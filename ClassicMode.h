/*
Taylor Ropiequet
2349522
ropiequet@chapman.edu
CPSC 350-02
Assignment 2

This is my .h header file with a class "ClassicMode" listing my variables and methods.
*/

#include <iostream>
#include "GameBoard.h"
#ifndef CLASSICMODE_H
#define CLASSICMODE_H


using namespace std;

class ClassicMode{

public:

  // ClassicMode();
  // ClassicMode(int r, int c);

  int checkNeighbors(int r, int c, GameBoard* g);
  GameBoard* CreateNextGen(GameBoard* g);





};
#endif
