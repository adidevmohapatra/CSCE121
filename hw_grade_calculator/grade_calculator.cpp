// These headers define some of the classes and functions we need
#include <iostream>
#include <string>
#include <sstream>
#include <limits>

// ONLY MAKE CHANGES WHERE THERE IS A TODO

// These using declarations let us refer to things more simply
// e.g. instead of "std::cin" we can just write "cin"
using std::cin, std::cout, std::endl;
using std::string, std::getline;

// These methods are defined below the main function

// print instructions for inputting grades
void print_instructions();

// pretty print a summary of the grades
void print_results(double exam_average,
                   double hw_average,
                   double lw_average,
                   double engagement,
                   double weighted_total,
                   char final_letter_grade);

// YOU ARE NOT EXPECTED TO UNDERSTAND THIS ONE... YET
// extract the category and score from the line
// and store the values in the provided variables
// if line := "exam 95", then category := "exam" and score := 95
// if the line is invalid, then category := "ignore"
void get_category_and_score(const string& line,
                            string* category,
                            double* score);

int main() {
    print_instructions();

    // ONLY MAKE CHANGES WHERE THERE IS A TODO


    

    double exam_grade=0;
    double final_exam=0;
    double hw=0; 
    double engage=0;
    

    int labwork=0;
    int exam_count=0;
    int hw_count=0;
    int engage_count=0;
    int lw_count=0;
    int final_count=0;

    string line;
    // read one line from standard input (discards the ending newline character)
    getline(cin, line);
    // read lines until an empty line is read
    while (!line.empty()) {
        string category;
        double score;
        get_category_and_score(line, &category, &score);

        // process the grade entry
        if (category == "exam") {
          exam_grade+= score;
          exam_count++;
        } else if (category == "final-exam") {
           final_exam+=score;
           final_count++;

        } else if (category == "hw") {
           hw+=score;
           hw_count++;
        } else if (category == "lw") {
            if (labwork>=1){
                labwork=1;    
            }
            else if (labwork==0){
                labwork=0;
            }
            labwork+=score;
            lw_count++;  
        } else if (category == "engagement") {
           engage+=score;
           engage_count++; 
           
        } else {
            cout << "ignored invalid input" << endl;
        }
                

        // get the next line from standard input
        getline(cin, line);
    }

    
    double exam_average = 0;
    double hw_average = 0;
    double lw_average = 0;
    double engagement = 0;

    if (hw_count==0){
               hw_average=0;
           }
    else {
        hw_average=hw/(double)hw_count;
    }
    if (lw_count==0){
               labwork=0;
    }
    else {
        lw_average=(labwork/(double)lw_count)*100;
    }
    if (engage_count==0){
               engage=0;
    }
    else {
        engagement=engage;
        if (engagement>=100){
            engagement=100;
        }
    }

           
    

    exam_average=exam_grade;
    final_exam=final_exam;
    
                

    if (((exam_average+final_exam)/3)>final_exam){
        exam_average=(((exam_average+final_exam)/3));
}
    else {
        exam_average=final_exam;
    }
    
            
            

   
    double weighted_total = 0;

    weighted_total=((hw_average*.4)+(engagement*.1)+(lw_average*.1)+(exam_average*.4));

    // TODO(student): compute final letter grade
     char final_letter_grade = 'X';

    if (90<=weighted_total){
      final_letter_grade= 'A';
    }
    else if(80<=weighted_total){
      final_letter_grade= 'B';
    }
    else if(70<=weighted_total){
      final_letter_grade= 'C';
    }
    else if(60<=weighted_total){
      final_letter_grade= 'D';
    }
    else{
      final_letter_grade= 'F';
    }

    

    print_results(
        exam_average, hw_average, lw_average, engagement,
        weighted_total, final_letter_grade);
}

// These methods are already implemented for you
// You should not need to modify them

void print_instructions() {
    cout << "enter grades as <category> <score>" << endl;
    cout << "  <category> := exam | final-exam | hw | lw | engagement" << endl;
    cout << "     <score> := numeric value" << endl;
    cout << "enter an empty line to end input" << endl;
}

void get_category_and_score(
    const string& line,
    string* category,
    double* score) {
    // turn the string into an input stream
    std::istringstream sin(line);

    // read the category (as string) and score (as double) from the stream
    sin >> *category;
    sin >> *score;

    if (sin.fail()) {
        // the stream is in a fail state (something went wrong)
        // clear the flags
        sin.clear();
        // clear the stream buffer (throw away whatever garbage is in there)
        sin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // signal that the line was invalid
        *category = "ignore";
    }
}

void print_results(
    double exam_average,
    double hw_average,
    double lw_average,
    double engagement,
    double weighted_total,
    char final_letter_grade) {
    cout << "summary:" << endl;
    cout << "      exam average: " << exam_average << endl;
    cout << "        hw average: " << hw_average << endl;
    cout << "        lw average: " << lw_average << endl;
    cout << "        engagement: " << engagement << endl;
    cout << "    ---------------" << endl;

    cout << "    weighted total: " << weighted_total << endl;

    cout << "final letter grade: " << final_letter_grade << endl;
}