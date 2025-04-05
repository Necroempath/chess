#include "Knight.h"
Knight::Knight(Position pos) : Figure(pos, 'N') {};

bool Knight::move(Position pos)
{
	if (abs(pos.y - _pos.y) + abs(pos.x - _pos.x) != 3 || pos.y == _pos.y || pos.x == _pos.x) return 0;

	_pos = pos;

	return 1;
}