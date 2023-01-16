/*
 * CellData.h
 *
 *  Created on: Nov 9, 2021
 *      Author: student
 */

#include <iostream>
#include <string>
#include "CellData.h"

using std::cout;
using std::string;

CellData::CellData(): id("-1"), fov(-1), volume(-1), center_x(-1), center_y(-1), min_x(-1),min_y(-1),max_x(-1), max_y(-1){
    
} //initialize everything

CellData::CellData(std::string id, int fov, double volume, double center_x, double center_y, double min_x, double max_x, double min_y, double max_y):
id(id), fov(fov), volume(volume), center_x(center_x), center_y(center_y), min_x(min_x),min_y(min_y),max_x(max_x), max_y(max_y){
    
} //initialize everything



CellData::~CellData() {} // You should not need to implement this

bool CellData::operator<(const CellData& b) {

	// Implement this

    if (b.fov>fov){
        return true;
    }
    else if (b.fov<fov){
        return false;
    }
    else if (b.id>id){
        return true;
    }
    else if(b.id<id){
        return false;
    }

return false;
}

bool CellData::operator==(const CellData& b)
{
    // Implement this
    if(b.id==id && b.fov==fov){
        return true;
    }
    else if(b.id!=id && b.fov!=fov){
        return false;
    }
return false;
}
