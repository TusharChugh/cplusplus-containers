#pragma once

#include <cstring>
#include <cstddef>
#include <ostream>
#include <iterator>


const static char * STRING_VERSION = "0.0.1";

namespace STLContainer {
    class String;

    void swap(String & str1, String & str2) noexcept;

    class String {

    public:
        static const int MAX_LENGTH = 65535;
        /*******************constructors*******************/

        /**
         * Default constructor
         * Constructs an empty string with a length of zero characters
         */
        String();

        /**
         * Constructor to take input as c-string
         * @param str copies the null-terminated character sequence (c-string) pointer by str
         */
        String(const char* str);

        /**
         * Copy constructor
         * @param str constructs a copy of str
         */
        String(const String& str);

        /**
         * Move constructors
         * @param str constructs a new string and moves the contents of str to it
         */
        String(String&& str) noexcept;

        /**
         * Destructor
         */
        ~String();

        /*******************data management*******************/
        /**
         * Allocate the memory for a string given the input size
         * @param size size of the memory to be allocated
         * @return character pointer to the allocated memory
         */
        const char* alloc_str(size_t size);

        /**
         * reset the string to an empty string with a length of zero characters
         */
        void reset();

        /**
         * Copies the null-terminated character sequence pointed by str
         * @param input null terminated str
         * @return string with copied data
         */
        const char* copy_str(const char * str);

        /**
         * returns a null-terminated character sequence (c-string) type
         * @return c-string
         */
        const char* c_str() const noexcept;

        /**
         * Function to swap two String objects
         * @param str1 String1
         * @param str2 String2
         */
        friend void swap(String& str1, String& str2) noexcept;

        /******************operators******************/

        /**
         * Copy and assignment
         * @param str String to be copied
         * @return reference to the assigned String
         */
        String& operator = (String str);

        /**
         * Concatenates provided String
         * @param str String to be concatenated
         * @return concatenated String
         */
        String& operator += (const String& str);

        /**
         * Concatenates provided cstring
         * @param str cstring to be concatenated
         * @return concanated String
         */
        String& operator += (const char* str);

        char& operator [](size_t index);

        /**
         * returns the value at the index
         * @return value at the index
         */
        const char& operator [] (size_t index) const;

        /******************utilities******************/

        /**
         * returns the length of the string
         * @return number of characters in the string
         */
        inline size_t length() const { return _str_len;  }

        /**
         * returns the size (=length) of the string
         * @return number of characters in the string
         */
        inline size_t size() const { return _str_len; }

        /**
         * empty string or not
         * @return true if string length is zero else false
         */
        inline bool empty() const { return !(_str_len); };

        /**
         * returns the first character of the String
         * @return the character at the 0 index
         */
        const char& front() const;

        /**
         * returns the character at the back of the String
         * @return last character of the String
         */
        const char& back() const;

    private:
        char * _str = nullptr;
        size_t _str_len = 0;
    };

    /******************non-member functions******************/

    /******************comparison operators******************/

    //Comparison operators
    inline bool operator==(const STLContainer::String& lhs, const STLContainer::String& rhs) {
        if(strncmp(lhs.c_str(), rhs.c_str(), STLContainer::String::MAX_LENGTH) == 0) return true;
        return false;
    }

    inline bool operator!=(const STLContainer::String& lhs, const STLContainer::String& rhs) {
        return !operator==(lhs, rhs);
    }

    inline bool operator< (const STLContainer::String& lhs, const STLContainer::String& rhs) {
        if(strncmp(lhs.c_str(), rhs.c_str(), STLContainer::String::MAX_LENGTH) < 0) return true;
        return false;
    }

    inline bool operator> (const STLContainer::String& lhs, const STLContainer::String& rhs) {
        return operator<(rhs, lhs);
    }

    inline bool operator<=(const STLContainer::String& lhs, const STLContainer::String& rhs) {
        return !operator>(lhs, rhs);
    }

    inline bool operator>=(const STLContainer::String& lhs, const STLContainer::String& rhs) {
        return !operator<(lhs, rhs);
    }

    inline String operator+(String lhs, const String& rhs) {
        lhs += rhs;
        return lhs;
    }

    std::ostream& operator<<(std::ostream& os, const String str);
}