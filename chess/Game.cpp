#include "Game.h"
void Game::init_board(Figure* figure)
{
	for (short i = 0; i < _row; i++)	for (short j = 0; j < _col; j++) _board[i][j] = ' ';

	_board[figure->get_pos().y][figure->get_pos().x] = figure->get_sign();
}

const short Game::figure_select() const
{
	short option;
	std::cout << "Type digit for selecting corresponding chess figure:\n1 - pawn, 2 - knight, 3 - bishop, 4 - rook, 5 - queen, 6 or default - king\n";
	std::cin >> option;
	return option;
}

Game::Game() : _figure(nullptr), _row(8), _col(8) {};

void Game::start_game()
{
	Position start_pos = { 1, 3 };
	Position current_pos;
	Position new_pos;

	switch (figure_select())
	{
	case PAWN:
		_figure = new Pawn(start_pos);
		break;
	case KNIGHT:
		_figure = new Knight(start_pos);
		break;
	case BISHOP:
		_figure = new Bishop(start_pos);
		break;
	case ROOK:
		_figure = new Rook(start_pos);
		break;
	case QUEEN:
		_figure = new Queen(start_pos);
		break;
	default:
		_figure = new King(start_pos);
		break;
	}

	init_board(_figure);

	while (1)
	{
		print_board();
		current_pos = _figure->get_pos();

		std::cout << "\n\nEnter new position (e.g e3, f7):\t";
		char sym;
		std::cin >> sym;

		std::cin >> new_pos.y;
		new_pos.x = sym - 97;
		new_pos.y -= 1;

		if (new_pos.y >= _row || new_pos.y < 0 || new_pos.x >= _col || new_pos.x < 0) {
			std::cout << "\nPosition out of chessboard area\n";
		}
		else if (new_pos.y == current_pos.y && new_pos.x == current_pos.x) {
			std::cout << "\nCan not move to current position\n";
		}
		else if (!_figure->move(new_pos)) {
			std::cout << "\nInaccessible position for given figure\n";
		}
		else {
			_board[current_pos.y][current_pos.x] = ' ';
			_board[new_pos.y][new_pos.x] = _figure->get_sign();
			if (_figure->get_sign() == 'P' && new_pos.y == _row - 1)
			{
				_figure = new Queen(new_pos);
				_board[new_pos.y][new_pos.x] = 'Q';
			}

		}
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