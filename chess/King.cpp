#include "King.h"
King::King(Position pos) : Figure(pos, 'K') {};

bool King::move(Position pos)
{
	if ((_pos.y - pos.y) > 1 || (_pos.y - pos.y) < -1 || (_pos.x - pos.x) > 1 || (_pos.x - pos.x) < -1) return 0;

	_pos = pos;

	return 1;
}