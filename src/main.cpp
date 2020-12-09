#include <iostream>
#include "pieces/Piece.hpp"
#include "Chess.hpp"

using namespace std;

int main()
{
	
	Chess game;
	game.startGame();
	cin.ignore();
	cin.get();
	return 0;
}