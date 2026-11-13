#include <iostream>
#include <vector>
#include "Media.h"
#include "Game.h"
#include "Music.h"
#include "Movie.h"
#include <limits>
#include <cstring>
#include <algorithm>
#include <ranges>

using namespace std;

void lower(char (&input)[]){
  // establishes variables used
  char temp[] = "";
  int length;
  char ch1;

  // gets length of the input carray
  length = strlen(input);

  // goes through and makes uppercase chars lowercase
  for(int i = 0; i<length; i++){
    ch1 = input[i];
    ch1 = tolower(ch1);
    strncat(temp,&ch1,1);
    }
  // sets input to the output
  strcpy(input,temp);
}

bool getYN(char prompt[] = "y/n?: "){
  char input = ' ';
  bool noValue = true;
  while(noValue){
    cout << prompt;
    cin >> input;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    if(tolower(input) == 'y'){
      noValue = false;
      return true;
    } elif (tolower(input) == 'n'){
      noValue = false;
      return true;
    }
  }
}

// gets text input using a passed in prompt and assigns it to the char passed in
void getTextInput(char (&input)[], char prompt[]){
  cout << prompt;
  cin.getline(input,numeric_limits<streamsize>::max());
}


// gets int input using a passed in prompt and assigns it to an int passed in
void getIntInput(int &input, char prompt[]){
  bool noinput = true;
  char error[22] = "Enter a Valid Number!";
  // checks that input is valid and dosent leave anything in the buffer
  while (noinput){
    cout << prompt;
    cin >> input;
    if (cin.fail() or cin.peek() != '\n'){
      cout << error << endl;
      cin.clear();
    } else {
      noinput = false;
    }
    // removes trailing newline from input buffer
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
  }
}

void search(const vector<media*> input, vector<media*> output){
  char titleYN[35] = "search by title? (y/n): ";
  char titlePr[35] = "enter title: ";
  char yearYN[35] = "search by year? (y/n): ";
  char yearPr[35] = "enter year: ";
  char publisherYN[35] = "search by publisher? (y/n): ";
  char publisherPr[35] = "enter publisher name: ";
  char durationYN[35] = "search by duration? (y/n): ";
  char durationPr[35] = "enter duration in seconds: ";
  char ratingYN[35] = "search by rating? (y/n): ";
  char ratingPr[35] = "enter rating (0.0 to 10.0): ";
  char directorYN[35] = "search by director? (y/n): ";
  char directorPr[35] = "enter director name: ";
  char artistYN[35] = "search by artist? (y/n): ";
  char artistPr[35] = "enter artist name: ";
  vector<media*> temp = {};
  // a list holding all class 'id's' returned by get_type, 0 is media, 1 is game, 2 is music, 3 is movie
  vector<int> possibleClasses = {0,1,2,3};
  output = input;
  if (getYN(titleYN) == true){}
  if (getYN(yearYN) == true){}
  if (getYN(publisherYN) == true){
    if (ranges::find(possibleClasses,0) != possibleClasses.end()){}
    if (ranges::find(possibleClasses,3) != possibleClasses.end()){}
  }
  if (getYN(durationYN) == true){
    if (ranges::find(possibleClasses,0) != possibleClasses.end()){}
  }
  if (getYN(ratingYN) == true){
    if (ranges::find(possibleClasses,0) != possibleClasses.end()){}
  }
  if (getYN(directorYN) == true){
    if (ranges::find(possibleClasses,3) != possibleClasses.end()){
      possibleClasses = {3};
    } else {
      possibleClasses = {};
   }
  }
  if (getYN(artistYN) == true){
    if (ranges::find(possibleClasses,2) != possibleClasses.end()){
      possibleClasses = {2};
    } else {
      possibleClasses = {};
    }
  }
}


int main(){
  
}
