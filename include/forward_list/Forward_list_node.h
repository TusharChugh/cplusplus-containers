# include<memory>
namespace STLContainer{

    template <typename T> class forward_list; // forward declare
    template<typename T> class forward_list_iterator; // forward declare

 template<typename T>
 class forward_list_node{
     friend class forward_list_iterator<T>;
     friend class forward_list<T>;
 public:
     using value_type           =    T;
     using reference            =    value_type&;
     using const_reference      =    const reference;
     using _forward_list_node   =    typename STLContainer::forward_list_node<T>;
     using _node_pointer        =    typename STLContainer::forward_list_node<T> *;

 private:
     value_type _value;
     _node_pointer _next;
     forward_list_node(const_reference value = value_type{},  _node_pointer next = nullptr): _value(value), _next(next){};
     ~forward_list_node() = default;
 };
}
