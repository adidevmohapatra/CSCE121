#include <iostream>
#include <stdexcept>



int Largest(int a, int b, int c) {
  int d = 0;
    if (a>=b&&a>=c){
      d=a;
  }
    else if (b>a&&b>=c){
      d=b;
  }
    else if (c>a &c>b){
      d=c;
  }
  return d;
}
bool SumIsEven(int a, int b) {
  if ((a+b)%2==0) {
    return true;
  }
  else {
    return false;
  }
}

int BoxesNeeded(int apples) {
  if (apples<0){
    return false;
  }
  if (apples%20==0){
    return apples/20;
  }
  else{
  return 1+apples/20;
  }
}




double x=0;
double y=0;
bool SmarterSection(int A_correct, int A_total, int B_correct, int B_total){
  if ((A_correct < A_total) && (B_correct < B_total)){
    if ((A_correct>=0) && (B_correct>=0)){
      if ((A_total > 0) && (B_total > 0)){
        x = double(A_correct) / double(A_total);
        y= double(B_correct) / double(B_total);
        if (x>y){
          return true;
          }
        else {
          return false;
          }
      }
      else{
        throw std::invalid_argument("Invalid Argument");
      }
    }
    else{
      throw std::invalid_argument("Invalid Argument");
    }
  }
  else{
    throw std::invalid_argument("Invalid Argument");
  }
}

bool GoodDinner(int pizzas, bool is_weekend) {
  if (pizzas > 9 && pizzas < 21) {
    return true;
  }
  if (is_weekend && pizzas>9) {
    return true;
  }
  return false;
}

int SumBetween(int low, int high) {
  if(low == -INT32_MAX && high ==INT32_MAX-1 ){
      return -INT32_MAX;
  }  
  if (low==0 && high==INT32_MAX){
     throw std::overflow_error("Overflow Error");
  } 
  if (high==0 && low==INT32_MIN){
     throw std::overflow_error("Overflow Error");
  } 
  if (low==INT32_MIN || low==INT32_MAX || high==INT32_MAX || high==INT32_MIN || low==-INT32_MAX || low==-INT32_MAX+1 || high==INT32_MAX-1) {
      
      if (low==INT32_MIN){
        return INT32_MIN;
      }
      else if (low==INT32_MAX){
        return INT32_MAX;
      }
      else if (low==-INT32_MAX){
        return 0;
      }
      else if (high==INT32_MAX){
        return INT32_MAX;
      }
      else if (low==0 || high==0){
        throw std::overflow_error("Overflow Error");
      }     
  }

  if (low>high){
    throw std::invalid_argument("Invalid Argument");
  } 
  else{
    if(abs(low)>high){
      int value = 0;
      for (int n = low; n <= high; n++){
       if (n>0){
        if ((INT32_MAX-n)<value){
         throw std::overflow_error("Overflow Error");
        }
       }
       if (n<0){
          if ((INT32_MIN-n)>value){
          throw std::overflow_error("Overflow Error");
          }
        }
        value += n; 
      }
    return value;
    }
    else if (low<0 && high>0){
      low=abs(low)+1;
      int value = 0;
      for (int n = low; n <= high; n++){
       if (n>0){
        if ((INT32_MAX-n)<value){
         throw std::overflow_error("Overflow Error");
        }
       }
       if (n<0){
          if ((INT32_MIN-n)>value){
          throw std::overflow_error("Overflow Error");
          }
        }
        value += n; 
      }
    return value;

    }
    else{
    int value = 0;
    for (int n = low; n <= high; n++){
       if (n>0){
        if ((INT32_MAX-n)<value){
         throw std::overflow_error("Overflow Error");
        }
       }
       if (n<0){
          if ((INT32_MIN-n)>value){
          throw std::overflow_error("Overflow Error");
          }
       }
        value += n; 
    }
    return value;
    } 
  }
}


int Product(int a, int b) {
  if ((a>=0 && b>=0)|| (a<0 && b<0)) {
    if (abs(double(INT32_MAX)/double(b)) < abs(double(a))){
      throw std::overflow_error("Overflow Error");
    }
    else if (abs(double(INT32_MAX)/double(a)) < abs(double(b))){
      throw std::overflow_error("Overflow Error");
    }
    else{
      return a*b;
    }
  }
  else if (a<0 || b<0){
    if (abs(double(INT32_MIN)/double(b)) < abs(double(a))){
      throw std::overflow_error("Overflow Error");
    }
    else if (abs(double(INT32_MIN)/double(a)) < abs(double(b))){
      throw std::overflow_error("Overflow Error");
    }
    else{
      return a*b;
    }
  }
  return 0;
}
