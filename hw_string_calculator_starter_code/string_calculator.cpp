#include <iostream>
#include <string>
#include <iostream>
#include <string>
#include "./string_calculator.h"

using std::cout;
using std::endl;
using std::string;

unsigned int digit_to_decimal(char digit) {
    int number;
    number = (int) digit-48;
    if (number>=0 && number<=9){
        return number;
     }
    else {
        throw std::invalid_argument("Invalid Digit");
     }
    return 0;
    // TODO(student): implement
}

char decimal_to_digit(unsigned int decimal) {
    char number1;
    number1 = (char)decimal+48;
    if (number1>=48 && number1<=57){
        return number1;
     }
    else{
        throw std::invalid_argument("Invalid Digit");
     }
    return '0';
    // TODO(student): implement
}

string trim_leading_zeros(string num) {
    int i=0;
    bool is_negative=false;
    if (num[0]=='-'){
        is_negative=true;
        num=num.substr(1);

    }
    while (num[i]=='0'){
        if (num[i]!='0'){
            break;
        }
        i++;
    }
    string ans=num.substr(i);
    if (ans=="" || ans=="-"){
        return "0";
    }

    if (is_negative==true){
        return "-"+ans;
    }
    
    return ans;

    // TODO(student): implement
}


string add(string lhs, string rhs) {
    int max_length= 0;
    int int1=0;
    int int2=0;
    int final_int;
    int carry=0;
    char final_char=' ';
    string ans="";
    bool is_negative=false;
    
    if (rhs[0]=='-' || lhs[0]=='-'){
        is_negative=true;
        rhs=rhs.substr(1);
        lhs=lhs.substr(1);

    }


    if (lhs.length()>rhs.length()){
        max_length=lhs.length();
        while(lhs.length()!=rhs.length()){
          rhs="0"+rhs;
         
        }
    }
    else {
        max_length=rhs.length();
        while(lhs.length()!=rhs.length()){
          lhs="0"+lhs;
        }
    }

    lhs="0"+lhs;
    rhs="0"+rhs;
    max_length++;
    for (int i=max_length-1;i>=0;--i){
        int1=digit_to_decimal(lhs.at(i));
        int2=digit_to_decimal(rhs.at(i));
        final_int=int1+int2+carry;

        
        if (final_int>9){
            carry=final_int/10;
            final_int=final_int%10;
            final_char=decimal_to_digit(final_int);
            
            ans += final_char;

        }

        else{
            final_char=decimal_to_digit(final_int);
            ans = ans + final_char;
            carry=0;
        }
 
    }
    string reverse="";
    for (int i=ans.size()-1;i>=0;--i){
        reverse+=ans[i];
    }
    ans=reverse;
    ans=trim_leading_zeros(ans);
    if(is_negative){
        return "-"  + ans;
    } else {
        return ans;
    }
    // TODO(student): implement
}




string helper(string a, char b){
    string ans="0";
    
    b=digit_to_decimal(b);

    for (int i=b ; i>0 ; --i){
        ans= add(a,ans);
        
    }
    return ans;

}

string multiply(string lhs, string rhs) {
   string current_ans="0";
   string zeros="";
   int count=0;

    
    if (rhs[0]=='-' && lhs[0]=='-'){
        rhs=rhs.substr(1);
        lhs=lhs.substr(1);
        count=1;
    }
    else if (lhs[0]=='-'){
        lhs=lhs.substr(1);
        count=2;
    }
    else if (rhs[0]=='-'){
        rhs=rhs.substr(1);
        count=2;
    }

   string a=lhs;
   for (int i=rhs.size()-1;i>=0;--i){
        char b=rhs.at(i);
        string num=helper(a,b) + zeros;
        current_ans = add(current_ans, num);
        zeros += "0";
   }
   if (count==1){
       return current_ans;
   }
   else if (count==2){
       current_ans= "-"+current_ans;
       return current_ans; 
   }
   else{
       return current_ans;
   }
 
}
