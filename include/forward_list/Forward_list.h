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