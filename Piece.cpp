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
bool inCheck(int color, vector<vector<Piece*>>& b) {
	/*
		determine if the king of 'color' is under attack (in check)
	*/
	//loop through all of our oponents pieces and check if the position our king is at
	//is one of the available moves
	pair<int, int> king_pos;
	for (auto& r : b) {
		for (auto& p : r) {
			auto [c, id] = p->getInfo();
			if (c == color and id == 5) {//our king
				king_pos = p->getPos();
				goto endloop;
			}
		}
	}
	endloop:
	int opp = !color;
	for (auto& r : b) {
		for (auto& piece : r) {
			if (piece->getInfo().first == opp) {//opponent color
				piece->calculateAvailableMoves(b);
				//if (piece->getAvailableMoves().size() < 1) continue;
				for (auto& move : piece->getAvailableMoves()) {
					if (move.first == king_pos.first && move.second == king_pos.second) {
						//attacking our king!
						return true;
					}
				}
			}
		}
	}
	return false;
}

int isLegal(int color, int nr, int nc, vector<vector<Piece*>> b) {
	/*
		can a piece of this color move to some cell [nr,nc]
		things to check:
		1) does a piece of our own color occupy that square
		2) Can we make this move without going into check (to-do)
		3) Is an enemy king (id = 5) on the cell, (we cant capture the king!)

		1) if piece of same color occupies the cell, or out of bounds return 0 
		2) if the piece is a king return 1
		3) captured an enemy piece return 2
		4) moved to empty cell retur 3
	*/
	if (nr < 0 || nr > ROWS - 1 || nc < 0 || nc > COLS - 1) {
		return 0;
	}
	pair<int,int> info = b[nr][nc]->getInfo();
	int _c = info.first;
	int _id = info.second;
	if (color == _c) {//same color... cant move there!
		return 0;
	}
	else if (_id == 5) {//the piece is a king!
		return 1;
	}
	if (_id != -1)// was a capture!
		return 2;
	return 3;//we can move there! was not a capture though!
}

