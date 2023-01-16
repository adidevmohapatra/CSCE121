#include <iostream>
#include "functions.h"

using std::cout;
using std::endl;

bool is_valid_range(int a, int b) {
	// TODO(student): validate input range
	if (((10<=a) && (a<10000) && (10<=b) && (b<10000)) && (a<=b)) {
		return true;
	}
	else {
		//cout<<" Invalid Input" << endl;
	return false;
	}
}

char classify_mv_range_type(int number) {
    // TODO(student): return 'M' if number has /\/\... pattern,
	// return 'V' if number has \/\/ pattern, and return 'N' otherwise
	//int dnumber is to find the individual numbers
	int d1=0;
	int d2=0;
	int d3=0;
	int d4=0;
	int d5=0;
	int d6=0;
	int d7=0;
	int d8=0;
	int d9=0;
	int d10=0;
	//find the remainder of the bigger numbers
	int remainder=0;
	int remainder_1=0;
	int remainder_2=0;
	int remainder_3=0;
	int remainder_4=0;
	int remainder_5=0;
	int remainder_6=0;
	int remainder_7=0;

  //2 digit number
	if ((10<=number) && (number<=99)){ 
	 	d1=number/10;
     	d2=number%10;
		 //see if the second digit is bigger than the first, continues like this for all the digits till 10 digits
		 if (d1<d2){
			 return 'M';
		 }
		 //see if th second digit is smaller than the first, continues like this for all the digits till 10 digits
		 else if (d1>d2)	{
			 return 'V';
		 } 
		 else {
			 return 'N';
		 }
		
	}
	//3 digit number
	else if ((100<=number) && (number<=999)){
		d1=number/100;
     	remainder=number%100;
		d2=remainder/10;
		d3=remainder%10;
		 if ((d1<d2) && (d2>d3)){
			 return 'M';
		 }
		 else if ((d1>d2) && (d2<d3)){
			 return 'V';
		 }
		 else {
			 return 'N';
		 }
	}
	//4 digit number
	else if ((1000<number) && (number<=9999)){
		d1=number/1000;
		remainder=number%1000;
		d2=remainder/100;
		remainder_1=remainder%100;
		d3=remainder_1/10;
		d4=remainder_1%10;
		 if ((d1<d2) && (d2>d3) && (d3<d4)){
			 return 'M';
		 }
		 else if ((d1>d2) && (d2<d3) && (d3>d4)){
			 return 'V';
		 }
		 else {
			 return 'N';
		 }
	}
	//5 digit number
	else if ((10000<number) && (number<=99999)){
		d1=number/10000;
		remainder=number%10000;
		d2=remainder/1000;
		remainder_1=remainder%1000;
		d3=remainder_1/100;
		remainder_2=remainder_1%100;
		d4=remainder_2/10;
		d5=remainder_2%10;
		 if ((d1<d2) && (d2>d3) && (d3<d4)&& (d4>d5)){
			 return 'M';
		 }
		 else if ((d1>d2) && (d2<d3) && (d3>d4) && (d4<d5)){
			 return 'V';
		 }
		 else {
			 return 'N';
		 }
	}
	//6 digit number
	else if ((100000<number) && (number<=999999)){
		d1=number/100000;
		remainder=number%100000;
		d2=remainder/10000;
		remainder_1=remainder%10000;
		d3=remainder_1/1000;
		remainder_2=remainder_1%1000;
		d4=remainder_2/100;
		remainder_3=remainder_2%100;
		d5=remainder_3/10;
		d6=remainder_3%10;
		 if ((d1<d2) && (d2>d3) && (d3<d4)&& (d4>d5)&&(d5<d6)){
			 return 'M';
		 }
		 else if ((d1>d2) && (d2<d3) && (d3>d4) && (d4<d5)&&(d5>d6)){
			 return 'V';
		 }
		 else {
			 return 'N';
		 }
	}
	//7 digit number
	else if ((1000000<number) && (number<=9999999)){
		d1=number/1000000;
		remainder=number%1000000;
		d2=remainder/100000;
		remainder_1=remainder%100000;
		d3=remainder_1/10000;
		remainder_2=remainder_1%10000;
		d4=remainder_2/1000;
		remainder_3=remainder_2%1000;
		d5=remainder_3/100;
		remainder_4=remainder_3%100;
		d6=remainder_4/10;
		d7=remainder_4%10;

		 if ((d1<d2) && (d2>d3) && (d3<d4)&& (d4>d5)&&(d5<d6)&&(d6>d7)){
			 return 'M';
		 }
		 else if ((d1>d2) && (d2<d3) && (d3>d4) && (d4<d5)&&(d5>d6)&&(d6<d7)){
			 return 'V';
		 }
		 else {
			 return 'N';
		 }
	}
	//8 digit number
	else if ((10000000<number) && (number<=99999999)){
		d1=number/10000000;
		remainder=number%10000000;
		d2=remainder/1000000;
		remainder_1=remainder%1000000;
		d3=remainder_1/100000;
		remainder_2=remainder_1%100000;
		d4=remainder_2/10000;
		remainder_3=remainder_2%10000;
		d5=remainder_3/1000;
		remainder_4=remainder_3%1000;
		d6=remainder_4/100;
		remainder_5=remainder_4%100;
		d7=remainder_5/10;
		d8=remainder_5%10;

		 if ((d1<d2) && (d2>d3) && (d3<d4)&& (d4>d5)&&(d5<d6)&&(d6>d7)&&(d7<d8)){
			 return 'M';
		 }
		 else if ((d1>d2) && (d2<d3) && (d3>d4) && (d4<d5)&&(d5>d6)&&(d6<d7)&&(d7>d8)){
			 return 'V';
		 }
		 else {
			 return 'N';
		 }
	}
	//9 digit number
	else if ((100000000<number) && (number<=999999999)){
		d1=number/100000000;
		remainder=number%100000000;
		d2=remainder/10000000;
		remainder_1=remainder%10000000;
		d3=remainder_1/1000000;
		remainder_2=remainder_1%1000000;
		d4=remainder_2/100000;
		remainder_3=remainder_2%100000;
		d5=remainder_3/10000;
		remainder_4=remainder_3%10000;
		d6=remainder_4/1000;
		remainder_5=remainder_4%1000;
		d7=remainder_5/100;
		remainder_6=remainder_5%100;
		d8=remainder_6/10;
		d9=remainder_6%10;

		 if ((d1<d2) && (d2>d3) && (d3<d4)&& (d4>d5)&&(d5<d6)&&(d6>d7)&&(d7<d8)&&(d8>d9)){
			 return 'M';
		 }
		 else if ((d1>d2) && (d2<d3) && (d3>d4) && (d4<d5)&&(d5>d6)&&(d6<d7)&&(d7>d8)&&(d8<d9)){
			 return 'V';
		 }
		 else {
			 return 'N';
		 }
	}
	//10 digit number
	else if (1000000000<number) {
		d1=number/1000000000;
		remainder=number%1000000000;
		d2=remainder/100000000;
		remainder_1=remainder%100000000;
		d3=remainder_1/10000000;
		remainder_2=remainder_1%10000000;
		d4=remainder_2/1000000;
		remainder_3=remainder_2%1000000;
		d5=remainder_3/100000;
		remainder_4=remainder_3%100000;
		d6=remainder_4/10000;
		remainder_5=remainder_4%10000;
		d7=remainder_5/1000;
		remainder_6=remainder_5%1000;
		d8=remainder_6/100;
		remainder_7=remainder_6%100;
		d9=remainder_7/10;
		d10=remainder_7%10;

		 if ((d1<d2) && (d2>d3) && (d3<d4)&& (d4>d5)&&(d5<d6)&&(d6>d7)&&(d7<d8)&&(d8>d9)&&(d9<d10)){
			 return 'M';
		 }
		 else if ((d1>d2) && (d2<d3) && (d3>d4) && (d4<d5)&&(d5>d6)&&(d6<d7)&&(d7>d8)&&(d8<d9)&&(d9>d10)){
			 return 'V';
		 }
		 else {
			 return 'N';
		 }
	}

	
	else{
	return 'N';
	}
}

void count_valid_mv_numbers(int a, int b) {
	// TODO(student): count the number of valid mountain ranges and valley
	// ranges in the range [a, b] and print out to console using the format
	// in Requirement 4 of the homework prompt

	int mountains=0;
	int valleys=0;

	for (int i = a; i <= b; ++i) {
		char classification = classify_mv_range_type(i);
		if (classification == 'M')
			mountains++;
		if (classification == 'V')
			valleys++;
	}
	cout << "There are " << mountains << " mountain ranges and " << valleys << " valley ranges between " << a << " and " << b << "."<<endl;
}