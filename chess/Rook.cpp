#include "Rook.h"
Rook::Rook(Position pos) : Figure(pos, 'R') {};

bool Rook::move(Position pos)
{
	if (pos.y != _pos.y && pos.x != _pos.x) return 0;

	_pos = pos;

	return 1;
}
