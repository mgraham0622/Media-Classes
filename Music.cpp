/*
  C++ file for music class, defines the methods outlined in the header file
  
  Created by Matthew G (Referencing Rule of 3 Implementation Video by ReelLearning on YT)

  last worked on: 11/13/26
 */

// imports libraries used
#include "Media.h"
#include "Music.h"
#include <cstring>

// sets up namespace
using namespace std;

// prints out class type and variables when a class object is put into the output stream
ostream& operator<<(ostream& os, const Music& source){
  char endcap[11] = "----------";
  char mediaLabel[18] = "Media Type: Music";
  char titleLabel[8] = "Title: ";
  char yearLabel[7] = "Year: ";
  char durationLabel[11] = "Duration: ";
  char publisherLabel[12] = "Publisher: ";
  char artistLabel[9] = "Artist: ";
  char secondsLabel[9] = " seconds";
  os << endcap << endl;
  os << mediaLabel << endl;
  os << titleLabel << source.title << endl;
  os << yearLabel << source.year << endl;
  os << durationLabel << source.duration << secondsLabel << endl;
  os << publisherLabel << source.publisher << endl;
  os << artistLabel << source.artist << endl;
  os << endcap;
  return os << endl;
}

// puts passed in values into a new class object, also calls parent constructor for values shared with parent
Music::Music(const int year,const char* title, const int duration, const char* publisher, const char* artist):Media(year,title){
  this->duration = duration;
  this->publisher = new char[strlen(publisher)+1];
  strcpy(this->publisher,publisher);
  this->artist = new char[strlen(artist)+1];
  strcpy(this->artist,artist);
}

// copy constructor, same as regular constructor (above), but it gets its values from another class object
Music::Music(const Music& source):Media(source){
  this->duration = source.duration;
  this->publisher = new char[strlen(source.publisher)+1];
  strcpy(this->publisher,source.publisher);
  this->artist = new char[strlen(source.artist)+1];
  strcpy(this->artist,source.artist);
}

// copies values from another class object into the one the = operator was called on
Music& Music::operator=(const Music& source){
  if (this == &source){
    return *this;
  } else {
    Media::operator=(source);
    this->duration = source.duration;
    delete[] this->publisher; 
    this->publisher = new char[strlen(source.publisher)+1];
    strcpy(this->publisher,source.publisher);
    delete[] this->artist;
    this->artist = new char[strlen(source.artist)+1];
    strcpy(this->artist,source.artist);
    return *this;
  }
}

// deletes class variables that were on the heap and sets thir pointers to point at nothing
Music::~Music(){
  delete[] this->publisher;
  this->publisher = nullptr;
  delete[] this->artist; 
  this->artist = nullptr;
}

// getter functions that return in-class variables
int Music::get_duration(){
  return this->duration;
}
void Music::get_publisher(char* returnString){
  strcpy(returnString,this->publisher);
}
void Music::get_artist(char* returnString){
  strcpy(returnString,this->artist);
}
// returns class type as a number
int Music::get_type(){
  return 2;
}
