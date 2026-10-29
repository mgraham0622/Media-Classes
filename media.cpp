/*
  Created by Matthew G (Referencing Rule of 3 Implementation Video by ReelLearning on YT)
 */
#include "Media.h"
#include <cstring>

using namespace std;

ostream& operator<<(ostream& os, const Media& source){
  char endcap[11] = "----------";
  char titleLabel[8] = "Title: ";
  char yearLabel[7] = "Year: ";
  os << endcap << endl;
  os << titleLabel << *(source.title) << endl;
  os << yearLabel << source.year << endl;
  os << endcap;
}
Media::Media(const int year,const char* title){
  this->year = year;
  this->title = new char[strlen(*title)+1];
  strcpy(this->title,title);
}
Media::Media(const media& source){
  this->year = source.year;
  this->title = new char[strlen(*source.title)+1];
  strcpy(this->title,source.title);
}
Media& Media::operator=(const Media& source){
  if (*this == source){
    return *this;
  } else {
    this->year = source.year;
    this->title = new char[strlen(*source.title)+1];
    strcpy(this->title,source.title);
    return *this;
  }
}
Media::~Media(){
  delete[] this->title; 
}

