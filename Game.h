#ifndef GAME_HEADER
#define GAME_HEADER

/*
  Header for child Media class, holds rating/publisher variables.
  
  Created by Matthew G (Referencing Rule of 3 Implementation video by ReelLearning on YT)

  last worked on: 11/13/26
*/

// imports libraries needed
#include <iostream>

// main class/function definitions
class Game : public Media{

  // allows << operator to access private class vars for printing
  friend std::ostream& operator<<(std::ostream& os,const Game& source);

  // variables the class uses, cannot be modified/returned without using methods defined below on a game class
private:
  // default values
  static constexpr float default_rating = -10.0;
  static constexpr char default_publisher[13] = "No Publisher";
  // real class values
  float rating;
  char* publisher;

  
public:
  // constructor, sets up new class variable with passed in values
  Game(const int year = default_year,const char* title = default_title, const float rating = default_rating, const char* publisher = default_publisher); 
  
  // copy constructor (unnecessary), makes a copy of another class object of the same type
  Game(const Game& source);
  
  // overloaded assignment operator (unnecessary), copies values from one class to another
  Game& operator=(const Game& source);
  
  // destructor, makes sure values on heap are cleaned up properly
  virtual ~Game();

  // functions to return private variables
  virtual float get_rating();

  virtual void get_publisher(char* returnString);

  // function to return class type as a number
  virtual int get_type();
};

#endif
