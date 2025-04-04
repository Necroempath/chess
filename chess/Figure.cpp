#include "Figure.h"

Figure::Figure(Position pos, char sign) : _pos(pos), _sign(sign) {};

char Figure::get_sign() const { return _sign; }

Position Figure::get_pos() const { return _pos; }

short Figure::move(Position pos)
{
	return 0;
}