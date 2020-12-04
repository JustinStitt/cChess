#include "Piece.hpp"

void Queen::calculateAvailableMoves(vector<vector<Piece*>>& b) {
	const auto& [r, c] = this->pos;
	/*
		a queen is a portmanteau of bishop and rook moves.
		create dummy bishop and dummy rook and combine legal moves
	*/
	//allocate on heap
	Bishop* dummy_bishop = new Bishop(this->color, 2, this->pos); 
	dummy_bishop->calculateAvailableMoves(b);
	Rook* dummy_rook = new Rook(this->color, 3, this->pos); 
	dummy_rook->calculateAvailableMoves(b);

	vector<pair<int, int>> legal_moves = dummy_bishop->available_moves;
	for (auto move : dummy_rook->available_moves) {
		legal_moves.push_back(move);
	}
	this->available_moves = legal_moves;
	delete dummy_bishop;
	delete dummy_rook;
}