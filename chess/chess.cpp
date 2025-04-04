#include <iostream>
#include "Figure.h"
#include "King.h"
#include "Board.h"

enum Figures
{
	PAWN = 1,
	KNIGHT,
	BISHOP,
	ROOK,
	QUEEN,
	KING
};

void init_board(Figure figure)
{
	for (short i = 0; i < Board::row; i++)	for (short j = 0; j < Board::col; j++) Board::board[i][j] = ' ';

	Board::board[figure.get_pos().y][figure.get_pos().x] = figure.get_sign();
}

void print_board()
{
	std::cout << '\n';

	for (short i = Board::row; i > 0; i--)
	{
		std::cout << i << ' ';

		for (short j = 0; j < Board::col; j++)	std::cout << '[' << Board::board[i - 1][j] << ']';

		std::cout << '\n';
	}

	std::cout << "   ";

	for (char i = 97; i < 105; i++)	std::cout << i << "  ";
}

void print_figure_choice()
{
	std::cout << "Type digit for selecting corresponding chess figure:\n1 - pawn, 2 - knight, 3 - bishop, 4 - rook, 5 - queen, 6 or default - king";
}

int main()
{
	Position start_pos = { 1, 3 };
	short choice_option = 1;
	Figure* figure = nullptr;

	switch (choice_option)
	{
	case PAWN:
		figure = new King(start_pos);
		break;
	case KNIGHT:
		figure = new King(start_pos);
		break;
	case BISHOP:
		figure = new King(start_pos);
		break;
	case ROOK:
		figure = new King(start_pos);
		break;
	case QUEEN:
		figure = new King(start_pos);
		break;
	case KING:
		figure = new King(start_pos);
		break;
	default:
		break;
	}
	init_board(*figure);
	print_board();
	while (1)
	{
		Position new_pos;
		std::cout << "\nEnter new position (e.g e3, f7):\t";
		char sym;
		std::cin >> sym;
		
		std::cin >> new_pos.y;
		new_pos.x = sym - 97;
		new_pos.y--;
		switch (figure->move(new_pos))
		{
		case -2:
			std::cout << "Can not move to current position\n";
			break;
		case -1:
			std::cout << "Point out of chessboard area\n";
			break;
		case 0:
			std::cout << "Inaccessible point for selected figure\n";
			break;
		}
		print_board();
	}

	return 0;
}


