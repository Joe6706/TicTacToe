#pragma once

#include <iostream>
void endGame();
void play(int row, int col);
bool checkRows();
bool checkCols();
bool checkDiag();
bool checkValidLocation(int rows, int cols);
bool checkWin();
void drawBoard();
void CheckEnding();



