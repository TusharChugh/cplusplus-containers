#pragma once
#include <iterator>
#include"Vector.h"

namespace STLContainer {

    template<class T> class Vector; // forward declaration

    template<typename Vector_c, typename _pointer, typename _reference>
    class Vector_iterator : public std::iterator<
            std::random_access_iterator_tag,
            typename Vector_c::value_type,
            typename Vector_c::value_type,
            _pointer,
            _reference> {
        // Type Definition, friend class
    public:
        using value_type        = typename Vector_c::value_type;
        using difference_type   = typename Vector_c::different_type;
        using reference         = typename Vector_c::reference;
        using const_reference   = typename Vector_c::const_reference;
        using pointer           = typename Vector_c::pointer;
        using const_pointer     = typename Vector_c::const_pointer;
        using iterator_category = std::random_access_iterator_tag;

        friend class Vector<value_type>;

    public:
        // constructor

        //Vector_iterator(){}
        explicit Vector_iterator(value_type* start_element = nullptr, size_t index = 0) : _start_element(start_element), _index(index){};

        ~Vector_iterator() = default;

        //explicit Vector_iterator(const Vector_iterator &other) : _start_element(other._start_element), _index(other._index){};???

        //explicit Vector_iterator(const Vector<value_type> *start_element = nullptr, size_t index = 0) : _start_element(start_element), _index(index){};

        // deference
        reference operator*() const { return _start_element[_index]; }

        pointer operator->() const { return &(_start_element[_index]); }

        // pre
        Vector_iterator& operator++() {
            ++_index;
            return *this;
        }

        Vector_iterator operator++(int) {
            Vector_iterator temp(*this);
            _index++;
            return temp;
        }

        Vector_iterator& operator--() {
            --_index;
            return *this;
        }

        Vector_iterator operator--(int) {
            Vector_iterator temp(*this);
            --_index;
            return temp;
        }

        // Comparison operators
        bool operator==(const Vector_iterator &rhs) const {
            return (_index == rhs._index) && (_start_element == rhs._start_element);
        }

        bool operator!=(const Vector_iterator &rhs) const {
            return (_index != rhs._index) || (_start_element != rhs._start_element);
        }

        size_t operator-(const Vector_iterator& other) {
            return _index - other._index;
        }

        Vector_iterator operator-(size_t increment) {
            return Vector_iterator(_start_element, _index - increment);
        }

        Vector_iterator operator+(size_t increment) {
            return Vector_iterator(_start_element, _index + increment);
        }

        bool operator<(const Vector_iterator& other) {
            return _index < other._index;
        }

    private:
        value_type* _start_element;
        size_t _index;
    };
}