#include<iterator>
#include <assert.h>
#include "Forward_list_node.h"

namespace STLContainer{
    template<typename T>
    class forward_list_iterator : public std::iterator<
    std::forward_iterator_tag,
    T, // Value type
    T*,// Pointer
    T&> {// Reference
        // declare the friend to the forward_Qlist
        friend class forward_list<T>;

    public:
        using value_type            =    T;
        using reference             =    value_type&;
        using const_reference       =    const reference;
        using _forward_list_node    =   typename STLContainer::forward_list_node<T>;
        using _node_pointer         =   typename STLContainer::forward_list_node<T> *;
        using iterator              =   typename STLContainer::forward_list_iterator<T>;
        using const_iterator        =   const iterator;

        // dereference
        reference operator* () const{
            return _pointee->_value;
        }

         iterator& operator++(){
            _pointee =_pointee->_next;
            return * this;
        }

        iterator operator++(int){
            iterator retval(_pointee);
            ++ (*this);
            return retval;
        }

        // compare ==
        bool operator == (iterator other) const{
            return _pointee == other._pointee;
        }

        bool operator!= (iterator other) const {
            return _pointee != other._pointee;
        }
    private:
        _node_pointer _pointee;
        explicit forward_list_iterator(_node_pointer pointee):_pointee(pointee){};
    };
}