#include "Chess.hpp"

void Chess::setupBoard() {
	this->board.resize(ROWS);//setup rows
	for (auto& r : this->board) {
		r.resize(COLS, new Empty());//setup cols (empty pieces/cells)
	}

	//pawns
	for (int c{}; c < COLS; ++c) {
		this->board[1][c] = new Pawn(0, 0, make_pair(1, c));//second_rank
	}
	for (int c{}; c < COLS; ++c) {
		this->board[6][c] = new Pawn(1, 0, make_pair(6, c));//seventh_rank
	}
	//knights
	this->board[0][1] = new Knight(0, 1, make_pair(0, 1)); //white queen's knight
	this->board[0][6] = new Knight(0, 1, make_pair(0, 6)); //white king's knight
	this->board[7][1] = new Knight(1, 1, make_pair(7, 1)); //black queen's knight
	this->board[7][6] = new Knight(1, 1, make_pair(7, 6)); //black king's knight

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


