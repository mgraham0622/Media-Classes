/*
  cpp file for game child class, defines all of the methods in the header file
  
  Created by Matthew G (Referencing Rule of 3 Implementation Video by ReelLearning on YT)

  last worked on: 11/13/26
 */
// import libraries needed
#include "Media.h"
#include "Game.h"
#include <cstring>

// set up namespace
using namespace std;

// prints out media type and variables when put into the output stream
ostream& operator<<(ostream& os, const Game& source){
  char endcap[11] = "----------";
  char mediaLabel[17] = "Media Type: Game";
  char titleLabel[8] = "Title: ";
  char yearLabel[7] = "Year: ";
  char ratingLabel[9] = "Rating: ";
  char publisherLabel[12] = "Publisher: ";
  os << endcap << endl;
  os << mediaLabel << endl;
  os << titleLabel << source.title << endl;
  os << yearLabel << source.year << endl;
  os << ratingLabel << source.rating << endl;
  os << publisherLabel << source.publisher << endl;
  os << endcap;
  return os << endl;
}

// constructor, turns passed in values into class variables, also calls main class constructor for variables shared with main class
Game::Game(const int year,const char* title, const float rating, const char* publisher):Media(year,title){
  this->rating = rating;
  this->publisher = new char[strlen(publisher)+1];
  strcpy(this->publisher,publisher);
}

// copy constructor, same thing as regular construgtor but it gets the values from another class object
Game::Game(const Game& source):Media(source){
  this->rating = source.rating;
  this->publisher = new char[strlen(source.publisher)+1];
  strcpy(this->publisher,source.publisher);
}

// copies values from one class over to this one
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
// deletes carrays that were on the heap (virtual so child class destructor gets called then main class destructor gets called)
Game::~Game(){
  delete[] this->publisher; 
  this->publisher = nullptr;
}
// getter functions, return class variable values
float Game::get_rating(){
  return this->rating;
}
void Game::get_publisher(char* returnString){
  strcpy(returnString,this->publisher);
}
// returns class type as a number
int Game::get_type(){
  return 1;
}
