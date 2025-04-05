#include "Queen.h"
Queen::Queen(Position pos) : Figure(pos, 'Q') {};

bool Queen::move(Position pos)
{
	if (pos.y != _pos.y && pos.x != _pos.x && (abs(pos.y - _pos.y) != abs(pos.x - _pos.x))) return 0;

	_pos = pos;

	return 1;
}