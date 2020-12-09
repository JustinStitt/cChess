#include "Piece.hpp"

void Pawn::calculateAvailableMoves(vector<vector<Piece*>>& b) {
	const auto& [r, c] = this->pos;

	vector<pair<int, int>> moves;
	int dir = this->color == 0 ? 1 : -1;//if white dir is up, else down
	if (int nr = r + dir; isLegal(this->color, nr, c, b) == 3) {//valid move
		moves.push_back(make_pair(nr, c));
	}
	//check diagnol captures for each color
	int nr = r + dir;
	int nc = c - 1;
	int legal = isLegal(this->color, nr, nc, b);
	if (legal == 2 || legal == 1)//capture or check
		moves.push_back(make_pair(nr, nc));
	nc = c + 1; legal = isLegal(this->color, nr, nc, b);
	if (legal == 2 || legal == 1) {//capture or check
		moves.push_back(make_pair(nr, nc));
	}
	//double move from home row
	if (int ddir = dir * 2; (r == 1 && this->color == 0) ||
		(r == 6 && this->color)) {//2nd rank and white or 7th rank and black
		int legal = isLegal(this->color, r + ddir, c, b);
		if (legal == 3) {//empty cell
			moves.push_back(make_pair(r + ddir, c)); 
		}
	}
	this->available_moves = moves;
}
