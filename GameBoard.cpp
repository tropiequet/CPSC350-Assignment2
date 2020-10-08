/*
Taylor Ropiequet
2349522
ropiequet@chapman.edu
CPSC 350-02
Assignment 2

This is my file that implements my variables and methods for  the GameBoard class.
*/

#include "GameBoard.h"
#include <iostream>
#include <fstream>
#include <istream>
#include <cmath>
#include <math.h>
#include <ctime>
#include <time.h>
#include <cstdlib>
#include <string>
#include <random>
#include <bits/stdc++.h>

using namespace std;




GameBoard::GameBoard(){
  rows = 128;
  cols = 128;
  grid = new char*[rows];
  for (int i = 0; i < rows; ++i){
    grid[i] = new char[cols];
  }
  size = 0;
}

GameBoard::GameBoard(int r, int c){
  rows = r;
  cols = c;
  grid = new char*[rows];
  for (int i = 0; i < rows; ++i){
    grid[i] = new char[cols];
  }
  size = rows * cols;
}

GameBoard::~GameBoard(){
  for (int i = 0; i < rows; i++) {
  delete[] grid[i];
}
delete[] grid;
}

bool GameBoard::isEmpty(){
  int count = 0;
  for (int r = 0; r < rows; ++r){
    for (int c = 0; c < cols; ++c){
      if (grid[r][c] == '-'){
        count++;
      }
    }
  }
  if (count == size){
    return true;
  }else{
    return false;
  }
}




void GameBoard::randomBoard(double density){ //generates random board if thats what user chooses
  int count = 0;
  int randomRow;
  int randomCol;

  int maxX = size * density;

  while (count < maxX){
    randomRow = rand() % rows;
    randomCol = rand() % cols;
    if (grid[randomRow][randomCol] == 'X'){
      continue;
    }else{
      grid[randomRow][randomCol] = 'X';
      count++;
    }
  }

  for (int r = 0; r < rows; ++r){
    for (int c = 0; c < cols; ++c){
      if (grid[r][c] == 'X'){
        continue;
      }else{
        grid[r][c] = '-';
      }
    }
  }
  printBoard();
}


void GameBoard::createBoard(string file){
  ifstream infile(file);
  infile >> rows;
  infile >> cols;
  char character;

  for (int r = 0; r < rows; ++r){
    for (int c = 0; c < cols; ++c){
      infile >> character;
      grid[r][c] = character;
    }
  }
}


void GameBoard::printBoard(){
  for (int r = 0; r < rows; ++r){
    for (int c = 0; c < cols; ++c){
      //cout << "ROW" << endl;
      if (grid[r][c] == '-'){
        cout<<'-';
      }else if (grid[r][c] == 'X'){
        cout<<'X';
      }
    }
    cout << endl;
  }
}



char** GameBoard::getGrid(){
  return grid;
}

void GameBoard::setGrid(char** g){
  grid = g;
}

int GameBoard::getRows(){
  return rows;
}

int GameBoard::getCols(){
  return cols;
}


bool GameBoard::isEqualTo(GameBoard* gNext){
  char** nextGrid = gNext->getGrid();
  char** currGrid = getGrid();

  int differences = 0;

  for (int r = 0; r < rows; ++r){
    for (int c = 0; c < cols; ++c){
      if (currGrid[r][c] == nextGrid[r][c]){
        continue;
      }else{
        differences++;
      }
    }
  }

  if (differences == 0){
    return true;
  }else{
    return false;
  }
}


void GameBoard::writeFile(ofstream& outfile, int count){
   //ofstream outfile;
  // outfile.open(file, ios::out | ios::app);

  outfile << "Generation " << count << endl;

  for (int r = 0; r < rows; ++r){
    for (int c = 0; c < cols; ++c){
      outfile << grid[r][c];
    }
    outfile << endl;
  }
  outfile << endl;
}
