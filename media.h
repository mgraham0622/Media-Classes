#ifndef MEDIA_HEADER
#define MEDIA_HEADER

/*
  Created by Matthew G (Referencing Rule of 3 Implementation video by ReelLearning on YT)
*/

#include <iostream>

class Media{

  // allows << operator to access private class vars for printing
  friend std::ostream& operator<<(std::ostream& os,const Media& source);
  
protected:
  static const int default_year = -1;
  static constexpr char default_title[9] = "No Title";
  int year;
  char* title;
  
public:
  // constructor
  Media(const int year = default_year,const char* title = default_title); 
  
  // copy constructor (unnecessary)
  Media(const Media& source);
  
  // overloaded assignment operator (unnecessary)
  Media& operator=(const Media& source);
  
  // destructor
  virtual ~Media();

  // functions to return protected variables
  int get_year();

  void get_title(char* returnString);
  // virtual function to tell what type/child of media class this is
  virtual int get_type();
  
};

#endif
