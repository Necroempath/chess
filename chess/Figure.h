#pragma once

struct Position
{
	short y, x;
};

class Figure
{
protected:
	Position _pos;
	char _sign;

public:
	Figure(Position pos, char sign);

	Position get_pos() const;

	char get_sign() const;

	virtual bool move(Position pos) = 0;
};

short abs(short value);
