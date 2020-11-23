#include "Chess.hpp"

void Chess::setupBoard() {
	this->board.resize(ROWS);//setup rows
	for (auto& r : this->board) {
		r.resize(COLS, new Empty());//setup cols (empty pieces/cells)
	}

	//setup 1,2 & 7,8 ranks with correct piece positions
	for (int c{}; c < COLS; ++c) {
		this->board[1][c] = new Pawn(0, 0, make_pair(1, c));//second_rank
	}
	for (int c{}; c < COLS; ++c) {
		this->board[6][c] = new Pawn(1, 0, make_pair(6, c));//seventh_rank
	}
	//this->board[2][3] = new Pawn(1, 0, make_pair(2, 0)); //debug
}



void Chess::printBoard() {
	for (int r = this->board.size() - 1; r >= 0; --r) {//reverse order so white is at the bottom
		for (auto& p : this->board[r]) {
			pair<int, int> info = p->getInfo();
			if (info.first == -1 and info.second == -1)
				cout << " xx";//empty cell displayed as 'xx' (prob change this)
			else 
				cout << " " << info.first << info.second;
		}
		cout << endl;
	}
}


