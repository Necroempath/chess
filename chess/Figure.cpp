#include "Figure.h"

Figure::Figure(Position pos, char sign) : _pos(pos), _sign(sign) {};

char Figure::get_sign() const { return _sign; }

short Figure::move(Position pos)
{
	return 0;
}