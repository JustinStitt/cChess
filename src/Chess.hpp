#pragma once
#include <vector>
#include <iostream>
#include "pieces/Piece.hpp"
#include "ruleset.hpp"

using namespace std;

class Chess {
private:
	vector<vector<Piece*>> board;
	int current_player;//0 = white, 1 = black;
public:
	Chess() = default;//default constructor

	void setupBoard();//setup the board with vanilla chess layout

	vector<vector<Piece*>> getBoard() { return this->board; }
	void printBoard();//display the board through std i/o
	
	void startGame();

	void nextTurn();//cycles player's turn
	void prompt();

};