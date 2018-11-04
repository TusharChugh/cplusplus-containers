#pragma once

#include <deque>
#include <type_traits>

namespace STLContainer {
    template<typename T, typename Container = std::deque<T>> class Stack {
    public:
        using container_type  = Container;
        using value_type      = typename Container::value_type;
        using size_type       = typename Container::size_type;
        using reference       = typename Container::reference;
        using const_reference = typename Container::const_reference;

        // Constructors
        explicit Stack( const Container& cont ) : container( cont ) {}

        explicit Stack( Container&& cont = Container() ) : container( std::move( cont ) ) {}

        Stack( const Stack& other ) : container( other.container ) {}

        Stack( Stack&& other ) noexcept : container( std::move( other.container ) ) {}

        /**
         * Destructs the container adaptor.
         * The destructors of the elements are called and the used storage is deallocated.
         * Note, that if the elements are pointers, the pointed-to objects are not destroyed.
         */
        ~Stack() = default;

        inline reference top() {
            return container.back();
        }

        inline const_reference top() const {
            return container.back();
        }

        inline bool empty() const {
            return container.empty();
        }

        inline size_type size() const {
            return container.size();
        }

        inline void push( const value_type& value ) {
            container.push_back( value );
        }

        inline void push( value_type&& value ) {
            container.push_back( std::move( value ) );
        }

        inline void pop() {
            container.pop_back();
        }

        void swap( Stack& other ) noexcept {
            using std::swap;
            swap( container, other.container );
        }

    protected:
        Container container;
    };

    template<class T, class Container>
    bool operator==( const Stack<T, Container>& lhs, const Stack<T, Container>& rhs ) {
        return lhs.container == rhs.container;
    }

    template<class T, class Container>
    bool operator!=( const Stack<T, Container>& lhs, const Stack<T, Container>& rhs ) {
        return lhs.container != rhs.container;
    }

    template<class T, class Container>
    bool operator<( const Stack<T, Container>& lhs, const Stack<T, Container>& rhs ) {
        return lhs.container < rhs.container;
    }

    template<class T, class Container>
    bool operator<=( const Stack<T, Container>& lhs, const Stack<T, Container>& rhs ) {
        return lhs.container <= rhs.container;
    }

    template<class T, class Container>
    bool operator>( const Stack<T, Container>& lhs, const Stack<T, Container>& rhs ) {
        return lhs.container > rhs.container;
    }

    template<class T, class Container>
    bool operator>=( const Stack<T, Container>& lhs, const Stack<T, Container>& rhs ) {
        return lhs.container >= rhs.container;
    }

    template<class T, class Container>
    void swap( Stack<T, Container>& lhs, Stack<T, Container>& rhs ) noexcept {
        lhs.swap( rhs );
    }
} // namespace