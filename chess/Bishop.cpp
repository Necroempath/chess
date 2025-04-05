#include "Bishop.h"
Bishop::Bishop(Position pos) : Figure(pos, 'B') {};

bool Bishop::move(Position pos)
{
	if (abs(pos.y - _pos.y) != abs(pos.x - _pos.x)) return 0;

	_pos = pos;

	return 1;
	return 1;
}
