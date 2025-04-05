#pragma once
#include "Figure.h"

class Knight : public Figure
{
public:
	Knight(Position pos);

	bool move(Position pos) override;
};
