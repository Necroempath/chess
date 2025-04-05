#pragma once
#include <iostream>
#include "Figure.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"

enum Figures
{
	PAWN = 1,
	KNIGHT,
	BISHOP,
	ROOK,
	QUEEN,
	KING
};

class Game
{
	short _row, _col;
	char _board[8][8];
	Figure* _figure;

	void init_board(Figure* figure);

	const short figure_select() const;

public:
	Game();

	void start_game();

	void print_board() const;
};

