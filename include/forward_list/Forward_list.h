//#include "Forward_list_node.h"
#include "Forward_list_iterator.h"
#include <memory.h>
#include <iostream>

namespace STLContainer {

    template<typename T>
    class forward_list {
    private:
        using _forward_list_node        =   typename STLContainer::forward_list_node<T>;
        using _node_pointer             =   typename STLContainer::forward_list_node<T> *;
    public:
        using value_type                =    T;
        using reference                 =   value_type&;
        using const_reference           =   const reference;
        using iterator                  =   typename STLContainer::forward_list_iterator<T>;
        using const_iterator            =   const iterator;

        // construct/deconstruct
        explicit forward_list() : _head(make_node(value_type{}, nullptr)), _tail(_head){ };

        forward_list (forward_list&& other) noexcept
            :_head{std::move(other._head)}, _tail{std::move(other._tail)}{
            other._head = nullptr;
            other._tail = nullptr;
        }

//        forward_list (const forward_list& other):_head(make_node(value_type{}, nullptr)), _tail(_head){
//            auto node_other = other._head->_next;
//            auto last_node  = _head;
//            _head->_value = other._head->_value;
//
//            while (node_other!=other._tail){
//                auto new_node = make_node(node_other->_value, nullptr);
//                last_node->_next = new_node;
//                last_node->_next->_value = new_node->_value;
//                last_node = last_node->_next;
//                node_other= node_other->_next;
//            }
//            _tail = nullptr; // it is the tail now
//        }

        forward_list (const forward_list& other): _head(make_node(other._head->_value, nullptr)), _tail(_head){

            auto node_other = other._head->_next;
            auto last_node = _head;
            while(node_other!=other._tail){
                auto new_node = make_node(node_other->_value, nullptr);
                last_node->_next = new_node;
                last_node = new_node;
                node_other = node_other->_next;
            }
            _tail = make_node(value_type{}, nullptr);
            last_node->_next = _tail;
        }


        // define the customized container behavior
        ~forward_list() = default;

        //Element access
        reference front(){
            return _head->_value;
        }

        // capacity:
        bool empty() const noexcept{ return _head == _tail;}

        // modifiers:

        void clear() noexcept {
            while (_head!= _tail){
               // auto current_node = _head;
                _head = _head->_next;
                //delete current_node;
            }
            return;
        }

        void push_front(const_reference value){
            auto current_node = make_node(value, _head);
            _head = current_node;
        }

        void push_front(value_type&& value){
            auto current_node = make_node(value, _head);
            _head = current_node;
        }

        void pop_front(){
            if (_head == _tail)
                // throw an exception
                std::cout << "empty forward_list:" << std::endl;
            else {
                _node_pointer tmp = _head; // use the the tmp to store the current _head, later, the node which _head points to will
                _head = _head->_next; // advance the _head;
            }
        }

        iterator begin() noexcept{return iterator(_head);}

        const_iterator begin() const noexcept {return iterator(_head);}

        iterator end() noexcept{return iterator(_tail);}

        const_iterator end() const noexcept{return iterator(_tail);}

    private:
        _node_pointer _head;
        _node_pointer _tail;

        _node_pointer make_node(value_type value, _node_pointer node_pointer){
            return new forward_list_node<value_type>(value, node_pointer);
        }
    };
}