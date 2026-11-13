#ifndef GAME_HEADER
#define GAME_HEADER

/*
  Created by Matthew G (Referencing Rule of 3 Implementation video by ReelLearning on YT)
*/

#include <iostream>

class Game : public Media{

  // allows << operator to access private class vars for printing
  friend std::ostream& operator<<(std::ostream& os,const Game& source);
  
private:
  static constexpr float default_rating = -10.0;
  static constexpr char default_publisher[13] = "No Publisher";
  float rating;
  char* publisher;
  
public:
  // constructor
  Game(const int year = default_year,const char* title = default_title, const float rating = default_rating, const char* publisher = default_publisher); 
  
  // copy constructor (unnecessary)
  Game(const Game& source);
  
  // overloaded assignment operator (unnecessary)
  Game& operator=(const Game& source);
  
  // destructor
  virtual ~Game();

  // functions to return private variables
  float get_rating();

  void get_publisher(char* returnString);

  virtual int get_type();
};

#endif
