#pragma once
#include "Figure.h"

class King : public Figure
{
public:
	King(Position pos);

	bool move(Position pos) override;
};

