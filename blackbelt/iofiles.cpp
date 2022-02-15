//take input.txt, analyze each word and value and create into an output.txt file

#include <cstring>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>

//declare prototype
void printAway(int aCounter, std::string aString);

//print each translated line from the input
void printAway(int aCounter, std::string aString){
  int x;
  std::ofstream outFile;
  //create output file
  outFile.open("output.txt", std::ios_base::app);
  //for loop to print each piece of string, repeated however many times necessary
  for (x = 0; x < aCounter; x++){
    outFile << aString + ',';
  }
  outFile << std::endl;
  outFile.close();
}

int main(){
  // counter is the bank for the amount of times the text will be printed
  // text will be set to the entire line of text to be translated
  int counter;
  std::stringstream converter;
  std::string sCounter;
  std::string currentLine;
  std::ifstream inFile;
  std::string text;
  std::stringstream ss;

  //seek input file
  inFile.open("input.txt");
  for (int i = 0; i < 10; i++){
    //i represents each line in input file. use modulus to tell program if line is for string, or values
    //if i has no remainder, it's on a line of values
    if (i % 2 == 0){
      getline(inFile, currentLine);
      
      //create a temporary counter, set to one of three values at a time
      int tempCounter = 0;
     
      //clear the stringstreams
      ss.clear();
      ss.str("");
      converter.clear();
      converter.str("");

      //load variables into ss stream
      ss.str(currentLine);
      //use sCounter to get the line of numbers as a string
      getline(ss, sCounter);
      
      //clear counter in case previous line of numbers' counter is still loaded
      if (counter != 0){
        counter = 0;
      }
      
      //break down specific line down to each character
      char * cstr = new char [sCounter.length()+1];
      std::strcpy (cstr, sCounter.c_str());
    
      //use comma argument to ignore commas between numbers
      char * p = std::strtok (cstr,",");
      while (p!=0){
        //convert character from string to integer
        converter << p;
        converter >> tempCounter;
        counter = counter + tempCounter;
        p = std::strtok(NULL,",");
      }
    }
    //if i has a remainder, it's on a line of string
    else {
      //preparations for ss and getline like in other part of if statement
      getline(inFile, currentLine);
      ss.clear();
      ss.str("");
      converter.clear();
      converter.str("");

      ss.str(currentLine);
      //use text to get line of text to be analyzed
      getline(ss, text);
      
      //wait! did you put a valid number?
      if (counter == 0){
        std::cout << std::endl;
        std::cout << "Please enter whole numbers that add up to a positive whole number." << std::endl;
        return 0;
      }
      //does your total counter equal a positive number?
      else if (counter < 0) {
        std::cout << std::endl;
        std::cout << "Please ensure each line of numbers don't add up to a negative number." << std::endl;
        return 0;
      }
      else {
        //use other function we defined
        printAway(counter, text);
      }
    }
  }
  inFile.close();
  return 0;
}
