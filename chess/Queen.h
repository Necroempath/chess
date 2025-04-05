#pragma once
#include "Figure.h"

class Queen : public Figure
{
public:
	Queen(Position pos);

	bool move(Position pos) override;
};


