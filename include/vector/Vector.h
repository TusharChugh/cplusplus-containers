#pragma once

#include <iterator>
#include <iostream>
#include <initializer_list>
#include <stdexcept>
#include <list>
#include <memory>
#include "Vector_iterator.h"

namespace STLContainer {

    // forward declare
    template<typename Vector_c, typename _pointer, typename _reference> class Vector_iterator;

    template<class T>
    class Vector {
        const int INITIAL_CAPACITY = 8;
    public:

        // Type Definitions
        using value_type        = T;
        using reference         = value_type&;
        using const_reference   = const value_type&;
        using pointer           = value_type *;
        using const_pointer     = const value_type *;
        using different_type    = value_type;
        using iterator          = STLContainer::Vector_iterator<Vector<T>, pointer, reference>;
        using const_iterator    = STLContainer::Vector_iterator<Vector<T>, const_pointer, const_reference>;

        // Giving access to private members to Vector_list<T>
        friend class Vector_iterator<Vector<T>, typename Vector<T>::pointer, typename Vector<T>::reference>;
        friend class Vector_iterator<Vector<T>, typename Vector<T>::const_pointer, typename Vector<T>::const_reference>;

        // constructor, and deconstruct, copy constructor, move constructor
        explicit Vector(size_t count = 0, const T &value = value_type{}):_count(0),_capacity(0){
            reserve(count + 1); // for the psst last element
            for (auto index = 0; index < count; ++index)
                _elements[index] = value;
            _count = count;
        }

        Vector(std::initializer_list<T> init):_count(0),_capacity(0){
            reserve(init.size()+1);
            std::uninitialized_copy(init.begin(), init.end(), _elements);
            _count = init.size();
        };
        // copy constructor
        Vector(const Vector<T> &other):_count(0),_capacity(0){
            reserve(other._capacity);
            for (auto index = 0; index != other.size(); ++index) {
                _elements[index] = other._elements[index];
                ++_count;
            }
        }
        // copy assignment
        Vector<T> &operator=(const Vector<T> &other){
            if (this == &other) return *this;
            reserve(other._capacity);
            for (auto index = 0; index != other.size(); ++index)
                _elements[index] = other._elements[index];
            _count = other._count;
            return *this;
        }

        //move constructor
        Vector(Vector<T> &&other) : _elements{other._elements}, _count{other._count}, _capacity{other._count} {
            // release of resource allocated for object 'other'
            delete[] other._elements;
            other._elements = nullptr;
            other._count = 0;
            other._capacity = 0;
        }

        // move assignment
        Vector &operator=(Vector &&other){
            if (this != &other) {
                delete[]_elements;
                _elements = other._elements;
                _count = other._count;
                _capacity = other._capacity;
                // then destroy 'other'
                other._elements = nullptr;
                other._count = 0;
                other._capacity = 0;
                return *this;
            }
        }

        ~Vector(){delete[] _elements;};

        // capacity:
        size_t size() const noexcept{return _count;}

        size_t capacity() const noexcept{return _capacity;}

        bool empty() const noexcept{return size() == 0;}

        // increase the capacity of the vector to a value that's greater or equal to new_cap.
        // if new_cap is greater than the current capacity(), new storage is allocated, otherwise
        // the method does nothing
        void reserve(size_t new_cap) {
            // If new_cap is greater than the current capacity(),
            // new storage is allocated, otherwise the method does nothing.
            if (new_cap <= capacity())
                return;
            T *new_elements = new T[new_cap];
            // copy all the elements from original place in memory to the new allocated area in memory
            if (size()) { // need consider the empty vector case, if size == 0, new_cap is 0, new_elements = nullptr
                for (auto index = 0; index != size(); ++index)
                    new_elements[index] = _elements[index];
                delete[] _elements; // let _elements point to the new_elements
            }
            _capacity = new_cap-1; // update the capacity, exclude the past last element /end
            _elements = new_elements;
        }

        // element access []
        reference operator[](size_t index) {
            // exception
            if (index < 0 || size() <= index)
                throw std::out_of_range {"Vector::operator[]"};
            return _elements[index];
        }

        const_reference operator[](size_t index) const{
            // exception
            if (index < 0 || size() <= index)
                throw std::out_of_range {"Vector::operator[]"};
            return _elements[index];
        }

        reference front(){
            return *_elements;
        }

        const_reference front() const{
            return *_elements;
        }

        reference back(){
            return *(_elements + size() - 1);
        }

        const_reference back() const{
            return *(_elements + size() - 1);
        }

        // Iterators
        iterator make_iterator(value_type* start_element, size_t index) noexcept {
            return iterator(start_element, index);
        }

        const_iterator  make_iterator(const value_type* start_element, const size_t index) const noexcept{
            return  const_iterator(start_element, index);
        }

        iterator begin() noexcept {
            return make_iterator(_elements, 0);
        }

        const_iterator begin() const noexcept {
            return make_iterator(_elements, 0);
        }

        iterator end() noexcept {
            return make_iterator(_elements, _count);
        }

        const_iterator end() const noexcept {
            return make_iterator(_elements, _count);
        }
        // modifiers
        void clear() noexcept{
            delete[]_elements;
            _elements = nullptr;
            _count = 0;
        }

        void push_back(const T &x){
            // a new element coming in, first check size + 1 >capacity, if yes, need expand, call
            // reserve(), to allocate the new space new T [capacity*2]. then copy every element
            // in the original space to the new allocated area in memory.
            if (capacity() < size() + 1)
                reserve(size() == 0 ? 8 : 2 * size());
            _elements[_count++] = x;
        } // keep x unchanged

        void push_back(T &&x){
            // a new element coming in, first check size + 1 >capacity, if yes, need expand, call
            // reserve(), to allocate the new space new T [capacity*2]. then copy every element
            // in the original space to the new allocated area in memory.
            if (capacity() < size() + 1)
                reserve(size() == 0 ? INITIAL_CAPACITY : 2 * size());
            _elements[_count++] = x;
        } // need release the resources allocated for x;

        void pop_back(){
            if (~empty())
                --_count;
            _elements[_count].~T();
        } // pop up the last element

    private:
        value_type* _elements;
        size_t _count;
        size_t _capacity;
    };
}