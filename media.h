#ifndef MEDIA_H_
#define MEDIA_H_

#include <iostream>

class media{
private:
  static const int default_year = -1;
  static const char default_title[] = "No Title";
  int year;
  char title[];
  
public:
  // constructor
  media(int year = default_year,char* title = &default_title); 
  
  // copy constructor
  media(const media& source);
  
  // overloaded assignment operator
  media& operator=(const media& source);
  
  // destructor
  ~media();

  virtual int get_year();

  virtual void get_title(char returnString[]);
    
};

#endif /* MEDIA_H_ */
