#include "Piece.hpp"

void Bishop::calculateAvailableMoves(vector<vector<Piece*>>& b) {
	const auto& [r, c] = this->pos;
	/*
		bishop can move diagnolly on its own color
	*/
	vector<pair<int, int>> legal_moves;
	//check north-east diagnol
	for (int nr = r + 1, nc = c + 1; (nr <= ROWS - 1) 
		and (nc <= COLS - 1); ++nr, ++nc) {
		int legal = isLegal(this->color, nr, nc, b);
		if (legal) {
			legal_moves.push_back(make_pair(nr, nc));
			if (legal == 2 || legal == 1) break;//we captured, or check
		}
		else { break; }//if some cell is not legal, subsequent cells cannot possibly be legal
	}
	//check north-west diagnol
	for (int nr = r + 1, nc = c - 1; (nr <= ROWS - 1)
		and (nc >= 0); ++nr, --nc) {
		int legal = isLegal(this->color, nr, nc, b);
		if (legal) {
			legal_moves.push_back(make_pair(nr, nc));
			if (legal == 2 || legal == 1) break;//we captured, or check
		}
		else break;
	}
	//check south-east diagnol
	for (int nr = r - 1, nc = c + 1; (nr >= 0)
		and (nc <= COLS - 1); --nr, ++nc) {
		int legal = isLegal(this->color, nr, nc, b);
		if (legal) {
			legal_moves.push_back(make_pair(nr, nc));
			if (legal == 2) break;//we captured!
		}
		else break;
	}
	//check south-west diagnol
	for (int nr = r - 1, nc = c - 1; (nr >= 0)
		and (nc >= 0); --nr, --nc) {
		int legal = isLegal(this->color, nr, nc, b);
		if (legal) {
			legal_moves.push_back(make_pair(nr, nc));
			if (legal == 2) break;//we captured
		}
		else break;
	}
	this->available_moves = legal_moves;
}