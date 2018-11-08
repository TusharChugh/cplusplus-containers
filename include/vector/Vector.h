#pragma once
//
// Created by projectx on 10/4/18.
//
#include <iterator>
#include <iostream>
#include <initializer_list>
#include <stdexcept>
#include <list>
#include <memory>
/*
template<
        class T,
        class Allocator = std::allocator<T>
> class vector;
*/

//elem--------space------------------------>last
// reserve(); relocation
// capacity(): elem->last
// size() elem->space

// Class: Vector<ValueType>
namespace STLContainer {

    const int INITIAL_CAPACITY = 8;

    template<class T>
    class Vector {
    public:
        class Vector_iterator;  // forward declaration
        // let us have some types , type:
        using value_type        = T;
        using reference         = value_type&;
        using const_reference   = const value_type&;
        using iterator          = typename Vector<T>::Vector_iterator;
        using const_iterator    = const iterator;
// what we want to achieve?
// constructor, and deconstruct, copy constructor, move constructor
        //vector
        explicit Vector();
        explicit Vector(size_t count, const T &value); // assign value into the "count" elements

        Vector(std::initializer_list<T> init);
        Vector(const Vector<T> &other); // copy constructor
        Vector<T> &operator=(const Vector<T> &other); // copy assignment;
        Vector(Vector &&other); //move constructor
        Vector &operator=(Vector &&other);  // move assignment
        ~Vector();
// capacity:
        size_t size() const noexcept;

        size_t capacity() const noexcept;

        bool empty() const noexcept;
        // increase the capacity of the vector to a value that's greater or equal to new_cap.
        // if new_cap is greater than the current capacity(), new storage is allocated, otherwise
        // the method does nothing
        void reserve(size_t new_cap);  // why new (allocating resources in the free store, heap/dynamic memory) only happened
        // in the reserve function
// element access []
        reference operator[](size_t index);

        const_reference operator[](size_t index) const;
        //reference at(size_t index);
        //const_reference at(size_t index) const;
        reference front();

        const_reference front() const;

        reference back();

        const_reference back() const;

        // In addition to implementing the iterators themselves,
        // we have to implement the iterator-related functions in the container
        // iterators begin(), begin() for the constant, end(), and end() constant
        iterator begin() noexcept{
            return Vector_iterator(this, 0);
        }
        const Vector_iterator begin() const noexcept{
            return Vector_iterator(this, 0);
        }  // do not do it now

        Vector_iterator end() noexcept{
            return Vector_iterator(this, _count);
        }
        const Vector_iterator end() const noexcept{
            return Vector_iterator(this, _count);
        }

// modifiers:
        void clear() noexcept;
        void push_back(const T& x); // keep x unchanged
        void push_back(T&& x); // need release the resources allocated for x;
        void pop_back(); // pop up the last element

    private:
        value_type* _elements;
        size_t _count;
        size_t _capacity;

    // Iterator support
    public:
        class Vector_iterator{
        public:
            // constructor for iterator, fot tdd
            Vector_iterator();
            Vector_iterator(const Vector_iterator&);  //Vector_iterator(p), use the Vector_iterator to initialize this iterator
            Vector_iterator(const Vector<T>*, size_t index); //Vector_iterator(p, size_t index),  p---> move 'index' position;

            // iterator behavior, TDD, to think it thoroughly before writing the member functions
            // operator*()  *AI,  the element in the container which AI is pointing to, return type, should be reference;
            // operator->()  AI->  to get the members of this particular element which AI is pointing to
            // operator ++ ()  ++AI  iterator move to the position where it points to next element in the container.  first move, then return
            // operator ++(int) AI++ iterator move to the position where it points to next element in the container. first keep
            // value for return, then move. return the value before moving
            // compare
            // operator == (), compare if iterator, basically, the index == rhs. index?
            // operator != ()  similar to ==

            // Get the data element at this position
            T& operator* () const; // iterator *AI, the function itself won't modify the content the AI is pointing to
            T* operator->() const;     //AI-> some member of the container element where AI points to
            // Move position forward
            Vector_iterator& operator++ (); //pre-increment // allow modification   ++AI,  you need to use the reference
            Vector_iterator operator++ (int); // post increment allow modification  AI++,
            Vector_iterator& operator-- (); //pre-decrement // allow modification   ++AI,  you need to use the reference
            Vector_iterator operator-- (int); // post decrement allow modification
            // Comparison operators
            bool operator== (const Vector_iterator& rhs) const;   // AI== rhs?, the brace is used implicitily!, you forgot to add const.
                                                // you can not change the contact of rhs, and also the this
            bool operator!= (const Vector_iterator& rhs) const;   // AI!= rhs?

        private:
            const Vector<T>* _start_element;
            size_t _index;
        };
    };
//    implementation of the member functions for vector
//    template<class T>
//    vector<T>::vector(size_t count) : _elements{new T[count]}, _count{count}, _capacity{count} { };
//    template<class T>
//    Vector<T>::Vector(size_t count, const T &value) : _elements{new T[count]}, _count{count}, _capacity{count} {
//        for (auto index = 0; index < count; ++index) {
//            _elements[index] = value;
//        }
//    };
    template<class T>
    Vector<T>::Vector():_count(0),_capacity(0){
        _elements = new T[_capacity];
    }

    template<class T>
    Vector<T>::Vector(size_t count, const T &value):_count(0), _capacity(0) {
        reserve(count);
        for (auto index = 0; index< count; ++index)
            _elements[index] = value;
        _count = count;
    }

    template<class T>
    Vector<T>::Vector(std::initializer_list<T> init):_count(0),_capacity(0) {
        reserve(init.size());
        std::uninitialized_copy(init.begin(), init.end(),_elements);
        _count = init.size();
    }

//    template<class T>
//    void Vector<T>::clear() {
//        delete[]_elements;
//        _elements = nullptr;
//        _count = 0;
//        _capacity = 0;
//    }

    template<class T>
    void Vector<T>::clear() noexcept{
        delete[]_elements;
        _elements = nullptr;
        _count = 0;
    }


//Implementation: copy constructor and assignment operator
// copy constructor and copy assignment, keep object "other" in the memory
//    template<class T>
//    Vector<T>::Vector(const Vector<T> &other) : _elements{new T[other._count]}, _count{other._count},
//                                                _capacity{other._count} {
//        for (auto index = 0; index != other.size(); ++index) {
//            _elements[index] = other._elements[index];
//        }
//    }

    template<class T>
    Vector<T>::Vector(const Vector<T> &other):_count(0),_capacity{0} {
        reserve(other._capacity);
        for (auto index = 0; index != other.size(); ++index) {
            _elements[index] = other._elements[index];
            _count++;
        }
    }

    template<class T>
    Vector<T>& Vector<T>::operator=(const Vector<T> &other) {
        if (this == &other) return *this;
            //clear();
            //_count = other._count;
            //_capacity = other._capacity;
            //_elements = new T[other._capacity];
            reserve(other._capacity);
            for (auto index = 0; index != other.size(); ++index)
                _elements[index] = other._elements[index];
            _count = other._count;
        return *this;
    }

    template<class T>
// move constructor, release the resource assigned to other, make this->_elements to other-> _elements
// stealing everything from 'other', and then destroy 'other'
    Vector<T>::Vector(Vector<T> &&other) : _elements{other._elements}, _count{other._count}, _capacity{other._count} {
        // release of resource allocated for object 'other'
        delete[] other._elements;
        other._elements = nullptr;
        other._count = 0;
        other._capacity = 0;
    }

// different than the move construct, this object is already existed a = b, we need release the resource
// of 'a' at very beginning, and then let 'a' steal everything from 'b'
    template<class T>
    Vector<T> &Vector<T>::operator= (Vector<T> &&other) {
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
// destroy:
    template<class T>
    Vector<T>::~Vector() {
        delete[] _elements;
    }

    //In addition to implementing the iterators themselves, we have to implement the iterator-related functions in the container.
// iterators:
    /*
    template<class T>
    typename vector<T>::iterator vector<T>::begin() noexcept {
        return _elements;
    }

    template<class T>
    typename vector<T>::iterator vector<T>::end() noexcept {
        //return _elements + _count;
        return _elements + size();
    }

    template<class T>
    typename vector<T>::const_iterator vector<T>::begin() const noexcept {

        return _elements;
    }

    template<class T>
    typename vector<T>::const_iterator vector<T>::end() const noexcept {

        return _elements + size();
    }
     */

// capacity:
    template<class T>
    size_t Vector<T>::size() const noexcept {

        return _count;
    }

    template<class T>
    size_t Vector<T>::capacity() const noexcept {
        return _capacity;
    }

    template<class T>
    bool Vector<T>::empty() const noexcept {
        return size() == 0;
    }

    template<class T>
    void Vector<T>::reserve(size_t new_cap) {
//If new_cap is greater than the current capacity(),
// new storage is allocated, otherwise the method does nothing.
        if (new_cap <= capacity())
            return;
        T *new_elements = new T[new_cap];
            // copy all the elements from original place in memory to the new allocated area in memory
        if(size()) { // need consider the empty vector case, if size == 0, new_cap is 0, new_elements = nullptr
            for (auto index = 0; index != size(); ++index)
                new_elements[index] = _elements[index];
            delete[] _elements; // let _elements point to the new_elements
        }
        _capacity = new_cap; // update the capacity
        _elements = new_elements;
    }

//_elements access:
    template<class T>
    T &Vector<T>::operator[](size_t index) {
        // exception
        if (index < 0 || size() <= index)
            throw std::out_of_range {"Vector::operator[]"};
        return _elements[index];
    }

    template<class T>
    const T& Vector<T>::operator[](size_t index) const {
        // exception
        if (index < 0 || size() <= index)
            throw std::out_of_range {"Vector::operator[]"};
        return _elements[index];
    }

    template<class T>
    T& Vector<T>::front() {
        return *_elements;

    }

    template<class T>
    const T& Vector<T>::front() const {
        return *_elements;
    }

    template<class T>
    T& Vector<T>::back() {
        return *(_elements + size() - 1);
    }

    template<class T>
    const T& Vector<T>::back() const {
        return *(_elements + size() - 1);
    }

// modifiers:
    template<class T>
    void Vector<T>::push_back(const T &x) {
        // a new element coming in, first check size + 1 >capacity, if yes, need expand, call
        // reserve(), to allocate the new space new T [capacity*2]. then copy every element
        // in the original space to the new allocated area in memory.
        if (capacity() < size() + 1)
            reserve(size() == 0 ? 8 : 2 * size());
        _elements[_count++] = x;
    }

    template<class T>
    void Vector<T>::pop_back() {
        if (~empty())
            --_count;
        _elements[_count].~T();
    }

    template<class T>
    void Vector<T>::push_back(T &&x) {
        // a new element coming in, first check size + 1 >capacity, if yes, need expand, call
        // reserve(), to allocate the new space new T [capacity*2]. then copy every element
        // in the original space to the new allocated area in memory.
        if (capacity() < size() + 1)
            reserve(size() == 0 ? INITIAL_CAPACITY : 2 * size());
        _elements[_count++] = x;
//        delete x;
    }

//  Implementation for the iterator support for vector
    //const vector<T>* vp;
    //size_t index;
    template<class T>
    Vector<T>::Vector_iterator::Vector_iterator():_start_element(nullptr), _index(0){};

    template<class T>
    Vector<T>::Vector_iterator::Vector_iterator(const Vector_iterator& other): _start_element(other._start_element), _index(other._index){};//Vector_iterator(p);

    template<class T>
    Vector<T>::Vector_iterator::Vector_iterator(const Vector<T>* vector_elem, size_t index):_start_element(vector_elem), _index(index){}; //QiIterator(p, size_t index),  p--> move 'index' position

    template<class T>
    T& Vector<T>::Vector_iterator::operator*() const {
        return (_start_element->_elements[_index]);
    }

    template<class T>
    T* Vector<T>::Vector_iterator::operator->() const {
        return (_start_element->_elements[_index]);
    }
    // prefix
    template<class T>
    typename Vector<T>::Vector_iterator& Vector<T>::Vector_iterator::operator++() {
        _index++;
        return *this;
    }
    //postfix
    template<class T>
    typename Vector<T>::Vector_iterator Vector<T>::Vector_iterator::operator++(int){
        Vector_iterator  temp(*this); // construct a new iterator to keep the original iterator
        _index++;
        return temp;
    }

    template<class T>
    typename Vector<T>::Vector_iterator& Vector<T>::Vector_iterator::operator--() {
        _index--;
        return *this;
    }
    //postfix
    template<class T>
    typename Vector<T>::Vector_iterator Vector<T>::Vector_iterator::operator--(int){
        Vector_iterator  temp(*this); // construct a new iterator to keep the original iterator
        _index--;
        return temp;
    }

    // Compare
    template<class T>
    bool Vector<T>::Vector_iterator::operator== (const Vector_iterator &rhs) const {

        return (this->_index == rhs._index)&&(this->_start_element == rhs._start_element);
    }

    template<class T>
    bool Vector<T>::Vector_iterator::operator!= (const Vector_iterator &rhs) const {
        return (this->_index != rhs._index)||(this->_start_element != rhs._start_element);
    }
}