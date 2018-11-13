# pragma once
#include <functional>
#include <memory>
#include <iterator>
#include <queue>
#include <initializer_list>

namespace STLContainer{

        // define the nested class bst_node
    struct bst_node{
          // type definition
          using node_pointer  = bst_node*;

          int _value;
          node_pointer  _parent;
          node_pointer  _left;
          node_pointer  _right;

          explicit bst_node(const int value = {}) : _value(value), _parent(nullptr), _left(nullptr), _right(nullptr){};
      };

    class bst_iterator:public std::iterator<
            std::bidirectional_iterator_tag, //iterator category
            int, //value type
            int, // difference_type
            const int*, // pointer;
            int  //reference
                >
    {
         friend class bst;

     private:
         using node_pointer  = typename bst_node::node_pointer;

     public:

         // Dereference
         const int& operator* () const {
             return _pointee->_value;
         }

         node_pointer  operator-> (){return _pointee;}

         bst_iterator& operator++ (){
             _pointee = _tree_next(_pointee);
             return *this;
         }

         bst_iterator operator++ (int){
             auto temp = bst_iterator(_pointee);
             ++(*this);
             return temp;
         }

         bst_iterator& operator-- (){
             _pointee = _tree_prev(_pointee);
             return *this;
         }

         bst_iterator operator-- (int){
             auto temp =  bst_iterator(_pointee);
             --(*this);
             return temp;
         }

         // return the smallest element in the bst
         // @brief Returns if the the two iterators lhs and rhs are not equal
         // @param lhs first iterator
         // @param rhs second iterator
         // @return true if lhs is not equal to rhs
         // @return false if lhs is equal to rhs
         friend bool operator!=( const bst_iterator& lhs, const bst_iterator& rhs ) {
             return lhs._pointee != rhs._pointee;
         }
         // @brief Returns if the the two iterators lhs and rhs are equal
         // @param lhs first iterator
         // @param rhs second iterator
         // @return true if lhs is equal to rhs
         // @return false if lhs is not equal to rhs
         friend bool operator==( const bst_iterator& lhs, const bst_iterator& rhs ) {
             return !( lhs != rhs );
         }
        private:
            node_pointer _pointee;
            explicit bst_iterator(const node_pointer pointee = nullptr): _pointee(pointee){};
            // @help functions for iterator behavior
            // @brief Helper function to find if node is the left child of the parent
            // @param _NodePtr input node
            // @return true if the node is left child of the parent
            // @return false if node is not the left child of the parent
            bool _tree_is_left_child(node_pointer _NodePtr) noexcept {
                return _NodePtr == _NodePtr->_parent->_left;
            }

            node_pointer _tree_min(node_pointer _NodePtr) noexcept{
                while (_NodePtr->_left!= nullptr) {
                    _NodePtr = _NodePtr->_left;
                }
                return _NodePtr;
            }
            // get the successor of the given node
            node_pointer _tree_next(node_pointer _NodePtr) noexcept {
                // Case 1: get the left most child of its right subtree,
                // find the minimum of its right subtree
                if (_NodePtr->_right!= nullptr)
                    return _tree_min(_NodePtr->_right);
                    // case 2, no right subtree, if the node is NOT left child of its parent
                    // back track, unitl NodePtr hits a (parent) node which is the left child of
                    // its parent
                while(!_tree_is_left_child(_NodePtr)) {
                    _NodePtr = _NodePtr->_parent;
                }
                    // case 3, no right subtree, if the node is left child of its parent
                    // return its parent
                    return _NodePtr->_parent;
                }

            node_pointer _tree_max(node_pointer _NodePtr) noexcept{
                while (_NodePtr->_right!= nullptr) {
                    _NodePtr = _NodePtr->_right;
                }
                return _NodePtr;
            }

            node_pointer _tree_prev(node_pointer _NodePtr) noexcept{
                if(_NodePtr->_left!= nullptr)
                    return _tree_max(_NodePtr);
                while(_tree_is_left_child(_NodePtr)) {
                    _NodePtr = _NodePtr->_parent;
                }
                return _NodePtr->_parent;
            }
        };
    class bst{

    public:
        // type definition
        using node_pointer      =   typename bst_node::node_pointer;
        using iterator          =   bst_iterator;
        using const_iterator    =   const iterator;

        //construct, deconstruct
        explicit bst() :_root{make_node(int{})}, _size(0),_end(_root){}
        // copy construct
        bst(const bst& other):_root(make_node(int{})), _size(0),_end(_root){
            bst_copy(other);
        }
        // move construct
        bst(bst&& other):_root(std::move(other._root)), _size(other._size),
                           _end(other._end){
            other._root = nullptr;
            other._size = 0;
            other._end = nullptr;
        }

        // initializer construct
        bst(std::initializer_list<int> init):_root(make_node(int{})),_size(0),_end(_root){
            for (auto &num:init){
                auto pair = insert(num);
            }
        }

        ~bst() = default;

        // capacity
        size_t size() const noexcept {return _size;}

        bool empty(){return !(_size);}

        // modifier:
        std::pair<iterator, bool> insert(int value){
            auto current_node  = _root;

            if (current_node == _end) {
                auto new_node = make_node(value);
                new_node->_right = std::move(_root);
                _root = std::move(new_node);
                ++_size;
                return std::make_pair<iterator,bool>(make_iterator(_root), true);
            }

            auto parent = current_node;// x will be pointing to the position where we insert the value
            while ((current_node!= nullptr)&&(current_node!=_end)) {
                    parent = current_node;
                    if (current_node->_value > value)
                        current_node = current_node->_left;
                    else if (current_node->_value < value)
                        current_node  = current_node->_right;
                    else
                        return std::make_pair<iterator, bool>(make_iterator(current_node), false);
                }

            auto new_node = make_node(value);

            // current_node is a left leaf
            if (parent->_value > value){
                new_node->_parent = parent;
                parent->_left = std::move(new_node);
                ++_size;
                return std::make_pair<iterator, bool>(make_iterator(parent->_left), true);
                }
            // current_node reaches to the _end
            if (current_node == _end) {
                new_node->_parent = parent;
                new_node->_right = std::move(parent->_right);
                parent->_right = std::move(new_node);
                // update the _end
                //_end = parent->_right->_right;
                ++_size;
                return std::make_pair<iterator, bool>(make_iterator(parent->_right), true);
            }
            // current node is a right leaf, but not reaches to _end;
            else {
                new_node->_parent = parent;
                parent->_right = std::move(new_node);
                ++_size;
                return std::make_pair<iterator, bool>(make_iterator(parent->_right), true);
            }
        }

        // find an element with key equivalent to key.
        iterator find(int key) const
        {
            if(!_root) return make_iterator(_root);
            else{
                auto node = _root;
                while(node!= _end){
                 if(node->_value > key)
                     node= node->_left;
                 else if(node->_value < key)
                     node= node->_right;
                 else if (node->_value == key)
                     return make_iterator(node);
                }
            return make_iterator(_end);
            }
        }

        iterator begin() noexcept{
            auto NodePtr = _tree_min(_root);// O(log(n))
            return make_iterator(NodePtr);
        }


        iterator end() noexcept{
//            auto NodePtr = _tree_max(_root);// O(log(n))
//            return make_iterator(NodePtr);
            return make_iterator(_end);
        }

        //Iterator following the last removed element.
        iterator erase(iterator pos){
            //auto pos_successor = ++pos;
            // case 1 pos is the leaf, just deleted, update its parent's left and right
            if ((pos->_left == nullptr)&&(pos->_right == nullptr)){
                if (*pos < (pos->_parent->_value))
                    pos->_parent->_left  = nullptr;
                else
                    pos->_parent->_right = nullptr;

                --_size;
                return  ++pos;
                }

            // case 2 pos has ONLY one child, we need to by pass iterator pos, and link its parent
            // and its children directly.
            if ((pos->_left!= nullptr)&&(pos->_right == nullptr)){
                if (_tree_is_left_child(pos->_left->_parent))
                   pos->_parent->_left = pos->_left;
                else
                    pos->_parent->_right = pos->_left;

                pos->_left->_parent = pos->_parent;
                --_size;
                return ++pos;
            }
            if ((pos->_left == nullptr)&&(pos->_right != nullptr)){
                if (_tree_is_left_child(pos->_right->_parent))
                    pos->_parent->_left = pos->_right;
                else
                    pos->_parent->_right = pos->_right;

                pos->_right->_parent = pos->_parent;
                --_size;
                return ++pos;
            }
            // case 3 pos has TWO children, we need to replace it with its successor
            // recursively call it
            else{
                auto pos_current = pos++;
                auto pos_succ = pos;
                pos_current->_value = pos_succ->_value; // just replace the value;
                auto temp = erase(pos);
                --_size;
                return pos_succ;
            }
        }

    private:
        node_pointer  _root;
        size_t _size;
        node_pointer _end;
        // @brief Helper function to find if node is the left child of the parent
        // @param x_ input node
        // @return true if the node is left child of the parent
        // @return false if node is not the left child of the parent

        bool _tree_is_left_child(node_pointer _NodePtr) const noexcept
        {
            return _NodePtr == _NodePtr->_parent->_left;
        }

        node_pointer _tree_min(node_pointer _NodePtr) const noexcept{
            while (_NodePtr->_left!= nullptr) {
                _NodePtr = _NodePtr->_left;
            }
            return _NodePtr;
        }

        // get the successor of the given node
        node_pointer _tree_next(node_pointer _NodePtr) const noexcept {
            // Case 1: get the left most child of its right subtree,
            // find the minimum of its right subtree
            if (_NodePtr->_right!= nullptr)
                return _tree_min(_NodePtr->_right);
            // case 2, no right subtree, if the node is NOT left child of its parent
            // back track, until NodePtr hits a (parent) node which is the left child of
            // its parent
            while(!_tree_is_left_child(_NodePtr)) {
                _NodePtr = _NodePtr->_parent;
            }
            // case 3, no right subtree, if the node is left child of its parent
            // return its parent
            return _NodePtr->_parent;
        }

        node_pointer _tree_max(node_pointer _NodePtr) const noexcept{
            while (_NodePtr->_right!= nullptr) {
                _NodePtr = _NodePtr->_right;
            }
            return _NodePtr;
        }

        node_pointer _tree_prev(node_pointer _NodePtr) const noexcept{
            if(_NodePtr->_left!= nullptr)
                return _tree_max(_NodePtr);
            while(_tree_is_left_child(_NodePtr)) {
                _NodePtr = _NodePtr->_parent;
            }
            return _NodePtr->_parent;
        }

        iterator make_iterator (node_pointer _NodePtr) const noexcept{
            return iterator(_NodePtr);// move construct;
        }

        void bst_copy(const bst& other){
            std::queue<node_pointer> fringe;
            fringe.emplace(other._root);
            while(!fringe.empty()){
                auto current = fringe.front();
                fringe.pop();
                auto pair = insert(current->_value);
                if(current->_left!= nullptr) fringe.emplace(current->_left);
                if(current->_right!= nullptr) fringe.emplace(current->_right);
            }
        }

        bst_node* make_node(int value) {
            return new bst_node(value);
        }
    };
}