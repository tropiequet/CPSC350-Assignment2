#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include "ClassicMode.h"
#include "DoughnutMode.h"
#include "MirrorMode.h"

using namespace std;


int main(int argc, char** argv){

  srand (time(NULL));

  int mapType;
  int outputType;
  int gameType;
  int rows;
  int cols;
  double popDensity;
  int count;

  GameBoard *gCurr;
  GameBoard *gNext;
  ClassicMode c;
  DoughnutMode d;
  MirrorMode m;


  while (true){
    cout << "Would you like a random map or provide one via file?" << endl;
    cout << "Enter 1 for random map" << endl;
    cout << "Enter 2 for file map" << endl;
    cin >> mapType;
    cout << endl;

    if (mapType == 1){ //random
      cout << "Please enter how many rows: " << endl;
      cin >> rows;
      cout << "Please enter how many columns: " << endl;
      cin >> cols;
      cout << "Please enter the population density: " << endl;
      cin >> popDensity;
      gCurr = new GameBoard(rows, cols);
      gCurr->randomBoard(popDensity);
      break;
    }else if (mapType == 2){ //file map
      string file;
      string line;

      cout << "Please enter the name of the file: " << endl;
      cin >> file;
      cout << endl;

      ifstream infile(file);

      while (!infile.good()){
        cout << "Error! File does not exist! Please enter a new file name: " << endl;
        cin >> file;
        cout << endl;
        infile.open(file);

      }

      infile >> rows;
      infile >> cols;

      gCurr = new GameBoard(rows, cols);
      gCurr->createBoard(file);

      break;
    }else{
      cout << "Error! Incorrect choice! Please try again!" << endl;
    }
  }

  while (true){
    cout << "Which gamemode would you like to play?" << endl;
    cout << "Enter 1 for classic" << endl;
    cout << "Enter 2 for doughnut" << endl;
    cout << "Enter 3 for mirror" << endl;
    cin >> gameType;
    cout << endl;

    if (gameType == 1){ //CLASSIC
      while (true){
        cout << "How would you like the generations to output?" << endl;
        cout << "Enter 1 for a brief pause between generations" << endl;
        cout << "Enter 2 if you want to press enter between generations" << endl;
        cout << "Enter 3 if you want to output to a file" << endl;
        cin >> outputType;
        cout << endl;
        cin.get();

        if (outputType == 1){//brief pause
          count = 1;
          cout << "Generation 0" << endl;
          gCurr->printBoard();
          gNext = c.CreateNextGen(gCurr);

          bool equalGrids = gCurr->isEqualTo(gNext);
          bool isEmpty = gNext->isEmpty();
          sleep(1);

          while ((!equalGrids) && (!isEmpty)){
            cout << "Generation " << count << endl;
            gNext->printBoard();
            gCurr = gNext;
            gNext = c.CreateNextGen(gCurr);
            count++;
            equalGrids = gCurr->isEqualTo(gNext);
            isEmpty = gNext->isEmpty();
            sleep(1);
          }
          cout << "Generations have stabilized/emptied" << endl;
          cout << "Please press enter to exit" << endl;
          cin.get();
          break;
        }
        else if (outputType == 2){ //press enter
          count = 1;
          cout << "Generation 0" << endl;
          gCurr->printBoard();
          cout << "Please press enter to continue" << endl;
          cin.get();
          gNext = c.CreateNextGen(gCurr);

          bool equalGrids = gCurr->isEqualTo(gNext);
          bool isEmpty = gNext->isEmpty();

          while ((!equalGrids) && (!isEmpty)){
            cout << "Generation " << count << endl;
            gNext->printBoard();
            gCurr = gNext;
            gNext = c.CreateNextGen(gCurr);
            count++;
            equalGrids = gCurr->isEqualTo(gNext);
            isEmpty = gNext->isEmpty();
            cout << "Please press enter to continue" << endl;
            cin.get();
          }
          cout << "Generations have stabilized/emptied" << endl;
          cout << "Please press enter to exit" << endl;
          cin.get();
          break;
        }
        else if (outputType == 3){ //write to a file
          count = 1;
          gNext = c.CreateNextGen(gCurr);
          string file;

          cout << "Please enter the name of the file: " << endl;
          cin >> file;
          cin.get();
          cout << endl;

          ofstream outfile(file);
          //outfile.open(file, ios::out | ios::trunc);

          cout << "Generations are writing to a file" << endl;

          gCurr->writeFile(outfile, 0);

          bool equalGrids = gCurr->isEqualTo(gNext);
          bool isEmpty = gNext->isEmpty();

          while ((!equalGrids) && (!isEmpty)){
            gNext->writeFile(outfile, count);
            gCurr = gNext;
            gNext = c.CreateNextGen(gCurr);
            count++;
            equalGrids = gCurr->isEqualTo(gNext);
            isEmpty = gNext->isEmpty();
          }

          cout << "Generations have stabilized/emptied" << endl;
          cout << "Please press enter to exit" << endl;
          cin.get();
          break;

        }
        else{
          cout << "Error! Incorrect choice! Please try again!" << endl;
        }
      }
      break;
    }
    else if (gameType == 2){ //DoughnutMode
      while (true){
        cout << "How would you like the generations to output?" << endl;
        cout << "Enter 1 for a brief pause between generations" << endl;
        cout << "Enter 2 if you want to press enter between generations" << endl;
        cout << "Enter 3 if you want to output to a file" << endl;
        cin >> outputType;
        cout << endl;
        cin.get();

        if (outputType == 1){//brief pause
          count = 1;
          cout << "Generation 0" << endl;
          gCurr->printBoard();
          gNext = d.CreateNextGen(gCurr);

          bool equalGrids = gCurr->isEqualTo(gNext);
          bool isEmpty = gNext->isEmpty();
          sleep(1);

          while ((!equalGrids) && (!isEmpty)){
            cout << "Generation " << count << endl;
            gNext->printBoard();
            gCurr = gNext;
            gNext = d.CreateNextGen(gCurr);
            count++;
            equalGrids = gCurr->isEqualTo(gNext);
            isEmpty = gNext->isEmpty();
            sleep(1);
          }
          cout << "Generations have stabilized/emptied" << endl;
          cout << "Please press enter to exit" << endl;
          cin.get();
          break;
        }
        else if (outputType == 2){ //press enter
          count = 1;
          cout << "Generation 0" << endl;
          gCurr->printBoard();
          cout << "Please press enter to continue" << endl;
          cin.get();
          gNext = d.CreateNextGen(gCurr);

          bool equalGrids = gCurr->isEqualTo(gNext);
          bool isEmpty = gNext->isEmpty();

          while ((!equalGrids) && (!isEmpty)){
            cout << "Generation " << count << endl;
            gNext->printBoard();
            gCurr = gNext;
            gNext = d.CreateNextGen(gCurr);
            count++;
            equalGrids = gCurr->isEqualTo(gNext);
            isEmpty = gNext->isEmpty();
            cout << "Please press enter to continue" << endl;
            cin.get();
          }
          cout << "Generations have stabilized/emptied" << endl;
          cout << "Please press enter to exit" << endl;
          cin.get();
          break;
        }
        else if (outputType == 3){ //write to a file
          count = 1;
          gNext = d.CreateNextGen(gCurr);
          string file;

          cout << "Please enter the name of the file: " << endl;
          cin >> file;
          cin.get();
          cout << endl;

          ofstream outfile(file);
          //outfile.open(file, ios::out | ios::trunc);

          cout << "Generations are writing to a file" << endl;

          gCurr->writeFile(outfile, 0);

          bool equalGrids = gCurr->isEqualTo(gNext);
          bool isEmpty = gNext->isEmpty();

          while ((!equalGrids) && (!isEmpty)){
            gNext->writeFile(outfile, count);
            gCurr = gNext;
            gNext = d.CreateNextGen(gCurr);
            count++;
            equalGrids = gCurr->isEqualTo(gNext);
            isEmpty = gNext->isEmpty();
          }

          cout << "Generations have stabilized/emptied" << endl;
          cout << "Please press enter to exit" << endl;
          cin.get();
          break;
        }
        else{
          cout << "Error! Incorrect choice! Please try again!" << endl;
        }
      }
      break;
    }
    else if (gameType == 3){ //MirrorMode
      while (true){
        cout << "How would you like the generations to output?" << endl;
        cout << "Enter 1 for a brief pause between generations" << endl;
        cout << "Enter 2 if you want to press enter between generations" << endl;
        cout << "Enter 3 if you want to output to a file" << endl;
        cin >> outputType;
        cout << endl;
        cin.get();

        if (outputType == 1){//brief pause
          count = 1;
          cout << "Generation 0" << endl;
          gCurr->printBoard();
          gNext = m.CreateNextGen(gCurr);

          bool equalGrids = gCurr->isEqualTo(gNext);
          bool isEmpty = gNext->isEmpty();
          sleep(1);

          while ((!equalGrids) && (!isEmpty)){
            cout << "Generation " << count << endl;
            gNext->printBoard();
            gCurr = gNext;
            gNext = m.CreateNextGen(gCurr);
            count++;
            equalGrids = gCurr->isEqualTo(gNext);
            isEmpty = gNext->isEmpty();
            sleep(1);
          }
          cout << "Generations have stabilized/emptied" << endl;
          cout << "Please press enter to exit" << endl;
          cin.get();
          break;
        }
        else if (outputType == 2){ //press enter
          count = 1;
          cout << "Generation 0" << endl;
          gCurr->printBoard();
          cout << "Please press enter to continue" << endl;
          cin.get();
          gNext = m.CreateNextGen(gCurr);

          bool equalGrids = gCurr->isEqualTo(gNext);
          bool isEmpty = gNext->isEmpty();

          while ((!equalGrids) && (!isEmpty)){
            cout << "Generation " << count << endl;
            gNext->printBoard();
            gCurr = gNext;
            gNext = m.CreateNextGen(gCurr);
            count++;
            equalGrids = gCurr->isEqualTo(gNext);
            isEmpty = gNext->isEmpty();
            cout << "Please press enter to continue" << endl;
            cin.get();
          }
          cout << "Generations have stabilized/emptied" << endl;
          cout << "Please press enter to exit" << endl;
          cin.get();
          break;
        }
        else if (outputType == 3){ //write to a file
          count = 1;
          gNext = m.CreateNextGen(gCurr);
          string file;

          cout << "Please enter the name of the file: " << endl;
          cin >> file;
          cin.get();
          cout << endl;

           ofstream outfile(file);
           //outfile.open(file, ios::out | ios::trunc);

          cout << "Generations are writing to a file" << endl;

          gCurr->writeFile(outfile, 0);

          bool equalGrids = gCurr->isEqualTo(gNext);
          bool isEmpty = gNext->isEmpty();

          while ((!equalGrids) && (!isEmpty)){
            gNext->writeFile(outfile, count);
            gCurr = gNext;
            gNext = m.CreateNextGen(gCurr);
            count++;
            equalGrids = gCurr->isEqualTo(gNext);
            isEmpty = gNext->isEmpty();
          }

          cout << "Generations have stabilized/emptied" << endl;
          cout << "Please press enter to exit" << endl;
          cin.get();
          break;
        }else{
          cout << "Error! Incorrect choice! Please try again!" << endl;
        }
      }
      break;
    }else{
      cout << "Error! Incorrect choice! Please try again!" << endl;
    }
  }




// gCurr = new GameBoard(3, 3);
// gCurr->randomBoard(0.5);
// cout << "curr board" << endl;
// gCurr->printBoard();
//
// gNext = c.CreateNextGen(gCurr);
// cout << "next board" << endl;
// gNext->printBoard();
//
//
// gCurr->~GameBoard();
// gNext->~GameBoard();




  return 0;
}
