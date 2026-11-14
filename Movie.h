#ifndef MOVIE_HEADER
#define MOVIE_HEADER

/*
  Header file for movie class, a child of the main Media class. Holds rating, director, and duration variables
  
  Created by Matthew G (Referencing Rule of 3 Implementation video by ReelLearning on YT)

  last worked on: 11/13/26
*/

// import library
#include <iostream>

// main class / method definitions
class Movie : public Media{

  // allows << operator to access private class vars for printing
  friend std::ostream& operator<<(std::ostream& os,const Movie& source);

  // class variables/defaults
private:
  static constexpr float default_rating = -10.0;
  static constexpr char default_director[12] = "No Director";
  static const int default_duration = -3660;
  float rating;
  char* director;
  int duration;
  
public:
  // constructor, takes passed in values and assigns them to variables in a new class object
  Movie(const int year = default_year,const char* title = default_title, const float rating = default_rating, const char* director = default_director, const int duration = default_duration); 
  
  // copy constructor (unnecessary), same as regular constructor but it gets the values from another class object
  Movie(const Movie& source);
  
  // overloaded assignment operator (unnecessary), copies values from one class object into the one the = operator was called on
  Movie& operator=(const Movie& source);
  
  // destructor, properly deletes class variables, including ones on the heap
  virtual ~Movie();

  // functions to return private variables
  virtual float get_rating();

  virtual void get_director(char* returnString);

  virtual int get_duration();

  // function to return the class type as a number
  virtual int get_type();
};

#endif
