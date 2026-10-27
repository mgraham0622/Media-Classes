#ifndef MEDIA_HEADER
#define MEDIA_HEADER

/*
  Created by Matthew G (referencing Rule of Three Implementation video by ReelLearning on YT)
*/

#include <iostream>

class Media{
private:
  static const int default_year = -1;
  static const char default_title[] = "No Title";
  int year;
  char title[];
  
public:
  // constructor
  Media(int year = default_year,char* title = &default_title); 
  
  // copy constructor
  Media(const Media& source);
  
  // overloaded assignment operator
  Media& operator=(const Media& source);
  
  // destructor
  ~Media();

  virtual int get_year();

  virtual void get_title(char (&returnString)[]);
    
};

#endif
