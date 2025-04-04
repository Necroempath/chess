#pragma once
#include "Board.h"

class Figure
{
protected:
	Position _pos;
	char _sign;

public:
	Figure(Position pos, char sign);
	char get_sign() const;

	virtual short move(Position pos);
};

