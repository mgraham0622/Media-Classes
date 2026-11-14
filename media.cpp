/*
  C++ file for media parent class, defines what the class methods do.

  Created by Matthew G (Referencing Rule of 3 Implementation Video by ReelLearning on YT)

  Last worked on: 11/13/26
 */

// imports necessary libraries
#include "Media.h"
#include <cstring>

// defines namespace
using namespace std;

// overloaded output stream operator, defines what gets output when a class object is printed
ostream& operator<<(ostream& os, const Media& source){
  // prints out class type and class variables
  char endcap[11] = "----------";
  char mediaLabel[18] = "Media Type: Media";
  char titleLabel[8] = "Title: ";
  char yearLabel[7] = "Year: ";
  os << endcap << endl;
  os << mediaLabel << endl;
  os << titleLabel << source.title << endl;
  os << yearLabel << source.year << endl;
  os << endcap;
  return os << endl;
}

// constructor, takes in variables assigned at creation and assigns them to variables for the class object created
Media::Media(const int year,const char* title){
  this->year = year;
  this->title = new char[strlen(title)+1];
  strcpy(this->title,title);
}

// copy constructor, creates a new class with the same (in terms of their values) variables as the class passed in
Media::Media(const Media& source){
  this->year = source.year;
  this->title = new char[strlen(source.title)+1];
  strcpy(this->title,source.title);
}

//overloaded assignment operator, makes sure that when one object is set equal to another it actually copies the values
Media& Media::operator=(const Media& source){
  if (this == &source){
    return *this;
  } else {
    this->year = source.year;
    delete[] this->title;
    this->title = new char[strlen(source.title)+1];
    strcpy(this->title,source.title);
    return *this;
  }
}

// destructor, deletes class values when it is deleted or reaches the end of the program it was in
Media::~Media(){
  // deletes the carray that was on the heap and points its pointer to nothing
  delete[] this->title;
  this->title = nullptr;
}

// getter functions, return the values within the class when called
int Media::get_year(){
  return this->year;
}
void Media::get_title(char* returnString){
  strcpy(returnString,this->title);
}
// returns the type of media class this class is as a number
int Media::get_type(){
  return 0;
}
// virtual functions that return nothing so that child classes can call,override them as main class pointers
void Media::get_publisher(char* returnString){}

int Media::get_duration(){return 0;}

float Media::get_rating(){return 0;}

void Media::get_director(char* returnString){}

void Media::get_artist(char* returnString){}
