#ifndef MUSIC_HEADER
#define MUSIC_HEADER

/*
  Header file for music class, child of parent class. holds duration, publisher, and artist values (as well as parent class values)
  
  Created by Matthew G (Referencing Rule of 3 Implementation video by ReelLearning on YT)

  last worked on: 11/13/26
*/

// import needed library
#include <iostream>

// main class definitions
class Music : public Media{

  // allows << operator to access private class vars for printing
  friend std::ostream& operator<<(std::ostream& os,const Music& source);

  //class variables and defaults
private:
  static const int default_duration = -3660;
  static constexpr char default_publisher[13] = "No Publisher";
  static constexpr char default_artist[10] = "No Artist";
  int duration;
  char* publisher;
  char* artist;
  
public:
  // constructor, assigns passed in values to a new class object
  Music(const int year = default_year,const char* title = default_title, const int duration = default_duration, const char* publisher = default_publisher, const char* artist = default_artist); 
  
  // copy constructor (unnecessary), same as constructor but the values come from another class object
  Music(const Music& source);
  
  // overloaded assignment operator (unnecessary) copies values from another class object into the one the operator was called on
  Music& operator=(const Music& source);
  
  // destructor, cleans up class variables in the heap properly (virtual so parent class destructor is called after it)
  virtual ~Music();

  // functions to return private variables
  virtual int get_duration();

  virtual void get_publisher(char* returnString);

  virtual void get_artist(char* returnString);

  // returns the class type as a number
  virtual int get_type();
};

#endif
