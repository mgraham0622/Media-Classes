/*
This function uses custom classes to allow a user to create and manage a database of various forms of media through a text interface.
The user can use the ADD command to add 4 types of media to the database (Media, Game, Music, and Movie), Search and filter the media
using various parameters with the command SEARCH, and delete specific objects from the database with DELETE. They can also use QUIT to
end the program

Created by: Matthew G

Last worked on: 11/13/26
 */

// include required libraries and custom classes
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
#include <cmath>

// set up namespace
using namespace std;

// function to remove punctuation and capitalize a string inputted
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
      // adds uppercase character and shifts index to the one after it
      temp[newLength] = ch1;
      newLength += 1;
    }
  }
  // adds null terminator
  temp[newLength] = '\0';
  // sets input to the output
  strcpy(input,temp);
  // deletes array that was put on the heap
  delete[] temp;
}

// returns true or false after prompting a yes/no answer from the user with a passed in prompt
bool getYN(const char prompt[] = "y/n?: "){
  // sets up variables
  char input = ' ';
  bool noValue = true;
  bool returnValue;
  // loops until it gets y or no as an input
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
  // returns true if the answer was yes, and false if no
  return returnValue;
}

// gets text input using a passed in prompt and assigns it to the carray passed in
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

// gets float input from 0-10 using a passed in prompt and assigns it to a float passed in
void getFloatInput(float &input, char prompt[]){
  bool noinput = true;
  char error[22] = "Enter a Valid Number!";
  char outOfRange[33] = "Enter a Decimal between 0 and 10";
  // checks that input is valid and dosent leave anything in the buffer
  while (noinput){
    cout << prompt;
    cin >> input;
    // checks if it was a number input
    if (cin.fail() or cin.peek() != '\n'){
      cout << error << endl;
      cin.clear();
      // checks if the number is between 0 and 10
    } else if ((input < 0) or (input > 10)){
      cout << outOfRange << endl;
    } else {
      // rounds the input and returns it
      input = round(input*10)/10;
      noinput = false;
    }
    // removes trailing newline from input buffer
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
  }
}

// search function, prompts the user for various different search fields and prints/returns(through output) all that match the entered ones
void search(const vector<Media*> input, vector<Media*> &output){
  // dialogue carrays
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
  // temp vector used for holding the class objects that match each new filter
  vector<Media*> temp = {};
  // a list holding all class 'id's' returned by get_type, 0 is media, 1 is game, 2 is music, 3 is movie
  vector<int> possibleClasses = {0,1,2,3};
  char word[256];
  char returnWord[256];
  int number = 0;
  float decimal = 0.0;

  //sets it so all media match at the start
  output = input;
  // asks if th user wants to filter by title
  if (getYN(titleYN) == true){
    //gets title
    getTextInput(word,titlePr);
    // finds all class objects that match and puts them on the temp vector
    for (auto it = output.begin(); it != output.end(); it++){
      (**it).get_title(returnWord);
      if (strcmp(returnWord,word) == 0){
	temp.push_back(*it);
      }
    }
    // sets output vector equal to temp and clears output vector
    output = temp;
    temp = {};
  }
  // asks if user wants to filter by year
  if (getYN(yearYN) == true){
    //gets year
    getIntInput(number,yearPr);
    // add all in current match to temp
    for (auto it = output.begin(); it != output.end(); it++){
      if ((**it).get_year() == number){
        temp.push_back(*it);
      }
    }
    // set output to temp
    output = temp;
    temp = {};
  }
  // ask if user wants to filter by publisher
  if (getYN(publisherYN) == true){
    // eliminates standard media from possible class types
    if (find(possibleClasses.begin(),possibleClasses.end(),0) != possibleClasses.end()){
      possibleClasses.erase(find(possibleClasses.begin(),possibleClasses.end(),0));
    }
    // eliminate movies from possible class types
    if (find(possibleClasses.begin(),possibleClasses.end(),3) != possibleClasses.end()){
      possibleClasses.erase(find(possibleClasses.begin(),possibleClasses.end(),3));
    }
    //gets publisher
    getTextInput(word,publisherPr);
    // adds all that match publisher and possible classes in current output to temp
    for (auto it = output.begin(); it != output.end(); it++){
      if (find(possibleClasses.begin(),possibleClasses.end(),(**it).get_type()) != possibleClasses.end()){
	(**it).get_publisher(returnWord);
	if (strcmp(returnWord,word) == 0){
	  temp.push_back(*it);
	}
      }
    }
    // sets temp to output
    output = temp;
    temp = {};
  }
  // asks if user wants to filter by duration
  if (getYN(durationYN) == true){
    // eliminates standard media from possible class types
    if (find(possibleClasses.begin(),possibleClasses.end(),0) != possibleClasses.end()){
      possibleClasses.erase(find(possibleClasses.begin(),possibleClasses.end(),0));
    }
    // eliminates video games from possible class types
    if (find(possibleClasses.begin(),possibleClasses.end(),1) != possibleClasses.end()){
      possibleClasses.erase(find(possibleClasses.begin(),possibleClasses.end(),1));
    }
    //gets duration
    getIntInput(number,durationPr);
    // puts all that match duration and possible classes in current output into temp
    for (auto it = output.begin(); it != output.end(); it++){
      if (find(possibleClasses.begin(),possibleClasses.end(),(**it).get_type()) != possibleClasses.end()){
        if ((**it).get_duration() == number){
          temp.push_back(*it);
        }
      }
    }
    // sets temp to output
    output = temp;
    temp = {};
  }
  // asks if user wants to filter by rating
  if (getYN(ratingYN) == true){
    // eliminates standard media from possible class types
    if (find(possibleClasses.begin(),possibleClasses.end(),0) != possibleClasses.end()){
      possibleClasses.erase(find(possibleClasses.begin(),possibleClasses.end(),0));
    }
    //eliminates music from possible class types
    if (find(possibleClasses.begin(),possibleClasses.end(),2) != possibleClasses.end()){
      possibleClasses.erase(find(possibleClasses.begin(),possibleClasses.end(),2));
    }
    // gets rating
    getFloatInput(decimal,ratingPr);
    // puts all that match rating and possible class types in current output into temp
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
  // asks if the user wants to filter by director
  if (getYN(directorYN) == true){
    // eliminates everything but movies from possible class types
    if (find(possibleClasses.begin(),possibleClasses.end(),3) != possibleClasses.end()){
      possibleClasses = {3};
    } else {
      possibleClasses = {};
   }
    // gets director
    getTextInput(word,directorPr);
    // adds all that match director and possible class types in current output into temp
    for (auto it = output.begin(); it != output.end(); it++){
      if (find(possibleClasses.begin(),possibleClasses.end(),(**it).get_type()) != possibleClasses.end()){
	(**it).get_director(returnWord);
	if (strcmp(returnWord,word) == 0){
          temp.push_back(*it);
        }
      }
    }
    // sets temp equal to output
    output = temp;
    temp = {};
  }
  // asks if the user wants to filter by artist
  if (getYN(artistYN) == true){
    // eliminates everything but music from possible class types
    if (find(possibleClasses.begin(),possibleClasses.end(),2) != possibleClasses.end()){
      possibleClasses = {2};
    } else {
      possibleClasses = {};
    }
    // gets artist
    getTextInput(word,artistPr);
    // adds all that match artist and possible class types into temp
    for (auto it = output.begin(); it != output.end(); it++){
      if (find(possibleClasses.begin(),possibleClasses.end(),(**it).get_type()) != possibleClasses.end()){
	(**it).get_artist(returnWord);
	if (strcmp(returnWord,word) == 0){
          temp.push_back(*it);
        }
      }
    }
    // sets temp equal to output
    output = temp;
    temp = {};
  }
  // checks if anything matched the search
  if (output.empty()){
    // if not, output that
    char emptyPrompt[32] = "No Results Matched Your Search.";
    cout << emptyPrompt << endl;
  } else {
    // if there were results that matched, print them out
    char resultsPrompt[36] = "These are the Results that Matched:";
    cout << resultsPrompt << endl;
    // for each class object in the output vector, gets the class type
    for (auto it = output.begin(); it != output.end(); it++){
      // depending on what type the class object is, casts it to the correct class and outputs it
      switch((**it).get_type()){
      case 0:
	// doesent cast if plain media class
	cout << (**it);
	break;
      case 1:
	// casts to game if game
	cout << *(static_cast<Game*>((*it)));
	break;
      case 2:
	// casts to music if music
	cout << *(static_cast<Music*>((*it)));;
	break;
      case 3:
	// casts to movie if movie
	cout << *(static_cast<Movie*>((*it)));;
	break;
      }
    }
  }
}

// remove function that asks the user to search for what they want to delete then allows them to delete it
void remove(vector<Media*> &input){
  // dialogues
  char deletePrompt[36] = "Search for what you want to delete:";
  char confirmation[32] = "Do you want to delete? (y/n)?: ";
  char success[15] = "Items Deleted!";
  char noDelete[26] = "Items will Not be Deleted";
  char noResults[19] = "No Items to Delete";
  // vector to hold the output of the search
  vector<Media*> toDelete = {};
  cout << deletePrompt << endl;
  // calls search function to get what the user wants to delete and output it into the toDelete vector
  search(input,toDelete);
  // checks if there is anything to delete
  if (toDelete.empty()){
    // if not, says there is nothing to delete
    cout << noResults << endl;
  } else {
    // if there is something to delete, prompts the user one last time
    if (getYN(confirmation) == true){
      // if they say yes, goes through the list and deletes each class object
      for (auto del = toDelete.begin(); del != toDelete.end(); del++){
	// finds vector to delete in main vector and deletes it
	auto it = find(input.begin(),input.end(),(*del));
	// deletes object and pointer from main vector
	if (it != input.end()){
	  delete (*it);
	  input.erase(it);
	}
      }
      // deletes bad pointers remaining in toDelete
      toDelete = {};
      // outputs results of deletion
      cout << success << endl;
    } else {
      // if user says no, gives feedback
      cout << noDelete << endl;
    }
  }
}

// function to add a media type to the input vector
void add(vector<Media*> &input){
  // prompts and variables used
  char typeToAddPrompt[60] = "What Would You Like to Add? GAME, MUSIC, MOVIE, or MEDIA?: ";
  char type[256];
  char tryAgainPrompt[29] = "Not a Valid Type! Try Again!";
  char success[15] = "Object Added!";
  bool hasType = false;
  vector<const char*> types = {"MEDIA","GAME","MUSIC","MOVIE"};
  int typeNum = -1;

  // prompts for different variables
  char titlePr[35] = "enter title: ";
  char yearPr[35] = "enter year: ";
  char publisherPr[35] = "enter publisher name: ";
  char durationPr[35] = "enter duration in seconds: ";
  char ratingPr[35] = "enter rating (0.0 to 10.0): ";
  char directorPr[35] = "enter director name: ";
  char artistPr[35] = "enter artist name: ";

  // variables to hold values passed into classes
  char title[256];
  int year = -1;
  char artist[256];
  int duration = -1;
  char publisher[256];
  char director[256];
  float rating = -1.0;

  // gets the type of media the user wants to add
  while (!hasType){
    // sets current type to nothing
    typeNum = -1;
    // asks what type the user wants to create
    getTextInput(type,typeToAddPrompt);
    // checks it against the vector of types
    strip(type);
    for(auto it = types.begin(); it != types.end(); it++){
      if (strcmp(type,*it) == 0){
	typeNum = it - types.begin();
      }
    }
    // depending on what type it is, prompt user for the variables needed for that type, create it, and add it to the class
    switch(typeNum){
    case 0:
      // create media object
      getTextInput(title,titlePr);
      getIntInput(year,yearPr);
      input.push_back(new Media(year,title));
      hasType = true;
      break;
    case 1:
      // create game object
      getTextInput(title,titlePr);
      getIntInput(year,yearPr);
      getTextInput(publisher,publisherPr);
      getFloatInput(rating,ratingPr);
      input.push_back(new Game(year,title,rating,publisher));
      hasType = true;
      break;
    case 2:
      // create music object
      getTextInput(title,titlePr);
      getIntInput(year,yearPr);
      getTextInput(artist,artistPr);
      getIntInput(duration,durationPr);
      getTextInput(publisher,publisherPr);
      input.push_back(new Music(year,title,duration,publisher,artist));
      hasType = true;
      break;
    case 3:
      // create movie object
      getTextInput(title,titlePr);
      getIntInput(year,yearPr);
      getIntInput(duration,durationPr);
      getTextInput(director,directorPr);
      getFloatInput(rating,ratingPr);
      input.push_back(new Movie(year,title,rating,director,duration));
      hasType = true;
      break;
    }
    // if the type input was not valid, continue the loop and output that user needs to try again
    if (hasType == false){
      cout << tryAgainPrompt << endl;
    } else {
      // outputs if the user succesfully created/added a new object
      cout << success << endl;
    }
  }
}

// main loop, continually prompts user for commands, then executes them
int main(){
  // dialogue used
  char commandPrompt[47] = "Enter a Command (ADD,SEARCH,DELETE, or QUIT): ";
  char emptyList[22] = "The Database is Empty";
  char quitYN[38] = "Are You Sure You Want To Quit?(y/n): ";
  char goodbye[9] = "Goodbye!";
  // vars to hold/identify commands
  char command[256];
  int commandNum = -1;
  // vector with valid commands
  vector<const char*> commands = {"ADD","SEARCH","DELETE","QUIT"};
  // main vector holding all the class objects
  vector<Media*> main = {};
  // dummy vector because the search function needs something passed in to output to
  vector<Media*> searchOutput = {};
  // starts/ends loop
  bool running = true;

  // main loop
  while (running){
    // sets there to be no valid command
    commandNum = -1;
    // asks for a command
    getTextInput(command,commandPrompt);
    // checks if the command is valid/what type it is
    strip(command);
    for(auto it = commands.begin(); it != commands.end(); it++){
      if (strcmp(command,*it) == 0){
        commandNum = it - commands.begin();
      }
    }
    // depending on which command was input, executes the given command
    switch (commandNum){
    case 0:
      // adds object to main vector
      add(main);
      break;
    case 1:
      // allows user to search through main vector
      // checks if there is anything in the database
      if (main.empty()){
	// outputs a message if database is empty
	cout << emptyList << endl;
      } else {
	// searches database and prints matches
	search(main,searchOutput);
	// clears dummy vector
	searchOutput = {};
      }
      break;
    case 2:
      // allows user to search for and delete objects
      // checks if there is anything to delete
      if (main.empty()){
	// outputs message if the database is empty
        cout << emptyList << endl;
      } else {
	// removes whatever the user searches for from main database
        remove(main);
      }
      break;
    case 3:
      // asks if user wants to quit
      if(getYN(quitYN)){
	// if yes, ends loop and says goodbye
	running = false;
	cout << goodbye << endl;
	// deletes all class objects remaining in the database, along with their heap variables
	for (auto it = main.begin(); it != main.end(); it++){
	  delete (*it);
	}
	// clears main function of bad pointers
	main = {};
      }
    }
  }
}
