// TODO: Implement this source file
#include <iostream>
#include <fstream>
#include "MyString.h"
#include "Rover.h"

using namespace std;

MyString::MyString():mystring_size(0), mystring_capacity(1),mystring(nullptr){
    this->mystring_size=0;
    mystring_capacity=1;
    mystring= new char[mystring_capacity];
    mystring[0]='\0';
}

MyString::MyString(const MyString& str):mystring_size(str.mystring_size), mystring_capacity(str.mystring_capacity),mystring( new char[mystring_size]){
    for(size_t i=0;i<mystring_size;++i){
        mystring[i]=str.mystring[i];
    }

}

MyString::MyString(const char* s):mystring_size(0), mystring_capacity(1),mystring(nullptr){
    if(s==nullptr){
        this->mystring_size=0;
        mystring_capacity=1;
        mystring= new char[mystring_capacity];
        mystring[0]='\0';
    }
    else{
    mystring_size=0;
    while(s[mystring_size]!='\0'){
        mystring_size+=1;
    }
    mystring_capacity=mystring_size+1;
    mystring= new char[mystring_capacity];
    for(size_t i=0;i<mystring_size;++i){
        mystring[i]=s[i];
    }
    mystring[mystring_size]='\0';
    }
}

MyString::~MyString(){
    delete [] mystring;
   
}
////////////////////////////////////////////////////////////

void MyString::resize(size_t n){

}

size_t MyString::capacity()const noexcept{

    return mystring_capacity;
}

size_t MyString::size()const noexcept{
    
    return mystring_size;
}

size_t MyString::length()const noexcept{
    
    return mystring_size;
}

const char* MyString::data()const noexcept{
        
    return mystring;
}


bool MyString::empty()const noexcept{
        if(mystring_size==0){
            return true;
        }
        else{
            return false;
        } 
}

const char& MyString::front()const{
  
    return mystring[0];
}
const char& MyString::at(size_t pos)const{

    if (pos>=mystring_size){
        throw std::out_of_range("Out of Bounds");
    }
    return mystring[pos];
}

void MyString::clear()noexcept{
    mystring_size=0;
    mystring_capacity=1;
    mystring[0]='\0';
}

size_t MyString::find (const MyString& str, size_t pos )const noexcept{


    if(mystring_size-pos<str.mystring_size){
        return -1;
    }


    for(size_t i=pos;i<mystring_size;++i){
        bool finder=true;
        if(mystring[i]==str.mystring[0]){
           for(size_t j=0;j<str.mystring_size;++j){
               if(mystring[i+j]!=str.mystring[j]){
                finder=false;
                break;
               }
            }
            if(finder==true){
                   return i;
               } 

        }

    }
    return -1;
}



ostream& operator<<(ostream& os, const MyString& str){
    for(size_t i=0;i<str.mystring_size;++i){
        os<< str.data()[i];
    }
    return os;
}

MyString& MyString::operator=(const MyString& str){
    mystring_capacity=str.mystring_capacity;
    mystring_size=str.mystring_size;
    delete[]mystring;
    mystring= new char[mystring_capacity];
    for(size_t i=0;i<str.mystring_size;++i){
            mystring[i]=str.mystring[i];
    }
    mystring[mystring_size]='\0';
    return *this;

}

MyString& MyString::operator+=(const MyString& str){
    
    size_t mystring1_size= mystring_size+str.mystring_size;

    size_t mystring1_capacity= mystring_capacity+str.mystring_capacity - 1;
    
    char* mystring1= new char[mystring1_capacity];

    for (size_t i=0;i<mystring_size;++i){
        mystring1[i]=mystring[i];
    }
    size_t temp=0;
    for(size_t i=mystring_size;i<mystring1_size;++i){
        mystring1[i]=str.mystring[temp];
        ++temp;
    }
    mystring1[mystring1_size]='\0';

    delete []mystring;

    mystring=mystring1;

    mystring_size=mystring1_size;

    mystring_capacity=mystring1_capacity;

   return *this;
}

bool operator==(const MyString& lhs, const MyString& rhs){

    if(lhs.mystring_size!=rhs.mystring_size){
        return false;
    }
    for(size_t i=0;i<rhs.mystring_size;++i){
        if(rhs.mystring[i]!=lhs.mystring[i]){
            return false;
        }
    }
    return true;
}

MyString operator+(const MyString& lhs, const MyString& rhs){
    MyString tot_string = lhs;
    tot_string += rhs;
    return tot_string;