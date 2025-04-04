#pragma once
#include "Figure.h"
#include "Board.h"

class King : public Figure
{
public:
	King(Position pos);

	short move(Position pos) override;
};

