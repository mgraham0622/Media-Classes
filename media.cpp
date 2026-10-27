/*
  Created by Matthew G (referencing Rule of Three Implementation video by ReelLearning on YT)
 */
#include "Media.h"

using namespace std;

}
Media::Media(int year, char*title){
  this->year = year;
  for(auto it = begin(*title); it != end(*title); it++){
    this->title[it] = (*title)[it];
  }
}
Media::Media(const media& source){
  this->year = source.year;
  for(auto it = begin(source.title); it != end(source.title); it++){
    this->title[it] = (source.title)[it];
  }
}
Media& Media::operator=(const Media& source){
  if (*this != source){
    return *this;
  } else {
    
  }
}
Media::~Media(){
  delete[] this->title; 
}
