#include <iostream>
#include <string>
#include <limits>
#include "./string_calculator.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main() {
    string quit;
    cout << "String Calculator" << endl;
    cout << "\"q\" or \"quit\" or ctrl+d to exit" << endl;

    
    
    while (quit!="q" && quit!="quit"){
    cout<<">> ";
    getline(cin,quit);
    string lhs;
    string rhs;
    int len=0;
    int len2=0;
    string ans="";
    if (quit.find("+") != string::npos){
           len=quit.find("+")-1;
           lhs=quit.substr(0,len);

           len2=quit.size() - quit.find("+");
           rhs=quit.substr(quit.find("+")+2,len2);

           ans=add(lhs, rhs);
           cout<<"ans = "<<endl;
           cout<<"\t"<<ans<<endl;

                   
    }
    else if (quit.find("*") != string::npos){
         len=quit.find("*")-1;
           lhs=quit.substr(0,len);

           len2=quit.size() - quit.find("*");
           rhs=quit.substr(quit.find("*")+2,len2);

           ans=multiply(lhs, rhs);
           cout<<"ans = "<<endl;
           cout<<"\t"<<ans<<endl;   
    }
    
} 
cout<<"farvel!"<<endl;
}

