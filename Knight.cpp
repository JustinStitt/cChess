#include "Piece.hpp"

void Knight::calculateAvailableMoves(vector<vector<Piece*>>& b) {
	/*
		Knight movement
		1 or 2 in a cardinal direction
		then 2 or 1 in adjacent cardinal direction 
		---
		[2N,1E], [2E,1N]
		[2S,1E], [2E,1S]
		[2N,1W], [2W,1N]
		[2S,1W], [2W,1S]
	*/
	const auto& [r, c] = this->pos;

	vector<pair<int, int>> knight_moves = {
		make_pair(r + 2, c + 1), make_pair(r + 1, c + 2),
		make_pair(r - 2, c + 1), make_pair(r - 1, c + 2),
		make_pair(r + 2, c - 1), make_pair(r + 1, c - 2),
		make_pair(r - 2, c - 1), make_pair(r - 1, c - 2)
	};
	//now check which of these moves are legal
	vector<pair<int, int>> legal_moves;

	for (auto& [nr, nc] : knight_moves) {
		if ((nr > ROWS - 1) || (nr < 0) || (nc > COLS - 1) || (nc < 0)) continue;//do not add
		if (!isLegal(this->color, nr, nc, b).first) continue;
		legal_moves.push_back(make_pair(nr, nc));
	}
	this->available_moves = legal_moves;
}