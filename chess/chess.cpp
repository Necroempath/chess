#include <iostream>
//#include "Figure.h"
//#include "King.h"
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

void init_board(short y = 0, short x = 0, char sign = ' ')
{
	for (short i = 0; i < Board::row; i++)	for (short j = 0; j < Board::col; j++) Board::board[i][j] = ' ';

	Board::board[y][x] = sign;
}

void print_board()
{
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
	/*short choice_option;
	Figure figure(6, 4, ' ');
	switch (choice_option)
	{
	case PAWN:
		figure = King(6, 4);
		break;
	case KNIGHT:
		figure = King(6, 4);
		break;
	case BISHOP:
		figure = King(6, 4);
		break;
	case ROOK:
		figure = King(6, 4);
		break;
	case QUEEN:
		figure = King(6, 4);
		break;
	case KING:
		figure = King(6, 4);
		break;
	default:
		break;
	}*/
	init_board();
	print_board();
	return 0;
}


