#include "Game.h"

const short Game::figure_select() const
{
	short option;
	std::cout << "Type digit for selecting corresponding chess figure:\n1 - pawn, 2 - knight, 3 - bishop, 4 - rook, 5 - queen, 6 or default - king\n";
	std::cin >> option;
	return option;
}

void Game::init_figure(const Position& current_pos)
{
	switch (figure_select())
	{
	case PAWN:
		_figure = new Pawn(current_pos);
		_type = PAWN;
		break;
	case KNIGHT:
		_figure = new Knight(current_pos);
		_type = KNIGHT;
		break;
	case BISHOP:
		_figure = new Bishop(current_pos);
		_type = BISHOP;
		break;
	case ROOK:
		_figure = new Rook(current_pos);
		_type = ROOK;
		break;
	case QUEEN:
		_figure = new Queen(current_pos);
		_type = QUEEN;
		break;
	default:
		_figure = new King(current_pos);
		_type = KING;
		break;
	}
}

void Game::init_new_pos(Position& new_pos)
{
	std::cout << "\n\nEnter new position (e.g e3, f7):\t";
	char sym;
	std::cin >> sym;

	std::cin >> new_pos.y;
	new_pos.x = sym - 97;
	new_pos.y -= 1;
}

short Game::move_figure(const Position& new_pos, const Position& current_pos)
{
	if (new_pos.y >= _row || new_pos.y < 0 || new_pos.x >= _col || new_pos.x < 0) {
		return -2;
	}
	else if (new_pos.y == current_pos.y && new_pos.x == current_pos.x) {
		return -1;
	}
	else if (!_figure->move(new_pos)) {
		return 0;
	}
	else {
		_board[current_pos.y][current_pos.x] = ' ';
		_board[new_pos.y][new_pos.x] = _figure->get_sign();

		return 1;
	}
}

void Game::print_msg(short msg_code)
{
	switch (msg_code) 
	{
	case -2:
		std::cout << "\nPosition out of chessboard area\n";
		break;
	case -1:
		std::cout << "\nCan not move to current position\n";
		break;
	case 0:
		std::cout << "\nInaccessible position for given figure\n";
		break;
	}
}

void Game::pawn_ascension(const Position& new_pos)
{
	if (new_pos.y == _row - 1)
	{
		delete _figure;
		_figure = new Queen(new_pos);
		_type = QUEEN;
		_board[new_pos.y][new_pos.x] = 'Q';
	}
}

void Game::print_board() const
{
	std::cout << '\n';

	for (short i = _row; i > 0; i--)
	{
		std::cout << i << ' ';

		for (short j = 0; j < _col; j++)	std::cout << '[' << _board[i - 1][j] << ']';

		std::cout << '\n';
	}

	std::cout << "   ";

	for (char i = 97; i < 97 + _col; i++)	std::cout << i << "  ";
}

Game::Game() : _figure(nullptr), _row(8), _col(8) 
{
	for (short i = 0; i < _row; i++)
	{
		for (short j = 0; j < _col; j++) _board[i][j] = ' ';
	}
};

void Game::start_game()
{
	Position current_pos = { 1, 3 };
	Position new_pos;

	init_figure(current_pos);

	_board[_figure->get_pos().y][_figure->get_pos().x] = _figure->get_sign();

	while (true)
	{
		print_board();
		current_pos = _figure->get_pos();

		init_new_pos(new_pos);

		print_msg(move_figure(new_pos, current_pos));

		if (_type == PAWN) pawn_ascension(new_pos);
		{
			pawn_ascension(new_pos);
		}
	}
}

Game::~Game() 
{
	delete _figure;
}