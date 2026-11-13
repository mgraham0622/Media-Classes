/*
  Created by Matthew G (Referencing Rule of 3 Implementation Video by ReelLearning on YT)
 */
#include "Media.h"
#include <cstring>

using namespace std;

ostream& operator<<(ostream& os, const Media& source){
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
Media::Media(const int year,const char* title){
  this->year = year;
  this->title = new char[strlen(title)+1];
  strcpy(this->title,title);
}
Media::Media(const Media& source){
  this->year = source.year;
  this->title = new char[strlen(source.title)+1];
  strcpy(this->title,source.title);
}
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
Media::~Media(){
  char* = this->title;
  delete[] this->title;
  this->title = nullptr;
}
int Media::get_year(){
  return this->year;
}
void Media::get_title(char* returnString){
  strcpy(returnString,this->title);
}
int Media::get_type(){
  return 0;
}
