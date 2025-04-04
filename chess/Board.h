#pragma once
struct Position
{
	short y, x;
};

struct Board
{
	static const short row = 8, col = 8;
	static char board[row][col];
};
