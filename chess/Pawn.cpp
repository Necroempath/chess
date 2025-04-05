#include "Pawn.h"
Pawn::Pawn(Position pos) : Figure(pos, 'P'), _first_move(1) {};

bool Pawn::move(Position pos)
{
	if (pos.x != _pos.x || pos.y - _pos.y > 1 + _first_move || pos.y < _pos.y) return 0;

	if (_first_move) _first_move--;

	_pos = pos;

	return 1;
}