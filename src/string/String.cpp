#include <string/String.h>
#include <utility>

//Constructors
Container::String::String() {
    reset();
}

Container::String::String(const char *str) {
    copy_str(str);
}

Container::String::String(String && str) noexcept {
    reset();
    _str = str._str;
    _str_len = str._str_len;
    str._str = nullptr;
    str._str_len = 0;
    str.reset();
}

Container::String::String(const String & str) {
    copy_str(str._str);
}

Container::String::~String() {
    reset();
}

//Data management
const char* Container::String::copy_str(const char * str) {
    if(str) {
        size_t length = strnlen(str, Container::String::MAX_LENGTH);
        alloc_str(length);
        strncpy(_str, str, length);
        _str_len = length;
    }
    return _str;
}

const char* Container::String::alloc_str(size_t size) {
    if(_str) reset();
    _str_len = (size > Container::String::MAX_LENGTH) ? Container::String::MAX_LENGTH :size;
    _str = new char[_str_len + 1]();
    return _str;
}

void Container::String::reset() {
    if(_str) delete [] _str;
    _str = nullptr;
    _str_len = 0;
}

const char * Container::String::c_str() const noexcept {
    return _str;
}

void Container::swap(String & str1, String & str2) noexcept {
    //enabling ADL with swap is not useful for our case as cstring and int don't have their own swap methods)
    using std::swap;
    swap(str1._str, str2._str);
    swap(str1._str_len, str2._str_len);
}

//Operators
Container::String & Container::String::operator=(String str) {
    swap(*this, str);
    return *this;
}

Container::String & Container::String::operator+=(const char * rhs) {
    if(rhs) {
        size_t rhs_len = strnlen(rhs, Container::String::MAX_LENGTH);
        size_t combined_length = _str_len + rhs_len;
        combined_length = combined_length < MAX_LENGTH ? combined_length : MAX_LENGTH;
        String first(*this);
        alloc_str(combined_length);
        strncpy(_str, first._str, first._str_len);
        strncpy(_str + first._str_len, rhs, rhs_len);
    }
    return *this;
}

Container::String & Container::String::operator+=(const String &rhs) {
    operator+=(rhs._str);
    return *this;
}

char& Container::String::operator[](size_t index) {
    if(index < 0 || index >= (int)_str_len) return _str[_str_len];
    return _str[index];
}

const char& Container::String::operator[](size_t index) const {
    if(index < 0 || index >= (int)_str_len) return _str[_str_len];
    return _str[index];
}

std::ostream& operator<<(std::ostream& os, const Container::String str) {
    os<<str.c_str();
    return os;
}

//Utilities

const char& Container::String::front() const {
    return _str[0];
}

const char& Container::String::back() const {
    return _str[_str_len - 1];
}
