// TODO: Implement this header file
#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>

using namespace std;

class MyString{
    private:
        size_t mystring_size;
        size_t mystring_capacity;
        char* mystring;
    public:
        MyString();	
        MyString(const MyString& str);
        MyString(const char* s);
        ~MyString();
        void resize (size_t n);
        size_t capacity() const noexcept;
        size_t size() const noexcept;
        size_t length() const noexcept;
        const char* data() const noexcept;
        bool empty() const noexcept;
        const char& front() const;
        const char& at (size_t pos) const;
        void clear() noexcept;
        size_t find (const MyString& str, size_t pos = 0) const noexcept;
        friend ostream& operator<< (ostream& os, const MyString& str);
        MyString& operator= (const MyString& str);
        MyString& operator+= (const MyString& str);
        friend bool operator== (const MyString& lhs, const MyString& rhs);
        friend MyString operator+ (const MyString& lhs, const MyString& rhs);

};

#endif 
