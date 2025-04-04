//#include "King.h"
//King::King(Position pos) : Figure(pos, 'K') {};
//
//short King::move(Position pos)
//{
//	if (pos.y < 0 || pos.y >= Board::row || pos.x < 0 || pos.y >= Board::col) return 0;
//	if (_pos.y == pos.y && _pos.x == pos.x) return -1;
//	if ((_pos.y - pos.y) > 1 || (_pos.y - pos.y) < -1 || (_pos.x - pos.x) > 1 || (_pos.x - pos.x) < -1) return -2;
//
//	Board::board[_pos.y][_pos.x] = ' ';
//	Board::board[pos.y][pos.y] = _sign;
//	return 1;
//}