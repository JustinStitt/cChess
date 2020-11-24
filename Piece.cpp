#include "Piece.hpp"

void Piece::printAvailableMoves() {
	cout << "pos: [" << this->pos.first <<
		"," << this->pos.second << "] " <<
		"color: " << (this->color == 0 ? "white" : "black") <<
		" id: " << this->id << endl;;
	for (auto& [r, c] : this->available_moves) {
		cout << "[" << r << "," << c << "]" << endl;
	}
}


//helpers (aux)
pair<bool, bool> isLegal(int color, int nr, int nc, vector<vector<Piece*>>& b) {
	/*
		can a piece of this color move to some cell [nr,nc]
		things to check:
		1) does a piece of our own color occupy that square
		2) Can we make this move without going into check (to-do)
		3) Is an enemy king (id = 5) on the cell, (we cant capture the king!)
	*/
	pair<int,int> info = b[nr][nc]->getInfo();
	int _c = info.first;
	int _id = info.second;
	if (color == _c) {//same color... cant move there!
		return make_pair(false, false);
	}
	else if (_id == 5) {//the piece is a king!
		return make_pair(false,false);
	}
	//to-do: are we in check as a result of this move?
	if (_id != -1)// was a capture!
		return make_pair(true, true);
	return make_pair(true, false);//we can move there! was not a capture though!
}