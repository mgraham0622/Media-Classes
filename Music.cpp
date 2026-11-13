/*
  Created by Matthew G (Referencing Rule of 3 Implementation Video by ReelLearning on YT)
 */
#include "Media.h"
#include "Music.h"
#include <cstring>

using namespace std;

ostream& operator<<(ostream& os, const Music& source){
  char endcap[11] = "----------";
  char mediaLabel[18] = "Media Type: Music";
  char titleLabel[8] = "Title: ";
  char yearLabel[7] = "Year: ";
  char durationLabel[11] = "Duration: ";
  char publisherLabel[12] = "Publisher: ";
  char artistLabel[9] = "Artist: ";
  os << endcap << endl;
  os << mediaLabel << endl;
  os << titleLabel << source.title << endl;
  os << yearLabel << source.year << endl;
  os << durationLabel << source.duration << endl;
  os << publisherLabel << source.publisher << endl;
  os << artistLabel << source.artist << endl;
  os << endcap;
  return os << endl;
}
Music::Music(const int year,const char* title, const int duration, const char* publisher, const char* artist):Media(year,title){
  this->duration = duration;
  this->publisher = new char[strlen(publisher)+1];
  strcpy(this->publisher,publisher);
  this->artist = new char[strlen(artist)+1];
  strcpy(this->artist,artist);
}
Music::Music(const Music& source):Media(source){
  this->duration = source.duration;
  this->publisher = new char[strlen(source.publisher)+1];
  strcpy(this->publisher,source.publisher);
  this->artist = new char[strlen(artist)+1];
  strcpy(this->artist,artist);
}

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
    this->artist = new char[strlen(artist)+1];
    strcpy(this->artist,artist);
    return *this;
  }
}
Music::~Music(){
  delete[] this->publisher;
  this->publisher = nullptr;
  delete[] this->artist; 
  this->artist = nullptr;
}
int Music::get_duration(){
  return this->duration;
}
void Music::get_publisher(char* returnString){
  strcpy(returnString,this->publisher);
}
void Music::get_artist(char* returnString){
  strcpy(returnString,this->publisher);
}
int Music::get_type(){
  return 2;
}
