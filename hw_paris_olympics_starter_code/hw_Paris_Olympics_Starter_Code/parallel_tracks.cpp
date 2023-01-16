#include <iostream>
#include <iomanip>
#include <string>
#include "parallel_tracks.h"
#include "fstream"
#include "sstream"
#include "limits"
#include "cctype"
using std::string;
using std::stringstream;


//-------------------------------------------------------
// Name: get_runner_data
// PreCondition:  the prepped parallel arrays , and a legit filename is pass
// PostCondition: all arrays contain data from the text file given
//---------------------------------------------------------



void get_runner_data( const std::string& file, double timeArray[], std::string countryArray[], 
		unsigned int numberArray[], std::string lastnameArray[]) 
{
	std::ifstream infilename;
	infilename.open(file);
	if (!infilename.is_open()){
		throw std::invalid_argument("Cannot open file");
	}
    unsigned int i=0;
	string line="";
	double times=0.0;
	string countries="";
	unsigned int numbers=0;
	string lnames="";

	

	for (i=0;i<SIZE;++i){	
	  
	  getline(infilename,line);
	
		if (line.length()<=1){
			throw std::domain_error("File missing data");
		}
		
		stringstream ss(line);

		ss>>times;

		if (ss.fail() || times<0.0){
			throw std::domain_error("File contains invalid data (time)");
		}
		timeArray[i]=times;
	

		ss>>countries;

		if (countries.length()!=3){
			throw std::domain_error("File contains invalid data (country)");
		}
		else if (countries.length()==3){
			for (int i=0; i<3;++i){
            if (isupper(countries[i])==false){
				throw std::domain_error("File contains invalid data (country)");
			}
			else if (isalpha(countries[i])==false){
				throw std::domain_error("File contains invalid data (country)");
			}
		}
		}
		countryArray[i]=countries;
		
		
		ss>>numbers;

		if (ss.fail()|| numbers>=100){
			throw std::domain_error("File contains invalid data (number)");
		}
		numberArray[i]=numbers;
		
		ss>>lnames;
		

		if (ss.fail()||lnames.length()<2){
			throw std::domain_error("File contains invalid data (name)");
		}
		else {
			for (unsigned int i=0;i<lnames.length();++i){
				if (isalpha(lnames[i])==false && isspace(lnames[i])==false){
				throw std::domain_error("File contains invalid data (name)");
			}
			}
			
		}
		lastnameArray[i]=lnames;
	}	

}

//-------------------------------------------------------
// Name: prep_double_array
// PreCondition:  a double arrays is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_double_array(double ary[])
// making sure all values within the array are set to 0.0;

{
unsigned int i=0;
for(i=0;i<SIZE;++i){
	ary[i]=0.0;
}


}

//-------------------------------------------------------
// Name: prep_double_array
// PreCondition:  an unsigned int arrays is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_unsigned_int_array(unsigned int ary[])
// making sure all values within the array are set to 0;
{
unsigned int i=0;
for(i=0;i<SIZE;++i){
	ary[i]=0;
}

}

//-------------------------------------------------------
// Name: prep_string_array
// PreCondition:  a string arrays is pass in
// PostCondition: data in the array is "N/A" out to determine if
// a value has changed
//---------------------------------------------------------
void prep_string_array(std::string ary[])
// making sure all values within the array are set to "N/A";
{
unsigned int i=0;
for(i=0;i<SIZE;++i){
	ary[i]="N/A";
}

}
//-------------------------------------------------------
// Name: get_ranking
// PreCondition:  just the time array is passed in, and has valid data
// PostCondition: after a very inefficient nested loop to determine the placements 
// and places the ranks in a new array. That new array is returned
//---------------------------------------------------------
void get_ranking(const double timeArray[], unsigned int rankArray[])
{
	for (unsigned int i=0; i<SIZE; ++i){
		int rank=1;
		for (unsigned int j=0;j<SIZE; j++){
			if (timeArray[j]<timeArray[i]){
				rank++;
			}
			rankArray[i]=rank;
		}
	}
}


//-------------------------------------------------------
// Name: print_results
// PreCondition:  almost all parallel arrays are passed in and have valid data
// PostCondition: after a very inefficient nested loop to determine the ranks
// it then displays then along with a delta in time from the start
//---------------------------------------------------------
void print_results(const double timeArray[], const std::string countryArray[],
		const std::string lastnameArray[], const unsigned int rankArray[])
{

	std::cout << "Final results!!";
	std::cout << std::setprecision(2) << std::showpoint << std::fixed << std::endl;
	double best_time = 0.0;
		
	// print the results, based on rank, but measure the time difference_type
	for(unsigned int j = 1; j <= SIZE; j++)
	{
		
		// go thru each array, find who places in "i" spot
		for(unsigned int i = 0; i < SIZE; i++)
		{
			if(rankArray[i] == 1) // has to be a better way, but need the starting time
			{
				best_time = timeArray[i];
			}
			
			
			if(rankArray[i] == j) // then display this person's data
			{
				// this needs precision display
				std::cout << "[" << j << "]  " << timeArray[i] << " " << std::setw(15) << std::left << lastnameArray[i] << "\t" << "(" << countryArray[i] << ")  +" << (timeArray[i] - best_time) << std::endl; 
			}
			
		}
	}	
}

std::string trim(std::string ret) {
	// remove whitespace from the beginning
	while (!ret.empty() && isspace(ret.at(0))) {
			ret.erase(0, 1);
		}

	// remove whitespace from the end
	//  Note: last index is (.size() - 1) due to 0 based indexing
	while (!ret.empty() && isspace(ret.at(ret.size()-1))) {
		ret.erase(ret.size()-1, 1);
	}
	
	return ret;
}