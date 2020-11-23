#include "Piece.hpp"

void Pawn::calculateAvailableMoves(vector<vector<Piece*>>& b) {
	const auto& [r, c] = this->pos;

	vector<pair<int, int>> moves;

	//white
	if (int nr = r + 1, nc = c;
		(this->color == 0) &&
		(r < ROWS - 1) &&
		(b[nr][c]->getInfo().first == -1)    )
	{//if we are white, within bounds, and empty cell is ahead
		moves.push_back(make_pair(nr, c));//add to available moves
	}
	//black
	else if (int nr = r - 1, nc = c;
		(this->color == 1) &&
		(r > 0) &&
		(b[nr][c]->getInfo().first == -1))
	{//if we are white, within bounds, and empty cell is ahead
		moves.push_back(make_pair(nr, c));//add to available moves
	}

	//check diagnol captures for each color
	int nr = (!color ? (r + 1) : (r - 1));
	if (!color && nr < ROWS - 1
		|| color > 0) {//if we are white, is the move in bounds? same for black.
		if (int nc = c - 1; nc >= 0) {//left diagnol in bounds
			if (auto piece = b[nr][nc]->getInfo(); piece.first == !color &&
				piece.second != 5) {//some  piece (not king)
				moves.push_back(make_pair(nr, nc));//capture left diagnol
			}
		}
		if (int nc = c + 1; nc <= COLS - 1) {//right diagnol in bounds
			if (auto piece = b[nr][nc]->getInfo(); piece.first == !color &&
				piece.second != 5) {//some  piece (not king)
				moves.push_back(make_pair(nr, nc));//capture right diagnol
			}
		}
	}

	this->available_moves = moves;
}
