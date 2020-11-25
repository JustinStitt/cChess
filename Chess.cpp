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
	//bishops
	this->board[0][2] = new Bishop(0, 2, make_pair(0, 2));//white queen's bishop
	this->board[0][5] = new Bishop(0, 2, make_pair(0, 5));//white kings's bishop
	this->board[7][2] = new Bishop(1, 2, make_pair(7, 2));//black queen's bishop
	this->board[7][5] = new Bishop(1, 2, make_pair(7, 5));//black kings's bishop
	//rooks
	this->board[0][0] = new Rook(0, 3, make_pair(0, 0));//white queen's rook
	this->board[0][7] = new Rook(0, 3, make_pair(0, 7));//white king's rook
	this->board[7][0] = new Rook(1, 3, make_pair(7, 0));//black queen's rook
	this->board[7][7] = new Rook(1, 3, make_pair(7, 7));//black king's rook

	

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


