#include<iostream>
#include<string>
#include "Node.h"
#include "CellData.h"

using std::cout;

// Default constructor
// remember to initialize next to nullptr
Node::Node(){

    data.id="-1";
    data.fov=-1;
    data.volume=-1;
    data.center_x=-1;
    data.center_y=-1;
    data.min_x = -1;
    data.min_y = -1;
    data.max_x = -1;
    data.max_y = -1;
    next=nullptr;
} 

// Parameterized constructor
// remember to initialize next to nullptr
Node::Node(std::string id, int fov, double volume, double center_x, double center_y, double min_x, double max_x, double min_y, double max_y)
{
    data.id=id;
    data.fov=fov;
    data.volume=volume;
    data.center_x=center_x;
    data.center_y=center_y;
    data.min_x = min_x;
    data.min_y = min_y;
    data.max_x = max_x;
    data.max_y = max_y;
    next=nullptr;
}

