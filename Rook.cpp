#include "Piece.hpp"

void Rook::calculateAvailableMoves(vector<vector<Piece*>>& b) {
	const auto& [r, c] = this->pos;

	/*
		rook moves any cardinal direction as many times as it wants
		obstructed by same color or opposite color pieces (the latter allowing capture)
	*/
	vector<pair<int, int>> legal_moves;
	//check north
	for (int nr = r + 1; nr <= ROWS - 1; ++nr) {
		int legal = isLegal(this->color, nr, c, b);
		if (legal) {//if we can move there
			legal_moves.push_back(make_pair(nr, c));
			if (legal == 2 || legal == 1) break;//we captured or put king in check
		} else break;
	}
	//check south
	for (int nr = r - 1; nr >= 0; --nr) {
		int legal = isLegal(this->color, nr, c, b);
		if (legal) {//if we can move there
			legal_moves.push_back(make_pair(nr, c));
			if (legal == 2 || legal == 1) break;//capture or check
		}else break;
	}
	//check east
	for (int nc = c + 1; nc <= COLS - 1; ++nc) {
		int legal = isLegal(this->color, r, nc, b);
		if (legal) {
			legal_moves.push_back(make_pair(r, nc));
			if (legal == 2 || legal == 1) break;//capture or check
		}else break;
	}
	//check west
	for (int nc = c - 1; nc >= 0; --nc) {
		int legal = isLegal(this->color, r, nc, b);
		if (legal) {
			legal_moves.push_back(make_pair(r, nc));
			if (legal == 2 || legal == 1) break;//capture or check
		}else break;
	}
	this->available_moves = legal_moves;
}