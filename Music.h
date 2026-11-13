#ifndef MUSIC_HEADER
#define MUSIC_HEADER

/*
  Created by Matthew G (Referencing Rule of 3 Implementation video by ReelLearning on YT)
*/

#include <iostream>

class Music : public Media{

  // allows << operator to access private class vars for printing
  friend std::ostream& operator<<(std::ostream& os,const Music& source);
  
private:
  static const int default_duration = -3660;
  static constexpr char default_publisher[13] = "No Publisher";
  static constexpr char default_artist[10] = "No Artist";
  float duration;
  char* publisher;
  char* artist;
  
public:
  // constructor
  Music(const int year = default_year,const char* title = default_title, const int duration = default_duration, const char* publisher = default_publisher, const char* artist = default_artist); 
  
  // copy constructor (unnecessary)
  Music(const Music& source);
  
  // overloaded assignment operator (unnecessary)
  Music& operator=(const Music& source);
  
  // destructor
  virtual ~Music();

  // functions to return private variables
  float get_duration();

  void get_publisher(char* returnString);

  void get_artist(char* returnString);

  virtual int get_type();
};

#endif
