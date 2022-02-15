#include <fstream>
#include <iostream>
#include <sstream>

int main(){
  std::ifstream inFile;
  std::string currentLine;
  std::stringstream converter;
  std::stringstream ss;
  int counter;
  std::string sCounter;
  std::string text;

  inFile.open("numString.csv");
  while (getline(inFile, currentLine)){

    ss.clear();
    ss.str("");
    converter.clear();
    converter.str("");

    ss.str(currentLine);

    getline(ss, sCounter, ',');

    getline(ss, text);

    converter << sCounter;

    converter >> counter;
    std::cout << counter * 10 << " " << text << std::endl;
  }
  inFile.close();
}
