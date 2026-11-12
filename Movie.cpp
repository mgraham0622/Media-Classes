/*
  Created by Matthew G (Referencing Rule of 3 Implementation Video by ReelLearning on YT)
 */
#include "Media.h"
#include "Movie.h"
#include <cstring>

using namespace std;

ostream& operator<<(ostream& os, const Movie& source){
  char endcap[11] = "----------";
  char titleLabel[8] = "Title: ";
  char yearLabel[7] = "Year: ";
  char ratingLabel[9] = "Rating: ";
  char directorLabel[11] = "Director: ";
  char durationLabel[11] = "Duration: ";
  os << endcap << endl;
  os << titleLabel << source.title << endl;
  os << yearLabel << source.year << endl;
  os << ratingLabel << source.rating << endl;
  os << directorLabel << source.director << endl;
  os << durationLabel << source.duration;
  os << endcap;
  return os << endl;
}
Movie::Movie(const int year,const char* title, const float rating, const char* director, const int duration):Media(year,title){
  this->rating = rating;
  this->director = new char[strlen(director)+1];
  strcpy(this->director,director);
  this->duration = duration;
}
Movie::Movie(const Movie& source):Media(source){
  this->rating = source.rating;
  this->director = new char[strlen(source.director)+1];
  strcpy(this->director,source.director);
  this->duration = source.duration;
}

Movie& Movie::operator=(const Movie& source){
  if (this == &source){
    return *this;
  } else {
    Media::operator=(source);
    this->rating = source.rating;
    this->director = new char[strlen(source.director)+1];
    strcpy(this->director,source.director);
    this->duration = source.duration;
    return *this;
  }
}
Movie::~Movie(){
  delete[] this->director; 
}
float Movie::get_rating(){
  return this->rating;
}
void Movie::get_director(char* returnString){
  strcpy(returnString,this->director);
}

int Movie::get_duration(){
  return this->duration;
}
