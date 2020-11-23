#pragma once
#include <vector>
#include <iostream>
#include "Piece.hpp"
#include "ruleset.hpp"

using namespace std;

class Chess {
private:
	vector<vector<Piece*>> board;
public:
	Chess() = default;//default constructor

	void setupBoard();//setup the board with vanilla chess layout

	vector<vector<Piece*>> getBoard() { return this->board; }
	void printBoard();//display the board through std i/o

};