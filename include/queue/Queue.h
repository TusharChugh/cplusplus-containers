#pragma once

#include <deque>
namespace STLContainer{
    template <class T, class Container = std::deque<T>> class queue{

    public:
        // type definition
        using  container_type   = Container;
        using  value_type       = typename Container::value_type;
        using  size_type        = typename Container::size_type;
        using  reference        = typename Container::reference;
        using  const_reference  = typename Container::const_reference;

        //
    private:
        Container _container;

    public:
        queue(): queue(Container()){};

        explicit queue(const Container& container): _container(container){}

        explicit queue(Container&& container): _container(std::move(container)){};

        queue(const queue& other):_container(other._container){};

        queue(queue&& other):_container(std::move(other._container)){};

        queue& operator = (const queue& other){
            _container = other._container;
            return *this;
        }

        ~queue()  = default;

        // modifier
        void push(const value_type& value){
            _container.push_back(value);
        }
        // capacity
        bool empty() const{
            return _container.empty();
        }

        size_type size() const {
            return _container.size();
        }

        void pop() {
            _container.pop_front();
        }
        // swap the two queues
        void swap(queue& other) noexcept{
            std::swap(_container, other._container);
        }

        void emplace(value_type&& value){
            _container.emplace_back(value);
        }
        reference front() {
            return  _container.front();
        }

        const_reference front() const{
            return _container.front();
        }

        reference back(){
            return _container.back();
        }

        const_reference back() const{
            return _container.back();
        }
    };
}