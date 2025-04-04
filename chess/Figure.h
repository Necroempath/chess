#pragma once
#include "Board.h"

class Figure
{
protected:
	Position _pos;
	char _sign;

public:
	Figure();

	Figure(Position pos, char sign);

	Position get_pos() const;

	char get_sign() const;

	virtual short move(Position pos);
};

