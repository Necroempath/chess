#pragma once
#include <iostream>
#include "Figure.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"

enum FigureType {
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
	FigureType _type;

	const short figure_select() const;

	void init_figure(const Position& current_pos);

	void init_new_pos(Position& new_pos);

	short move_figure(const Position& new_pos, const Position& current_pos);
	
	void print_msg(short msg_code);

	void pawn_ascension(const Position& new_pos);

	void print_board() const;

public:
	Game();

	void start_game();

	~Game();
};

