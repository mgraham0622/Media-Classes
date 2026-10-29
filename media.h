#ifndef MEDIA_HEADER
#define MEDIA_HEADER

/*
  Created by Matthew G (Referencing Rule of 3 Implementation video by ReelLearning on YT)
*/

#include <iostream>

class Media{

  // allows << operator to access private class vars for printing
  friend std::ostream& operator<<(std::ostream& os,const Media& source);
  
private:
  static const int default_year = -1;
  static const char default_title[9] = "No Title";
  int year;
  char* title;
  
public:
  // constructor
  Media(const int year = default_year,const char* title = &default_title); 
  
  // copy constructor (unnecessary)
  Media(const Media& source);
  
  // overloaded assignment operator (unnecessary)
  Media& operator=(const Media& source);
  
  // destructor
  ~Media();

  // functions to return private variables
  virtual int get_year();

  virtual void get_title(char (&returnString)[]);

    
};

#endif
