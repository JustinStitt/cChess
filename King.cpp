#include "Piece.hpp"

void King::calculateAvailableMoves(vector<vector<Piece*>>& b) {
	const auto& [r, c] = this->pos;
	/*
		king can move 1 cell in any cardinal direction or diagnol
		can capture oppositely colored pieces (not other king)
	*/
	//all possible moves
	vector<pair<int, int>> moves = {
		make_pair(r + 1, c), make_pair(r - 1, c),
		make_pair(r, c + 1), make_pair(r, c - 1), 
		make_pair(r + 1, c + 1), make_pair(r + 1, c - 1), 
		make_pair(r - 1, c + 1), make_pair(r - 1, c - 1)
	};
	//find legal moves
	vector<pair<int, int>> legal_moves;
	for (auto&[nr,nc] : moves) {

		if ((nr > ROWS - 1) || (nr < 0) ||
			(nc > COLS - 1) || (nc < 0)) continue;
		pair<bool, bool> legal = isLegal(this->color, nr, nc, b);
		if (!legal.first) continue;
		legal_moves.push_back(make_pair(nr, nc));
	}
	this->available_moves = legal_moves;
}