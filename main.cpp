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

void strip(char* input){
  // establishes variables used
  char* temp = new char[strlen(input)+1];
  int length;
  int newLength = 0;
  char ch1;

  // gets length of the input carray
  length = strlen(input);
  
  // goes through and capitalizes alphanumeric characters and adds them to output
  for(int i = 0; i<length; i++){
    ch1 = input[i];
    if(isalnum(ch1)){
      ch1 = toupper(ch1);
      temp[newLength] = ch1;
      newLength += 1;
    }
  }
  temp[newLength] = '\0';
  // sets input to the output
  strcpy(input,temp);
  delete[] temp;
}

bool getYN(const char prompt[] = "y/n?: "){
  char input = ' ';
  bool noValue = true;
  bool returnValue;
  while(noValue){
    cout << prompt;
    cin >> input;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    if(tolower(input) == 'y'){
      noValue = false;
      returnValue =  true;
    } else if (tolower(input) == 'n'){
      noValue = false;
      returnValue = false;
    }
  }
  return returnValue;
}

// gets text input using a passed in prompt and assigns it to the char passed in
void getTextInput(char* input, char prompt[]){
  cout << prompt;
  cin.getline(input,sizeof(input));
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

// gets float input using a passed in prompt and assigns it to a float passed in
void getFloatInput(float &input, char prompt[]){
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


void search(const vector<Media*> input, vector<Media*> &output){
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
  vector<Media*> temp = {};
  // a list holding all class 'id's' returned by get_type, 0 is media, 1 is game, 2 is music, 3 is movie
  vector<int> possibleClasses = {0,1,2,3};
  char word[256];
  char returnWord[256];
  int number = 0;
  float decimal = 0.0;

  // all media match
  output = input;
  
  if (getYN(titleYN) == true){
    //get title
    getTextInput(word,titlePr);
    for (auto it = output.begin(); it != output.end(); it++){
      (**it).get_title(returnWord);
      if (strcmp(returnWord,word) == 0){
	temp.push_back(*it);
      }
    }
    output = temp;
    temp = {};
  }
  if (getYN(yearYN) == true){
    //get year
    getIntInput(number,yearPr);
    for (auto it = output.begin(); it != output.end(); it++){
      if ((**it).get_year() == number){
        temp.push_back(*it);
      }
    }
    output = temp;
    temp = {};
  }
  if (getYN(publisherYN) == true){
    // eliminate standard media
    if (find(possibleClasses.begin(),possibleClasses.end(),0) != possibleClasses.end()){
      possibleClasses.erase(find(possibleClasses.begin(),possibleClasses.end(),0));
    }
    // eliminate movies
    if (find(possibleClasses.begin(),possibleClasses.end(),3) != possibleClasses.end()){
      possibleClasses.erase(find(possibleClasses.begin(),possibleClasses.end(),3));
    }
    //get publisher
    getTextInput(word,publisherPr);
    for (auto it = output.begin(); it != output.end(); it++){
      if (find(possibleClasses.begin(),possibleClasses.end(),(**it).get_type()) != possibleClasses.end()){
	(**it).get_publisher(returnWord);
	if (strcmp(returnWord,word) == 0){
	  temp.push_back(*it);
	}
      }
    }
    output = temp;
    temp = {};
  }
  if (getYN(durationYN) == true){
    // eliminate standard media
    if (find(possibleClasses.begin(),possibleClasses.end(),0) != possibleClasses.end()){
      possibleClasses.erase(find(possibleClasses.begin(),possibleClasses.end(),0));
    }
    // eliminate video games
    if (find(possibleClasses.begin(),possibleClasses.end(),1) != possibleClasses.end()){
      possibleClasses.erase(find(possibleClasses.begin(),possibleClasses.end(),1));
    }
    //get duration
    getIntInput(number,durationPr);
    for (auto it = output.begin(); it != output.end(); it++){
      if (find(possibleClasses.begin(),possibleClasses.end(),(**it).get_type()) != possibleClasses.end()){
        if ((**it).get_duration() == number){
          temp.push_back(*it);
        }
      }
    }
    output = temp;
    temp = {};
  }
  if (getYN(ratingYN) == true){
    // eliminate standard media
    if (find(possibleClasses.begin(),possibleClasses.end(),0) != possibleClasses.end()){
      possibleClasses.erase(find(possibleClasses.begin(),possibleClasses.end(),0));
    }
    //eliminate music
    if (find(possibleClasses.begin(),possibleClasses.end(),2) != possibleClasses.end()){
      possibleClasses.erase(find(possibleClasses.begin(),possibleClasses.end(),2));
    }
    // get rating
    getFloatInput(decimal,ratingPr);
    for (auto it = output.begin(); it != output.end(); it++){
      if (find(possibleClasses.begin(),possibleClasses.end(),(**it).get_type()) != possibleClasses.end()){
        if ((**it).get_rating() == decimal){
          temp.push_back(*it);
        }
      }
    }
    output = temp;
    temp = {};
  }
  if (getYN(directorYN) == true){
    // eliminate everything but movies
    if (find(possibleClasses.begin(),possibleClasses.end(),3) != possibleClasses.end()){
      possibleClasses = {3};
    } else {
      possibleClasses = {};
   }
    // get director
    getTextInput(word,directorPr);
    for (auto it = output.begin(); it != output.end(); it++){
      if (find(possibleClasses.begin(),possibleClasses.end(),(**it).get_type()) != possibleClasses.end()){
	(**it).get_director(returnWord);
	if (strcmp(returnWord,word) == 0){
          temp.push_back(*it);
        }
      }
    }
    output = temp;
    temp = {};
  }
  if (getYN(artistYN) == true){
    // eliminate everything but music
    if (find(possibleClasses.begin(),possibleClasses.end(),2) != possibleClasses.end()){
      possibleClasses = {2};
    } else {
      possibleClasses = {};
    }
    // get artist
    getTextInput(word,artistPr);
    for (auto it = output.begin(); it != output.end(); it++){
      if (find(possibleClasses.begin(),possibleClasses.end(),(**it).get_type()) != possibleClasses.end()){
	(**it).get_artist(returnWord);
	if (strcmp(returnWord,word) == 0){
          temp.push_back(*it);
        }
      }
    }
    output = temp;
    temp = {};
  }
  if (output.empty()){
    char emptyPrompt[32] = "No Results Matched Your Search.";
    cout << emptyPrompt << endl;
  } else {
    char resultsPrompt[36] = "These are the Results that Matched:";
    cout << resultsPrompt << endl;
    for (auto it = output.begin(); it != output.end(); it++){
      switch((**it).get_type()){
      case 0:
	cout << (**it);
	break;
      case 1:
	cout << *(static_cast<Game*>((*it)));
	break;
      case 2:
	cout << *(static_cast<Music*>((*it)));;
	break;
      case 3:
	cout << *(static_cast<Movie*>((*it)));;
	break;
      }
    }
  }
}

void remove(vector<Media*> &input){
  char deletePrompt[36] = "Search for what you want to delete:";
  char confirmation[32] = "Do you want to delete? (y/n)?: ";
  char success[15] = "Items Deleted!";
  char noDelete[26] = "Items will Not be Deleted";
  char noResults[19] = "No Items to Delete";
  vector<Media*> toDelete = {};
  cout << deletePrompt << endl;
  search(input,toDelete);
  if (toDelete.empty()){
    cout << noResults << endl;
  } else {
    if (getYN(confirmation) == true){
      for (auto del = toDelete.begin(); del != toDelete.end(); del++){
	auto it = find(input.begin(),input.end(),(*del));
	if (it != input.end()){
	  delete (*it);
	  input.erase(it);
	}
      }
      cout << success << endl;
    } else {
      cout << noDelete << endl;
    }
  }
}

void add(vector<Media*> &input){
  char typeToAddPrompt[60] = "What Would You Like to Add? GAME, MUSIC, MOVIE, or MEDIA?: ";
  char type[256];
  char tryAgainPrompt[29] = "Not a Valid Type! Try Again!";
  char success[15] = "Object Added!";
  bool hasType = false;
  vector<const char*> types = {"MEDIA","GAME","MUSIC","MOVIE"};
  int typeNum = -1;

  char titlePr[35] = "enter title: ";
  char yearPr[35] = "enter year: ";
  char publisherPr[35] = "enter publisher name: ";
  char durationPr[35] = "enter duration in seconds: ";
  char ratingPr[35] = "enter rating (0.0 to 10.0): ";
  char directorPr[35] = "enter director name: ";
  char artistPr[35] = "enter artist name: ";

  char title[256];
  int year = -1;
  char artist[256];
  int duration = -1;
  char publisher[256];
  char director[256];
  float rating = -1.0;

  
  while (!hasType){
    typeNum = -1;
    getTextInput(type,typeToAddPrompt);
    strip(type);
    for(auto it = types.begin(); it != types.end(); it++){
      if (strcmp(type,*it) == 0){
	typeNum = it - types.begin();
      }
    }
    switch(typeNum){
    case 0:
      getTextInput(title,titlePr);
      getIntInput(year,yearPr);
      input.push_back(new Media(year,title));
      hasType = true;
      break;
    case 1:
      getTextInput(title,titlePr);
      getIntInput(year,yearPr);
      getTextInput(publisher,publisherPr);
      getFloatInput(rating,ratingPr);
      input.push_back(new Game(year,title,rating,publisher));
      hasType = true;
      break;
    case 2:
      getTextInput(title,titlePr);
      getIntInput(year,yearPr);
      getTextInput(artist,artistPr);
      getIntInput(duration,durationPr);
      getTextInput(publisher,publisherPr);
      input.push_back(new Music(year,title,duration,publisher,artist));
      hasType = true;
      break;
    case 3:
      getTextInput(title,titlePr);
      getIntInput(year,yearPr);
      getIntInput(duration,durationPr);
      getTextInput(director,directorPr);
      getFloatInput(rating,ratingPr);
      input.push_back(new Movie(year,title,rating,director,duration));
      hasType = true;
      break;
    }
    if (hasType == false){
      cout << tryAgainPrompt << endl;
    } else {
      cout << success << endl;
    }
  }
}

int main(){
  char commandPrompt[47] = "Enter a Command (ADD,SEARCH,DELETE, or QUIT): ";
  char emptyList[22] = "The Database is Empty";
  char quitYN[38] = "Are You Sure You Want To Quit?(y/n): ";
  char goodbye[9] = "Goodbye!";
  char command[256];
  int commandNum = -1;
  vector<const char*> commands = {"ADD","SEARCH","DELETE","QUIT"};
  vector<Media*> main = {};
  vector<Media*> searchOutput = {};
  bool running = true;
  while (running){
    commandNum = -1;
    getTextInput(command,commandPrompt);
    strip(command);
    for(auto it = commands.begin(); it != commands.end(); it++){
      if (strcmp(command,*it) == 0){
        commandNum = it - commands.begin();
      }
    }
    switch (commandNum){
    case 0:
      add(main);
      break;
    case 1:
      if (main.empty()){
	cout << emptyList << endl;
      } else {
	search(main,searchOutput);
	searchOutput = {};
      }
      break;
    case 2:
      if (main.empty()){
        cout << emptyList << endl;
      } else {
        remove(main);
      }
      break;
    case 3:
      if(getYN(quitYN)){
	running = false;
	cout << goodbye << endl;
	for (auto it = main.begin(); it != main.end(); it++){
	  delete (*it);
	}
	main.clear();
      }
      break;
    }
  }
}
