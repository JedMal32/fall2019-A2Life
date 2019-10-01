#include <iostream>
#include <fstream>
#include "Generator.h"
#include "Board.h"

using namespace std;

Generator::Generator(){

};

Board Generator::text(string file){
  int counter = 0;
  int y = 0;
  ifstream input(file);
  string yInput;
  getline(input, yInput);
  int yVal = stoi(yInput);
  string xInput;
  getline(input, xInput);
  int xVal = stoi(xInput);
  Board game = Board(yVal, xVal);
  for(string line; getline(input, line);){ //Mostly correct, but soemthing is still off
    int x = 0;
    ++y;
    for(char c : line){
      ++x;
      bool decider = 0;
      if(c=='X'){
        decider = 1;
      }
      if(c=='-'){
        decider = 0;
      }
      game.setSpace(y,x,decider);
    }

  }
  return game;
}

Board Generator::random(int y, int x, float d){
  Board game = Board(y,x);
  srand(time(NULL));
  for(int v=1; v<=y; ++v){
    for(int h=1; h<=x; ++h){
      float r = float(rand() % 1000)/1000;
      if(r<d){
        game.setSpace(v,h,1);
      }else{
        game.setSpace(v,h,0);
      }
    }
  }
  return game;
}
