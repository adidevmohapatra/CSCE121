#include <iostream>
#include <string>
#include <sstream>
#include "LinkedList.h"
#include "Node.h"
#include <cmath>

using std::cout;
using std::string;
using std::ostream;

LinkedList::LinkedList() {
	  // Implement this function
      head=nullptr;
      tail=nullptr;
}

LinkedList::~LinkedList() {
	  // Implement this function
      this->clear();
}

LinkedList::LinkedList(const LinkedList& source) {
     
     head=nullptr;
     tail=nullptr;

     if (source.head==nullptr){
         head=nullptr;
         return;
    }
    this->head = new Node(source.head->data.id,source.head->data.fov,source.head->data.volume,source.head->data.center_x,source.head->data.center_y,source.head->data.min_x,source.head->data.max_x,source.head->data.min_y,source.head->data.max_y);
    Node *current=head;
    Node *newsource=source.head->next;

    while(newsource!=nullptr){
        Node *newsource1= new Node(newsource->data.id,newsource->data.fov,newsource->data.volume,newsource->data.center_x,newsource->data.center_y,newsource->data.min_x,newsource->data.max_x,newsource->data.min_y,newsource->data.max_y);
        current->next=newsource1;
        current=newsource1;
        newsource=newsource->next;

    }
    tail=current;

 

    // Implement this function

}

LinkedList& LinkedList::operator=(const LinkedList& source) 
{
    this->clear();

    this->head = new Node(source.head->data.id,source.head->data.fov,source.head->data.volume,source.head->data.center_x,source.head->data.center_y,source.head->data.min_x,source.head->data.max_x,source.head->data.min_y,source.head->data.max_y);
    Node *current=head;
    Node *newsource=source.head->next;

    while(newsource!=nullptr){
        Node *newsource1= new Node(newsource->data.id,newsource->data.fov,newsource->data.volume,newsource->data.center_x,newsource->data.center_y,newsource->data.min_x,newsource->data.max_x,newsource->data.min_y,newsource->data.max_y);
        current->next=newsource1;
        current=newsource1;
        newsource=newsource->next;

    }
    tail=current;

 


    return *this;
    // Implement this function
}

void LinkedList::insert(std::string id, int fov, double volume, double center_x, double center_y, double min_x, double max_x, double min_y, double max_y)
{
    Node* newnode= new Node(id,fov,volume,center_x,center_y,min_x,min_y,max_x,max_y);
    Node* current=head;
    Node* previous=nullptr;

    if (head==nullptr){
        head=newnode;
        tail=newnode;
    }
    else if(newnode->data < current->data){
        newnode->next = current;
        head = newnode;
    }
    else {
        previous=current;
        current=current->next;
        bool check = false;
        while(current!=nullptr){
            if (check){
                break;
            }
          if((newnode->data < current->data) && (previous->data < newnode->data)){
            newnode->next=current;
            previous->next=newnode;
            check = true;
          }  
            previous=current;
            current=current->next;
        }
        if (!check){
            previous->next=newnode;
            tail=newnode;
        }
    }

    // Implement this function


}

void LinkedList::remove(std::string id, int fov, double volume, double center_x, double center_y, double min_x, double max_x, double min_y, double max_y)
{
    Node* newnode= new Node(id,fov,volume,center_x,center_y,min_x,min_y,max_x,max_y);
    Node* current=head;
    Node* previous=nullptr;

    if (newnode->data == current->data){
        current = current->next;
        delete head;
        head = current;
        return;
    }
    else{
    previous=head;
    current=current->next;

    while (current!=nullptr){
        if (newnode->data == current->data){
            previous->next = current->next;
            delete current;
            return;
        }
        previous=current;
        current=current->next;
    }

    }

    // Implement this function
}

void LinkedList::clear() 
{	
if( head == nullptr){
    tail = nullptr;
    return;
}
    Node *walk=this->head;
    Node *temp;
    while (walk!=nullptr) {
        temp = walk->next;
        delete walk;
        walk = temp;
    }
    this->head = nullptr;
    this->tail = nullptr;
    // Implement this function
}


string LinkedList::print() const 
{
    string answer="fov,volume,center_x,center_y,min_x,max_x,min_y,max_y";
    std::stringstream ss;
    ss<<answer<<"\n";

    Node* newnode=head;

    while(newnode!=nullptr){
        ss<<newnode->data.id<<","<<newnode->data.fov<<","<<newnode->data.volume<<","<<newnode->data.center_x<<","<<newnode->data.center_y<<","<<newnode->data.min_x<<","<<newnode->data.min_y<<","<<newnode->data.max_x<<","<<newnode->data.max_y<<"\n";
        newnode=newnode->next;
    }

    cout<<ss.str();
    return ss.str();

    




   	// Implement this function
    

}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	/* Do not modify this function */
	os << ll.print();
	return os;
}

// given a fov number, count the cells observed in that fov
int LinkedList::countN(int fov)
{
	/* Do not modify this function */
    int count = 0;
    Node* cur = head;
    while (cur)
    {
        if (cur->data.fov == fov)
            count++;
        cur = cur->next;
    }
    return count;
}

/* given a fov number, compute the average volume of all the cells observed in
 * that fov
 */
double LinkedList::average(int fov)
{
    
    // Implement this function
     double sum = 0;
    //double avg = average(fov);
    int count = countN(fov);

    if (count == 0)
        return -1;

    Node* cur = head;
    while (cur)
    {
        if (fov == cur->data.fov)
            sum += (cur->data.volume);
        cur = cur->next;
    }

    return sum/count;
}

/* given a fov number, compute the variance volume of all the cells observed in
 * that fov
 */
double LinkedList::variance(int fov)
{
	/* Do not modify this function */
    double sum = 0;
    double avg = average(fov);
    int count = countN(fov);

    if (count == 0)
        return -1;

    Node* cur = head;
    while (cur)
    {
        if (fov == cur->data.fov)
            sum += (cur->data.volume - avg) * (cur->data.volume - avg);
        cur = cur->next;
    }

    return sum/count;
}

/* given a fov number, remove outliers
 */
string LinkedList::outliers(int fov, int k, int N)
{
    // Implement this function
    if (N>countN(fov)){
        string line="";
        line="Less than " + std::to_string(N) + " cells in fov " + std::to_string(fov);
        return line;
    }

    else{
        double newk=sqrt(variance(fov));
        double upper=average(fov)+k*newk;
        double lower=average(fov)-k*newk;
        int cellCount=0; 

        Node *newsource=head;
        
        while(newsource!= nullptr){
            if (newsource->data.volume>upper){
                remove(newsource->data.id,newsource->data.fov,newsource->data.volume,newsource->data.center_x,newsource->data.center_y,newsource->data.min_x,newsource->data.max_x,newsource->data.min_y,newsource->data.max_y);
                cellCount++;
            }
            if (newsource->data.volume<lower){
                remove(newsource->data.id,newsource->data.fov,newsource->data.volume,newsource->data.center_x,newsource->data.center_y,newsource->data.min_x,newsource->data.max_x,newsource->data.min_y,newsource->data.max_y);
                cellCount++;
            }

            newsource=newsource->next;
        }
        string line1;
        line1=std::to_string(cellCount)+" cells are removed.";

        return line1;
    }


}
