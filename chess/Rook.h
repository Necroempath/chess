#pragma once
#include "Figure.h"

class Rook : public Figure
{
public:
	Rook(Position pos);

	bool move(Position pos) override;
};


