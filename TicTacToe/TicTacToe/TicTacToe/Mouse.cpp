#include "Mouse.h"
// 895 width   518 height 

int getxPos()
{
	POINT p;
	if (GetCursorPos(&p))
	{
		return p.x;
	}
}

int getyPos()
{
	POINT p;
	if (GetCursorPos(&p))
	{
		return p.y;
	}
}

int getColIndex()
{
	int xpos = getxPos();
	if (xpos < 1050 / 3 + 450)
	{
		return 0;
	}
	else if (xpos > 1050 / 3 * 2 + 450)
	{
		return 2;
	}
	else
	{
		return 1;
	}
}

int getRowIndex()
{
	int ypos = getyPos();
	if (ypos < 650 / 3 + 200)
	{
		return 0;
	}
	else if (ypos > 650 / 3 * 2 + 200)
	{
		return 2;
	}
	else
	{
		return 1;
	}
}

static bool WithinX()
{
	return getxPos() > 450 && getxPos() < 1500;
}

static bool WithinY()
{
	return getyPos() > 200 && getyPos() < 850;
}

bool CheckValidity()
{
	return WithinX() && WithinY();
}


