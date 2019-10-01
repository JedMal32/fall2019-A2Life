#include <iostream>
#include <fstream>
#include "Generationer.h"
#include "Board.h"

using namespace std;

Generationer::Generationer(){
  mode = 'c';
  sameAsLast = 0;
}

Generationer::Generationer(char c){
  mode = c;
  sameAsLast = 0;
}

char Generationer::getMode(){
  return mode;
}

void Generationer::setMode(char c){
  mode = c;
}

int Generationer::getSame(){
  return sameAsLast;
}

void Generationer::incrementSame(){
  ++sameAsLast;
}

Board Generationer::evaluator(Board b){
  Board toReturn = Board();
  if(getMode()=='c'){
    toReturn = evaluatorClassic(b);
  }
  if(getMode()=='d'){
    toReturn = evaluatorDonut(b);
  }
  if(getMode()=='m'){
    toReturn = evaluatorMirror(b);
  }
  return toReturn;
}

Board Generationer::evaluatorClassic(Board b){
  int y = b.getY();
  int x = b.getX();
  Board newBoard = Board(y,x);

  for(int v = 1; v <= y; ++v){
    for(int h = 1; h <= x; ++h){
      int sum = 0;
      if(v>1 && h>1){ //TOP LEFT
        sum += b.getSpace(v-1,h-1);
      }
      if(v>1){ //TOP MIDDLE
        sum += b.getSpace(v-1,h);
      }
      if(v>1 && h<x){ //TOP RIGHT
        sum += b.getSpace(v-1,h+1);
      }
      if(h<x){ //RIGHT
        sum += b.getSpace(v,h+1);
      }
      if(v<y && h<x){ //BOTTOM RIGHT
        sum += b.getSpace(v+1,h+1);
      }
      if(v<y){ //BOTTOM
        sum += b.getSpace(v+1,h);
      }
      if(v<y && h>1){ //BOTTOM LEFT
        sum += b.getSpace(v+1,h-1);
      }
      if(h>1){ //LEFT
        sum += b.getSpace(v,h-1);
      }

      if(sum<2){
        newBoard.setSpace(v,h,0);
      }else if(sum==2){
        newBoard.setSpace(v,h,b.getSpace(v,h));
      }else if(sum==3){
        newBoard.setSpace(v,h,1);
      }else if(sum>3){
        newBoard.setSpace(v,h,0);
      }
    }
  }

  int differentNums = 0;
  for(int v = 1; v <= y; ++v){
    for(int h = 1; h <= x; ++h){
      if(!(b.getSpace(v,h)==newBoard.getSpace(v,h))){
        differentNums++;
      }
    }
  }
  if(differentNums==0){
    incrementSame();
  }

  return newBoard;

}



Board Generationer::evaluatorDonut(Board b){ //THIS IS COPIED FROM MIRROR, NEED TO UPDATE ELSEIF'S
  int y = b.getY();
  int x = b.getX();
  Board newBoard = Board(y,x);

  for(int v = 1; v <= y; ++v){
    for(int h = 1; h <= x; ++h){
      int sum = 0;
      if(v>1 && h>1){ //TOP LEFT
        sum += b.getSpace(v-1,h-1);
      }else if(v>1){
        sum += b.getSpace(y,h);
      }else if(h>1){
        sum += b.getSpace(v,x);
      }else{
        sum += b.getSpace(y,x);
      }
      if(v>1){ //TOP MIDDLE
        sum += b.getSpace(v-1,h);
      }else{
        sum += b.getSpace(x,h);
      }
      if(v>1 && h<x){ //TOP RIGHT
        sum += b.getSpace(v-1,h+1);
      }else if(v>1){
        sum += b.getSpace(x,h);
      }else if(h<x){
        sum += b.getSpace(v,1);
      }else{
        sum += b.getSpace(x,1);
      }
      if(h<x){ //RIGHT
        sum += b.getSpace(v,h+1);
      }else{
        sum += b.getSpace(v,1);
      }
      if(v<y && h<x){ //BOTTOM RIGHT
        sum += b.getSpace(v+1,h+1);
      }else if(v<y){
        sum += b.getSpace(1,h);
      }else if(h<x){
        sum += b.getSpace(v,1);
      }else{
        sum += b.getSpace(1,1);
      }
      if(v<y){ //BOTTOM
        sum += b.getSpace(v+1,h);
      }else{
        sum += b.getSpace(1,h);
      }
      if(v<y && h>1){ //BOTTOM LEFT
        sum += b.getSpace(v+1,h-1);
      }else if(v<y){
        sum += b.getSpace(1,h);
      }else if(h>1){
        sum += b.getSpace(v,x);
      }else{
        sum += b.getSpace(1,x);
      }
      if(h>1){ //LEFT
        sum += b.getSpace(v,h-1);
      }else{
        sum += b.getSpace(v,x);
      }

      if(sum<2){
        newBoard.setSpace(v,h,0);
      }else if(sum==2){
        newBoard.setSpace(v,h,b.getSpace(v,h));
      }else if(sum==3){
        newBoard.setSpace(v,h,1);
      }else if(sum>3){
        newBoard.setSpace(v,h,0);
      }
    }
  }

  int differentNums = 0;
  for(int v = 1; v <= y; ++v){
    for(int h = 1; h <= x; ++h){
      if(!(b.getSpace(v,h)==newBoard.getSpace(v,h))){
        differentNums++;
      }
    }
  }
  if(differentNums==0){
    incrementSame();
  }

  return newBoard;

}



Board Generationer::evaluatorMirror(Board b){
  int y = b.getY();
  int x = b.getX();
  Board newBoard = Board(y,x);

  for(int v = 1; v <= y; ++v){
    for(int h = 1; h <= x; ++h){
      int sum = 0;
      if(v>1 && h>1){ //TOP LEFT
        sum += b.getSpace(v-1,h-1);
      }else if(v>1){
        sum += b.getSpace(v-1,h);
      }else if(h>1){
        sum += b.getSpace(v,h-1);
      }else{
        sum += b.getSpace(v,h);
      }
      if(v>1){ //TOP MIDDLE
        sum += b.getSpace(v-1,h);
      }else{
        sum += b.getSpace(v,h);
      }
      if(v>1 && h<x){ //TOP RIGHT
        sum += b.getSpace(v-1,h+1);
      }else if(v>1){
        sum += b.getSpace(v-1,h);
      }else if(h<x){
        sum += b.getSpace(v,h+1);
      }else{
        sum += b.getSpace(v,h);
      }
      if(h<x){ //RIGHT
        sum += b.getSpace(v,h+1);
      }else{
        sum += b.getSpace(v,h);
      }
      if(v<y && h<x){ //BOTTOM RIGHT
        sum += b.getSpace(v+1,h+1);
      }else if(v<y){
        sum += b.getSpace(v+1,h);
      }else if(h<x){
        sum += b.getSpace(v,h+1);
      }else{
        sum += b.getSpace(v,h);
      }
      if(v<y){ //BOTTOM
        sum += b.getSpace(v+1,h);
      }else{
        sum += b.getSpace(v,h);
      }
      if(v<y && h>1){ //BOTTOM LEFT
        sum += b.getSpace(v+1,h-1);
      }else if(v<y){
        sum += b.getSpace(v+1,h);
      }else if(h>1){
        sum += b.getSpace(v,h-1);
      }else{
        sum += b.getSpace(v,h);
      }
      if(h>1){ //LEFT
        sum += b.getSpace(v,h-1);
      }else{
        sum += b.getSpace(v,h);
      }

      if(sum<2){
        newBoard.setSpace(v,h,0);
      }else if(sum==2){
        newBoard.setSpace(v,h,b.getSpace(v,h));
      }else if(sum==3){
        newBoard.setSpace(v,h,1);
      }else if(sum>3){
        newBoard.setSpace(v,h,0);
      }
    }
  }

  int differentNums = 0;
  for(int v = 1; v <= y; ++v){
    for(int h = 1; h <= x; ++h){
      if(!(b.getSpace(v,h)==newBoard.getSpace(v,h))){
        differentNums++;
      }
    }
  }
  if(differentNums==0){
    incrementSame();
  }

  return newBoard;

}
