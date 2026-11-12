#ifndef MOVIE_HEADER
#define MOVIE_HEADER

/*
  Created by Matthew G (Referencing Rule of 3 Implementation video by ReelLearning on YT)
*/

#include <iostream>

class Movie : public Media{

  // allows << operator to access private class vars for printing
  friend std::ostream& operator<<(std::ostream& os,const Movie& source);
  
private:
  static constexpr float default_rating = -10.0;
  static constexpr char default_director[12] = "No Director";
  static const int default_duration = -3660;
  float rating;
  char* director;
  int duration;
  
public:
  // constructor
  Movie(const int year = default_year,const char* title = default_title, const float rating = default_rating, const char* director = default_director, const int duration = default_duration); 
  
  // copy constructor (unnecessary)
  Movie(const Movie& source);
  
  // overloaded assignment operator (unnecessary)
  Movie& operator=(const Movie& source);
  
  // destructor
  virtual ~Movie();

  // functions to return private variables
  float get_rating();

  void get_director(char* returnString);

  int get_duration();
    
};

#endif
