/*
Taylor Ropiequet
2349522
ropiequet@chapman.edu
CPSC 350-02
Assignment 2

This is my file that implements my variables and methods for the DoughnutMode class.
*/

#include "DoughnutMode.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <ctime>
#include<cstdlib>
#include <string>
#include <random>

using namespace std;


int DoughnutMode::checkNeighbors(int r, int c, GameBoard* g){
  int rows = g->getRows();
  int cols = g->getCols();
  int count = 0;
  char** grid = g->getGrid();

  if ((r == 0) && (c == 0)){
    if (grid[r][c+1] == 'X'){
      count++;
    }
    if (grid[r+1][c] == 'X'){
      count++;
    }
    if (grid[r+1][c+1] == 'X'){
      count ++;
    }
    if (grid[r][cols - 1] == 'X'){
      count++;
    }
    if (grid[r+1][cols-1] == 'X'){
      count++;
    }
    if (grid[rows-1][c] == 'X'){
      count++;
    }
    if (grid[rows-1][c+1] == 'X'){
      count++;
    }
    if (grid[rows-1][cols-1] == 'X'){
      count++;
    }
  }else if ((r == 0) && (c == cols - 1)){
    if (grid[r][c-1] == 'X'){
      count++;
    }
    if (grid[r+1][c-1] == 'X'){
      count++;
    }
    if (grid[r+1][c] == 'X'){
      count ++;
    }
    if (grid[0][0] == 'X'){
      count++;
    }
    if (grid[r+1][0] == 'X'){
      count++;
    }
    if (grid[rows-1][0] == 'X'){
      count++;
    }
    if (grid[rows-1][c-1] == 'X'){
      count++;
    }
    if (grid[rows-1][c] == 'X'){
      count++;
    }
  }else if ((r == rows - 1) && (c == 0)){
    if (grid[r-1][c] == 'X'){
      count++;
    }
    if (grid[r-1][c+1] == 'X'){
      count++;
    }
    if (grid[r][c+1] == 'X'){
      count ++;
    }
    if (grid[0][0] == 'X'){
      count++;
    }
    if (grid[0][c+1] == 'X'){
      count++;
    }
    if (grid[0][cols-1] == 'X'){
      count++;
    }
    if (grid[r-1][cols-1] == 'X'){
      count++;
    }
    if (grid[r][cols-1] == 'X'){
      count++;
    }
  }else if ((r == rows - 1) && (c == cols - 1)){
    if (grid[r][c-1] == 'X'){
      count++;
    }
    if (grid[r-1][c-1] == 'X'){
      count++;
    }
    if (grid[r-1][c] == 'X'){
      count ++;
    }
    if (grid[0][c] == 'X'){
      count++;
    }
    if (grid[0][c-1] == 'X'){
      count++;
    }
    if (grid[0][0] == 'X'){
      count++;
    }
    if (grid[r-1][0] == 'X'){
      count++;
    }
    if (grid[r][0] == 'X'){
      count++;
    }
  }else if ((r == 0) && (c > 0) && (c < cols - 1)){
    if (grid[r][c-1] == 'X'){
      count++;
    }
    if (grid[r][c+1] == 'X'){
      count++;
    }
    if (grid[r+1][c-1] == 'X'){
      count ++;
    }
    if (grid[r+1][c] == 'X'){
      count++;
    }
    if (grid[r+1][c+1] == 'X'){
      count++;
    }
    if (grid[rows-1][c-1] == 'X'){
      count++;
    }
    if (grid[rows-1][c] == 'X'){
      count++;
    }
    if (grid[rows-1][c+1] == 'X'){
      count++;
    }
  }else if ((r > 0) && (r < rows - 1) && (c == 0)){
    if (grid[r-1][c] == 'X'){
      count++;
    }
    if (grid[r-1][c+1] == 'X'){
      count++;
    }
    if (grid[r][c+1] == 'X'){
      count ++;
    }
    if (grid[r+1][c+1] == 'X'){
      count++;
    }
    if (grid[r+1][c] == 'X'){
      count++;
    }
    if (grid[r-1][cols-1] == 'X'){
      count++;
    }
    if (grid[r][cols-1] == 'X'){
      count++;
    }
    if (grid[r+1][cols-1] == 'X'){
      count++;
    }
  }else if ((r == rows -1) && (c > 0) && (c < cols - 1)){
    if (grid[r-1][c-1] == 'X'){
      count++;
    }
    if (grid[r-1][c] == 'X'){
      count++;
    }
    if (grid[r-1][c+1] == 'X'){
      count ++;
    }
    if (grid[r][c-1] == 'X'){
      count++;
    }
    if (grid[r][c+1] == 'X'){
      count++;
    }
    if (grid[0][c-1] == 'X'){
      count++;
    }
    if (grid[0][c] == 'X'){
      count++;
    }
    if (grid[0][c+1] == 'X'){
      count++;
    }
  }else if ((r > 0) && (r < rows - 1) && (c == cols -1)){
    if (grid[r-1][c-1] == 'X'){
      count++;
    }
    if (grid[r-1][c] == 'X'){
      count++;
    }
    if (grid[r][c-1] == 'X'){
      count ++;
    }
    if (grid[r+1][c-1] == 'X'){
      count++;
    }
    if (grid[r+1][c] == 'X'){
      count++;
    }
    if (grid[r-1][0] == 'X'){
      count++;
    }
    if (grid[r][0] == 'X'){
      count++;
    }
    if (grid[r+1][0] == 'X'){
      count++;
    }
  }else{
    if (grid[r-1][c-1] == 'X'){
      count++;
    }
    if (grid[r-1][c] == 'X'){
      count++;
    }
    if (grid[r-1][c+1] == 'X'){
      count ++;
    }
    if (grid[r][c-1] == 'X'){
      count++;
    }
    if (grid[r][c+1] == 'X'){
      count++;
    }
    if (grid[r+1][c-1] == 'X'){
      count ++;
    }
    if (grid[r+1][c] == 'X'){
      count++;
    }
    if (grid[r+1][c+1] == 'X'){
      count++;
    }
  }
  return count;
}

GameBoard* DoughnutMode::CreateNextGen(GameBoard* g){
  int rows = g->getRows();
  int cols = g->getCols();

  int count;

  GameBoard *gNext = new GameBoard(rows, cols);

  char** nextGrid = gNext->getGrid();
  char** currGrid = g->getGrid();

  for (int r = 0; r < rows; ++r){
    for (int c = 0; c < cols; ++c){
      count = checkNeighbors(r, c, g);
      if (count <= 1){
        nextGrid[r][c] = '-';
      }else if (count == 2){
        if(currGrid[r][c] == 'X'){
          nextGrid[r][c] = 'X';
        }else{
          nextGrid[r][c] = '-';
        }
      }else if (count == 3){
        nextGrid[r][c] ='X';
      }else{
        nextGrid[r][c] = '-';
      }
    }
  }
  return gNext;
}
