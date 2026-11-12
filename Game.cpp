/*
  Created by Matthew G (Referencing Rule of 3 Implementation Video by ReelLearning on YT)
 */
#include "Media.h"
#include "Game.h"
#include <cstring>

using namespace std;

ostream& operator<<(ostream& os, const Game& source){
  char endcap[11] = "----------";
  char titleLabel[8] = "Title: ";
  char yearLabel[7] = "Year: ";
  char ratingLabel[9] = "Rating: ";
  char publisherLabel[12] = "Publisher: ";
  os << endcap << endl;
  os << titleLabel << source.title << endl;
  os << yearLabel << source.year << endl;
  os << ratingLabel << source.rating << endl;
  os << publisherLabel << source.publisher << endl;
  os << endcap;
  return os << endl;
}
Game::Game(const int year,const char* title, const float rating, const char* publisher):Media(year,title){
  this->rating = rating;
  this->publisher = new char[strlen(publisher)+1];
  strcpy(this->publisher,publisher);
}
Game::Game(const Game& source):Media(source){
  this->rating = source.rating;
  this->publisher = new char[strlen(source.publisher)+1];
  strcpy(this->publisher,source.publisher);
}

Game& Game::operator=(const Game& source){
  if (this == &source){
    return *this;
  } else {
    Media::operator=(source);
    this->rating = source.rating;
    delete[] this->publisher;
    this->publisher = new char[strlen(source.publisher)+1];
    strcpy(this->publisher,source.publisher);
    return *this;
  }
}
Game::~Game(){
  delete[] this->publisher; 
  this->publisher = nullptr;
}
float Game::get_rating(){
  return this->rating;
}
void Game::get_publisher(char* returnString){
  strcpy(returnString,this->publisher);
}
