#include "media.h"

using namespace std;

}
media::media(int year, char*title){
  this->year = year;
  for(auto it = begin(*title); it != end(*title); it++){
    this->title[it] = (*title)[it];
  }
}



media::~media(){
  
};
