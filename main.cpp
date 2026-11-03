#include <iostream>
#include <vector>
#include "Media.h"
/*
#include "Game.h"
#include "Song.h"
#include "Film.h"
*/

using namespace std;

int main(){
  Media* media1 = new Media(2000,"asd");
  Media* media2 = new Media(1993,"fgh");
  char title[] = "failed";

  cout << *media1;
  cout << *media2;

  cout << (*media1).get_year() << endl;
  (*media2).get_title(title);
  cout << title << endl;

  Media* media3 = new Media(*media1);
  
  (*media1) = (*media2);

  cout << *media1;
  cout << *media2;
  cout << *media3;

  delete media1;

  cout << *media1.title;
 
}
