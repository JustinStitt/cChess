#include <iostream>
#include "Piece.hpp"
#include "Chess.hpp"

using namespace std;

int main()
{
	
	Chess game;
	game.setupBoard();
	game.printBoard();

	vector<vector<Piece*>> board = game.getBoard();

	Piece* some_piece = board[1][2];//second rank white pawn
	some_piece->calculateAvailableMoves(board);
	some_piece->printAvailableMoves();

	cin.get();
	return 0;
}