#pragma once
#include "Figure.h"

class Pawn : public Figure
{
	short _first_move;
public:
	Pawn(Position pos);

	bool move(Position pos) override;
};
