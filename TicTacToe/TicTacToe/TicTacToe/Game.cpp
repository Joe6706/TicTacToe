#include "Game.h"
#include "Graphics.h"
#define INDEX_TO_Y_COOR(xRow) 0.8f - (2.0f/3.0f * xRow)
#define INDEX_TO_X_COOR(xCol) -0.8f + (2.0f/3.0f * xCol) 
#define INDEX_TO_Y_CENTER(oRow) 0.66f - (2.0f/3.0f * oRow)
#define INDEX_TO_X_CENTER(oCol) -0.66f + (2.0f/3.0f * oCol)



int m_arr[3][3] = {};
int turn = 1;

void endGame()
{
	memset(m_arr, 0, sizeof(m_arr));
	turn = 1;
}



void play(int row, int col)
{
	if (!checkValidLocation(row, col))
	{
		turn--;
		return; // stops method from proceeding due to invalid location
	}


	// 1 represents x and 2 represents o
	if (turn % 2 == 1)
	{
		m_arr[row][col] = 1;
	}
	else
	{
		m_arr[row][col] = 2;
	}


}

void CheckEnding()
{
	if (checkRows() || checkCols() || checkDiag())
	{
		if (turn % 2 == 1)
		{
			std::cout << "Game Finished, Player 1 wins" << std::endl;
		}
		else
		{
			std::cout << "Game Finished, Player 2 wins" << std::endl;
		}
		endGame();
		return;
	}
	turn++;
	if (turn == 10) // terminates Game if there are no more spots on the board
	{
		std::cout << "Draw" << std::endl;
		endGame();
		return;
	}
}


bool checkRows()
{
	for (int i = 0; i < 3; i++)
	{
		if (m_arr[i][0] != 0 && m_arr[i][0] == m_arr[i][1] && m_arr[i][1] == m_arr[i][2])
		{
			return true;
		}
	}
	return false;
}

bool checkCols()
{
	for (int i = 0; i < 3; i++)
	{
		if (m_arr[0][i] != 0 && m_arr[0][i] == m_arr[1][i] && m_arr[1][i] == m_arr[2][i])
		{
			return true;
		}
	}
	return false;
}

bool checkDiag()
{
	if (m_arr[0][0] != 0 && m_arr[0][0] == m_arr[1][1] && m_arr[1][1] == m_arr[2][2])
	{
		return true;
	}
	else if (m_arr[0][2] != 0 && m_arr[0][2] == m_arr[1][1] && m_arr[1][1] == m_arr[2][0])
	{
		return true;
	}
	return false;
}

bool checkValidLocation(int rows, int cols)
{
	return m_arr[rows][cols] == 0;
}

void drawBoard()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (m_arr[i][j] == 1)
			{
				drawX(INDEX_TO_X_COOR(j), INDEX_TO_Y_COOR(i));
			}
			else if (m_arr[i][j] == 2)
			{
				drawO(INDEX_TO_X_CENTER(j), INDEX_TO_Y_CENTER(i), 0.2f, 360);
			}
		}
	}
}

