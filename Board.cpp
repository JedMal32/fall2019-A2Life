#include <iostream>
#include <fstream>
#include "Board.h"

using namespace std;

Board::Board(){
  y = 8;
  x = 8;
  grid = new char*[y];
  for(int i = 0; i < y; i++){
    grid[i] = new char[x];
    for(int j = 0; j < x; j++){
      grid [i][j] = 0;
    }
  }
}

Board::Board(int a, int b){
  y = a;
  x = b;
  grid = new char*[y];
  for(int i = 0; i < y; i++){
    grid[i] = new char[x];
    for(int j = 0; j < x; j++){
      grid [i][j] = 0;
    }
  }
}

void Board::setSpace(int a, int b, bool z){
  grid[a-1][b-1] = z;
}

bool Board::getSpace(int a, int b){
  return grid[a-1][b-1];
}

void Board::consolePrint(){
  for(int v=1; v<=y; ++v){
    for(int h=1; h<=x; ++h){
      if(getSpace(v,h)==0){
        cout << "-";
      }
      if(getSpace(v,h)==1){
        cout << "X";
      }
    }
    cout << endl;
  }
}

void Board::filePrint(string name, int gen){
  ofstream toFile;
  toFile.open(name, ios::app);
  toFile << gen << endl;
  for(int v=1; v<=y; ++v){
    string lineOut;
    for(int h=1; h<=x; ++h){
      if(getSpace(v,h)==0){
        lineOut += '-';
      }
      if(getSpace(v,h)==1){
        lineOut += 'X';
      }
    }
    toFile << lineOut << endl;
  }
  toFile.close();


  //output <<
}

int Board::getY(){
  return y;
}

int Board::getX(){
  return x;
}
