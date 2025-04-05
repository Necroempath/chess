#pragma once
#include "Figure.h"

class Bishop : public Figure
{
public:
	Bishop(Position pos);

	bool move(Position pos) override;
};

