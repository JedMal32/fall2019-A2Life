#include <cstdlib>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include "Board.h"
#include "Generator.h"
#include "Generationer.h"
class Board;
class Generate;
class Generationer;


using namespace std;

int main(int argc, char** argv){

  //Asks if the board should be generated or inputed
  cout << "Would you like to start the simulation with a randomly generated board (1) or would you like to input your own flat text file (2)?" << endl;
  cout << "Please enter 1 or 2: ";
  int randomOrFlat = 0;
  cin >> randomOrFlat;
  Board mainBoard = Board();
  if(randomOrFlat == 1){
    int x = 0;
    int y = 0;
    float density = 0;
    cout << "What would you like the width of the board to be?: ";
    cin >> x;
    cout << "What would you like the height of the board to be?: ";
    cin >> y;
    cout << "What would you like the density of the board to be? (between 0 and 1): ";
    cin >> density;
    Generator g = Generator();
    mainBoard = g.random(y,x,density);
    cout << "Board is generated." << endl;
  }else if(randomOrFlat == 2){
    string name = "";
    cout << "What is the name of the file?: ";
    cin >> name;
    Generator g = Generator();
    mainBoard = g.text(name);
    cout << "Board is generated." << endl;
  }else{
    cout << "That is not a 1 or a 2, will now randomly generate and 8x8 board with density of .5" << endl;
    Generator g = Generator();
    mainBoard = g.random(8,8,.5);
  }

  //Boundary Mode
  cout << endl << "Would you like to run in boundary mode classic (c), donut (d), or mirror (m)? (c/d/m): ";
  char boundaryMode;
  cin >> boundaryMode;
  Generationer gen = Generationer(boundaryMode);
  if(boundaryMode=='c'){
    gen.setMode('c');
    cout << "Gamemode set to classic mode" << endl;
  }else if(boundaryMode=='d'){
    gen.setMode('d');
    cout << "Gamemode set to donut mode" << endl;
  }else if(boundaryMode=='m'){
    gen.setMode('m');
    cout << "Gamemode set to mirror mode" << endl;
  }else{
    gen.setMode('c');
    cout << "Valid character not entered, defaulting to classic mode" << endl;
  }

  //Pause, enter, output
  cout << endl << "Between generations, would you like to pause (p), hit the enter key (e), or instead output the final result(o)? (p/e/o): ";
  char pSO;
  cin >> pSO;
  if(pSO=='p'){
    bool keepGoing = 1;
    int genCounter = 0;
    cout << genCounter << endl;
    mainBoard.consolePrint();
    cout << endl;
    while(keepGoing){
      usleep(1000000);
      ++genCounter;
      cout << genCounter << endl;
      mainBoard = gen.evaluator(mainBoard);
      mainBoard.consolePrint();
      cout << "\n";
      if(gen.getSame()>2){
        keepGoing = 0;
      }
    }
  }
  if(pSO=='e'){
    bool keepGoing = 1;
    int genCounter = 0;
    cout << genCounter << endl;
    mainBoard.consolePrint();
    cout << endl;
    cin.get();
    while(keepGoing){
      cin.get();
      ++genCounter;
      cout << genCounter << endl;
      mainBoard = gen.evaluator(mainBoard);
      mainBoard.consolePrint();
      cout << "\n";
      if(gen.getSame()>2){
        keepGoing = 0;
      }
    }
  }
  if(pSO=='o'){
    cout << "What would you like to name the output file? (please include extension): ";
    string outputFile;
    cin >> outputFile;
    ofstream emptyFile;
    emptyFile.open(outputFile);
    emptyFile.close(); //empties out the previous file
    bool keepGoing = 1;
    int genCounter = 0;
    mainBoard.filePrint(outputFile, genCounter);
    while(keepGoing){
      ++genCounter;
      mainBoard = gen.evaluator(mainBoard);
      mainBoard.filePrint(outputFile, genCounter);
      if(gen.getSame()>2){
        keepGoing = 0;
      }
    }
  }

  cout << "Simulation ended, please press enter to exit" << endl;
  cin.get();


}
