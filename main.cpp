#include <iostream>
#include <vector>
#include "Media.h"
#include "Game.h"
#include "Music.h"
#include "Movie.h"


using namespace std;

int main(){
  Game* media1 = new Game(2000,"asd",5.6,"blizzard");
  Game* media2 = new Game(1993,"fgh",9.9,"ubislop");
  char title[] = "failed";

  cout << *media1;
  cout << *media2;

  cout << (*media1).get_rating() << endl;
  (*media2).get_publisher(title);
  cout << title << endl;

  Game* media3 = new Game(*media1);
  
  (*media1) = (*media2);

  cout << *media1;
  cout << *media2;
  cout << *media3;

  (*media1).get_title(title);
  
  delete media1;

  cout << title;
  
}
