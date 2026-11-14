#ifndef MEDIA_HEADER
#define MEDIA_HEADER

/*
  This is a header file for a printable parent media class with accesible title and year values
  
  Created by Matthew G (Referencing Rule of 3 Implementation video by ReelLearning on YT)

  Last Worked On: 11/19/26
*/

// imports libraries needed
#include <iostream>

// main class definition
class Media{

  // allows << operator to access private class vars for printing
  friend std::ostream& operator<<(std::ostream& os,const Media& source);

  // variables that only the class and its children can access
protected:
  static const int default_year = -1;
  static constexpr char default_title[9] = "No Title";
  int year;
  char* title;

  // public methods
public:
  // constructor, creates the class object
  Media(const int year = default_year,const char* title = default_title); 
  
  // copy constructor (unnecessary), also creates the class object but with another class passed in
  Media(const Media& source);
  
  // overloaded assignment operator (unnecessary), makes = operator behave properly
  Media& operator=(const Media& source);
  
  // destructor, deletes all class data stored in the heap
  virtual ~Media();

  // functions to return protected variables
  int get_year();

  void get_title(char* returnString);
  
  // virtual function to tell what type/child of media class this is for casting/printing
  virtual int get_type();

  // virtual getter functions that return nothing so child classes can override and call them as main class pointers
  virtual void get_publisher(char* returnString);

  virtual int get_duration();

  virtual float get_rating();

  virtual void get_director(char* returnString);

  virtual void get_artist(char* returnString);
};

#endif
