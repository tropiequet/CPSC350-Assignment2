/*
Taylor Ropiequet
2349522
ropiequet@chapman.edu
CPSC 350-02
Assignment 2

This is my .h header file with a class "GameBoard" listing my variables and methods.
*/

#include <iostream>
#ifndef GAMEBOARD_H
#define GAMEBOARD_H

using namespace std;

class GameBoard{

public:
  GameBoard();
  GameBoard(int rows, int cols);
  ~GameBoard();

  int rows;
  int cols;
  double size;
  char **grid;



  void randomBoard(double density);
  void createBoard(string file);

  char** getGrid();
  void setGrid(char** g);
  int getRows();
  int getCols();


  //string checkFile(string fileName);
  bool isEmpty();

  void printBoard();

  bool isEqualTo(GameBoard* gCurr);

  void writeFile(ofstream& outfile, int count);









};
#endif
