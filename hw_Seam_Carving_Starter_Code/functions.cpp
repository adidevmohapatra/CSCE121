#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using namespace std;

// TODO Write this function
int energy(const Pixel *const*image, int col, int row, int width, int height)
{
  int rx=0;
  int bx=0;
  int gx=0;
  int ry=0;
  int by=0;
  int gy=0;
///////////////
  if (height==0 || width==0){
    return 0;
  }

   if (width<2 && height<2){
    return 0;
  }

  if (height<2){
    if (col==0){  
    rx=(image[col+1][row].r)-(image[width-1][row].r);
    bx=(image[col+1][row].b)-(image[width-1][row].b);
    gx=(image[col+1][row].g)-(image[width-1][row].g);
    }
    else if(col==width-1){
    rx=(image[0][row].r)-(image[col-1][row].r);
    bx=(image[0][row].b)-(image[col-1][row].b);
    gx=(image[0][row].g)-(image[col-1][row].g);
    }
    else {
    rx=(image[col+1][row].r)-(image[col-1][row].r);
    bx=(image[col+1][row].b)-(image[col-1][row].b);
    gx=(image[col+1][row].g)-(image[col-1][row].g);
    }

  }
  if (width<2){
    if (row==0){  
    ry=(image[col][row+1].r)-(image[col][height-1].r);
    by=(image[col][row+1].b)-(image[col][height-1].b);
    gy=(image[col][row+1].g)-(image[col][height-1].g);
    }
    else if(row==height-1){
    ry=(image[col][0].r)-(image[col][row-1].r);
    by=(image[col][0].b)-(image[col][row-1].b);
    gy=(image[col][0].g)-(image[col][row-1].g);
    }
    else {
    ry=(image[col][row+1].r)-(image[col][row-1].r);
    by=(image[col][row+1].b)-(image[col][row-1].b);
    gy=(image[col][row+1].g)-(image[col][row-1].g);
    }
  }

 

  if (width>=2){
  if (col==0){  
    rx=(image[col+1][row].r)-(image[width-1][row].r);
    bx=(image[col+1][row].b)-(image[width-1][row].b);
    gx=(image[col+1][row].g)-(image[width-1][row].g);
  }
  else if(col==width-1){
    rx=(image[0][row].r)-(image[col-1][row].r);
    bx=(image[0][row].b)-(image[col-1][row].b);
    gx=(image[0][row].g)-(image[col-1][row].g);
  }
  else {
    rx=(image[col+1][row].r)-(image[col-1][row].r);
    bx=(image[col+1][row].b)-(image[col-1][row].b);
    gx=(image[col+1][row].g)-(image[col-1][row].g);
  }
  }
///////////////
  if (height>=2){
  if (row==0){  
    ry=(image[col][row+1].r)-(image[col][height-1].r);
    by=(image[col][row+1].b)-(image[col][height-1].b);
    gy=(image[col][row+1].g)-(image[col][height-1].g);
  }
  else if(row==height-1){
    ry=(image[col][0].r)-(image[col][row-1].r);
    by=(image[col][0].b)-(image[col][row-1].b);
    gy=(image[col][0].g)-(image[col][row-1].g);
  }
  else {
    ry=(image[col][row+1].r)-(image[col][row-1].r);
    by=(image[col][row+1].b)-(image[col][row-1].b);
    gy=(image[col][row+1].g)-(image[col][row-1].g);
  }
  }
  int total_x = pow(rx,2)+pow(bx,2)+pow(gx,2);
  int total_y = pow(ry,2)+pow(by,2)+pow(gy,2);
  int total_energy=total_x+total_y;
 
  return total_energy;
}

// TODO Write this function
int getVerticalSeam(const Pixel *const*image, int start_col, int width, int height, int* seam)
{
  int total_energy=0;
  seam[0]=start_col;
  total_energy=energy(image,start_col,0,width,height);

  if (height==1){
    return total_energy;
  }

  else{
  for (int i=1;i<height;++i){
    
    if (width==1){
     int mid_energy=energy(image,start_col,i,width,height);
     seam[i]=start_col;
     total_energy+=mid_energy;
      continue;
    }
    else if (start_col==0){
      int mid_energy=energy(image,start_col,i,width,height);
      int right_energy=energy(image,start_col+1,i,width,height);

      if (mid_energy>right_energy){
        start_col+=1;
        seam[i]=start_col;
        total_energy+=right_energy;
      }
      else{
        seam[i]=start_col;
        total_energy+=mid_energy;
      }
      
    }
    else if (start_col==width-1){
      int mid_energy=energy(image,start_col,i,width,height);
      int left_energy=energy(image,start_col-1,i,width,height);
        if (mid_energy>left_energy){
        start_col-=1;
        seam[i]=start_col;
        total_energy+=left_energy;
      }
      else{
        seam[i]=start_col;
        total_energy+=mid_energy;
      }
    }
    else{
      int mid_energy=energy(image,start_col,i,width,height);;
      int right_energy=energy(image,start_col+1,i,width,height);
      int left_energy=energy(image,start_col-1,i,width,height);

      if ((mid_energy<=right_energy) && (mid_energy<=left_energy)){
        seam[i]=start_col;
        total_energy+=mid_energy;
      }
      else if((left_energy<right_energy) && (left_energy<mid_energy)){
        start_col-=1;
        seam[i]=start_col;
        total_energy+=left_energy;
      }
      else if((right_energy<left_energy) && (right_energy<mid_energy)){
        start_col+=1;
        seam[i]=start_col;
        total_energy+=right_energy;
      }
      else if (right_energy==left_energy){
        total_energy+=right_energy;
        start_col+=1;
        seam[i]=start_col;
      }

    }
    }
  
  }
  return total_energy;
}
// TODO Write this function
void removeVerticalSeam(Pixel **image, int& width, int height, int *verticalSeam)
{
 
  for(int i=0;i<height;++i){
    for(int j=0;j<width-1;++j){
      if (j>=verticalSeam[i]){
        image[j][i]=image[j+1][i];
      }
    }
  }
  width--;
}

// TODO Write this function for extra credit
/*
int getHorizontalSeam(const Pixel *const*image, int start_row, int width, int height, int* seam)
{
  return 0;
}

// TODO Write this function for extra credit
void removeHorizontalSeam(Pixel **image, int width, int& height, int *horizontalSeam)
{
  
}
*/
int *findMinVerticalSeam(const Pixel *const*image, int width, int height)
{
  // initialize minSeam and minDistance to seam starting at first col (index 0)
  int *minSeam = new int[height]{0};
  int minDist = getVerticalSeam(image, 0, width, height, minSeam);

  int *candidateSeam = new int[height]{0};
  int candidateDistance = -1; // invalid distance

  // start at second col (index 1) since we initialized with first col (index 0)
  for (int col = 1; col < width; ++col)
  {
    candidateDistance = getVerticalSeam(image, col, width, height, candidateSeam);

    if (candidateDistance < minDist)
    { // new min
      //  swap min & candidate
      minDist = candidateDistance;
      int* temp = candidateSeam;
      candidateSeam = minSeam;
      minSeam = temp;
    }
  }

  // clean up 
  delete [] candidateSeam;

  return minSeam;
}
/*
int *findMinHorizontalSeam(const Pixel *const*image, int width, int height)
{
  // initialize minSeam and minDistance to seam starting at first row (index 0)
  int *minSeam = new int[width]{0};
  int minDistance = getHorizontalSeam(image, 0, width, height, minSeam);

  int *candidateSeam = new int[width]{0};
  int candidateDistance = -1; // invalid distance

  // start at second row (index 1) since we initialized with first row (index 0)
  for (int row = 1; row < height; ++row)
  {
    candidateDistance = getHorizontalSeam(image, row, width, height, candidateSeam);

    if (candidateDistance < minDistance)
    { // new minimum
      //  swap min and candidate seams
      minDistance = candidateDistance;
      int* temp = candidateSeam;
      candidateSeam = minSeam;
      minSeam = temp;
    }
  }

    // clean up 
  delete [] candidateSeam;

  return minSeam;
}
*/
Pixel **createImage(int width, int height)
{
  cout << "Start createImage... " << endl;

  // Create a one dimensional array on the heap of pointers to Pixels
  //    that has width elements (i.e. the number of columns)
  Pixel **image = new Pixel *[width] {}; // initializes to nullptr

  for (int col = 0; col < width; ++col)
  { // loop through each column
    // assign that column to a one dimensional array on the heap of Pixels
    //  that has height elements (i.e. the number of rows)
    try
    {
      image[col] = new Pixel[height];
    }
    catch (std::bad_alloc &e)
    {
      // clean up already allocated arrays
      for (int i = 0; i < col; ++i)
      {
        delete[] image[i];
      }
      delete[] image;
      // rethrow
      throw e;
    }
  }

  // initialize cells
  // cout << "Initializing cells..." << endl;
  for (int row = 0; row < height; ++row)
  {
    for (int col = 0; col < width; ++col)
    {
      // cout << "(" << col << ", " << row << ")" << endl;
      image[col][row] = {0, 0, 0};
    }
  }
  cout << "End createImage... " << endl;
  return image;
}

void deleteImage(Pixel **image, int width)
{
  cout << "Start deleteImage..." << endl;
  // avoid memory leak by deleting the array
  for (int i = 0; i < width; ++i)
  {
    delete[] image[i];
  }
  delete[] image;
  image = nullptr;
  cout << "End deleteImage..." << endl;
}

bool isValidColor(int colorVal)
{
  if (colorVal < 0 || colorVal > 255)
  {
    return false;
  }
  return true;
}

Pixel ** loadImage(string filename, int &width, int &height)
{
  cout << "Start loadImage..." << endl;
  // remove
  ifstream ifs(filename);
  if (!ifs.is_open())
  {
    throw std::invalid_argument("Failed to open input file (" + filename + ")");
  }

  string type;
  ifs >> type; // should be P3
  if (toupper(type.at(0)) != 'P' || type.at(1) != '3')
  {
    throw std::domain_error("Not PPM type P3 (" + type + ")");
  }
  ifs >> width;
  // cout << "w and h: " << w << " " << h << endl;
  if (ifs.fail())
  {
    throw std::domain_error("Read non-integer value for width");
  }
  if (width <= 0)
  {
    ostringstream oss;
    oss << "Width in file must be greater than 0 (" << width << ")";
    throw std::domain_error(oss.str());
  }

  ifs >> height;
  if (ifs.fail())
  {
    cout << "Read non-integer value for height" << endl;
  }
  if (height <= 0)
  {
    ostringstream oss;
    oss << "Height in file must be greater than 0 (" << height << ")";
    throw std::domain_error(oss.str());
  }

  int colorMax = 0;
  ifs >> colorMax;
  if (ifs.fail())
  {
    throw std::domain_error("Read non-integer value for max color value");
  }
  if (colorMax != 255)
  {
    ostringstream oss;
    oss << "Max color value must be 255 (" << colorMax << ")";
    throw std::domain_error(oss.str());
  }

  // load image throws exceptions but we will let them pass through
  Pixel **image = createImage(width, height);

  for (int row = 0; row < height; ++row)
  {
    for (int col = 0; col < width; ++col)
    {
      // cout << "Pixel(" << col << ", " << row << ")" << endl;
      ifs >> image[col][row].r;
      if (ifs.fail() && !ifs.eof())
      { // bad input that is not caused by being at the end of the file
        throw std::domain_error("Read non-integer value for red");
      }
      if (!isValidColor(image[col][row].r))
      {
        ostringstream oss;
        oss << "Invalid color value for red (" << image[col][row].r << ")";
        throw std::domain_error(oss.str());
      }

      ifs >> image[col][row].g;
      if (ifs.fail() && !ifs.eof())
      { // bad input that is not caused by being at the end of the file
        throw std::domain_error("Read non-integer value for green");
      }
      if (!isValidColor(image[col][row].r))
      {
        ostringstream oss;
        oss << "Invalid color value for green (" << image[col][row].r + ")";
        throw std::domain_error(oss.str());
      }

      ifs >> image[col][row].b;
      if (ifs.fail() && !ifs.eof())
      { // bad input that is not caused by being at the end of the file
        throw std::domain_error("Read non-integer value for blue");
      }
      if (!isValidColor(image[col][row].r))
      {
        ostringstream oss;
        oss << "Invalid color value for blue (" << image[col][row].r + ")";
        throw std::domain_error(oss.str());
      }
    }
  }
  cout << "End loadImage..." << endl;
  return image;
}

void outputImage(string filename, const Pixel *const *image, int width, int height)
{
  cout << "Start outputImage..." << endl;
  // remove code
  // declare/define and open output file stream with filename
  ofstream ofs(filename);
  // ensure file is open
  if (!ofs.is_open())
  {
    throw std::invalid_argument("Error: failed to open output file - " + filename);
  }
  ofs << "P3" << endl;
  ofs << width << " " << height << endl;
  ofs << 255 << endl;
  for (int row = 0; row < height; ++row)
  {
    for (int col = 0; col < width; ++col)
    {
      ofs << image[col][row].r << " ";
      ofs << image[col][row].g << " ";
      ofs << image[col][row].b << " ";
    }
    ofs << endl;
  }
  cout << "End outputImage..." << endl;
}