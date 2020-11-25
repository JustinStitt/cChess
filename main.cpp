#include <iostream>
#include "Piece.hpp"
#include "Chess.hpp"

using namespace std;

int main()
{
	
	Chess game;
	game.setupBoard();
	game.printBoard();
	
	vector<vector<Piece*>> board = game.getBoard();//debug
	Piece* some_piece = board[2][4];//debug
	some_piece->calculateAvailableMoves(board);//debug
	some_piece->printAvailableMoves();//debug
	


	cin.get();
	return 0;
}