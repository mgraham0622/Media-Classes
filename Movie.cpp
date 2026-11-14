/*
  C++ file for Movie class (child of Media class), holds rating, directorm and duration values
  
  Created by Matthew G (Referencing Rule of 3 Implementation Video by ReelLearning on YT)

  Last worked on: 11/13/26
 */

//import libraries
#include "Media.h"
#include "Movie.h"
#include <cstring>

// set up namespace
using namespace std;

// outputs class type and class variables when put in the output stream
ostream& operator<<(ostream& os, const Movie& source){
  char endcap[11] = "----------";
  char mediaLabel[18] = "Media Type: Movie";
  char titleLabel[8] = "Title: ";
  char yearLabel[7] = "Year: ";
  char ratingLabel[9] = "Rating: ";
  char directorLabel[11] = "Director: ";
  char durationLabel[11] = "Duration: ";
  char secondsLabel[9] = " seconds";
  os << endcap << endl;
  os << mediaLabel << endl;
  os << titleLabel << source.title << endl;
  os << yearLabel << source.year << endl;
  os << ratingLabel << source.rating << endl;
  os << directorLabel << source.director << endl;
  os << durationLabel << source.duration << secondsLabel << endl;
  os << endcap;
  return os << endl;
}
// creates a new class object, assigning the values passed in to the variables in that object
Movie::Movie(const int year,const char* title, const float rating, const char* director, const int duration):Media(year,title){
  this->rating = rating;
  this->director = new char[strlen(director)+1];
  strcpy(this->director,director);
  this->duration = duration;
}
// copy constructor, same as above but the variables come from another class object
Movie::Movie(const Movie& source):Media(source){
  this->rating = source.rating;
  this->director = new char[strlen(source.director)+1];
  strcpy(this->director,source.director);
  this->duration = source.duration;
}
// copies variables from a class object of the same type to one the = operator is used on
Movie& Movie::operator=(const Movie& source){
  if (this == &source){
    return *this;
  } else {
    Media::operator=(source);
    this->rating = source.rating;
    delete[] this->director;
    this->director = new char[strlen(source.director)+1];
    strcpy(this->director,source.director);
    this->duration = source.duration;
    return *this;
  }
}
// deletes class variables in the heap and sets their pointers to nothing
Movie::~Movie(){
  delete[] this->director; 
  this->director = nullptr;
}
// getter methods that return class variable values
float Movie::get_rating(){
  return this->rating;
}
void Movie::get_director(char* returnString){
  strcpy(returnString,this->director);
}

int Movie::get_duration(){
  return this->duration;
}
// returns the class type as a number
int Movie::get_type(){
  return 3;
}
