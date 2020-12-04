#pragma once
#include <vector>
#include <iostream>
#include "ruleset.hpp"
using namespace std;

class Piece {
protected:
	int color;
	int id;
	pair<int, int> pos;
	vector<pair<int, int>> available_moves;//all legal moves for a piece
public:
	Piece() : color(-1), id(-1) {}//empty cell (no piece)
	Piece(int _c, int _id, pair<int,int> _pos) : color(_c), id(_id),
											pos(_pos){}

	pair<int, int> getInfo() {
		return make_pair(this->color, this->id);
	}

	vector<pair<int, int>> getAvailableMoves() {
		return this->available_moves;
	}

	void setPos(pair<int, int> some_pos) {
		this->pos = some_pos;
	}

	pair<int, int> getPos() {
		return this->pos;
	}

	virtual void calculateAvailableMoves(vector<vector<Piece*>>& b) { return; }//each piece will have this
	void printAvailableMoves();
};

//Pieces

class Empty : public Piece {
private:
public:
	void calculateAvailableMoves() {
		cout << "defined" << endl;
	}
	using Piece::Piece;
};

class Pawn : public Piece {
private:
public:
	//implementation -> Pawn.cpp
	void calculateAvailableMoves(vector<vector<Piece*>>& b);
	using Piece::Piece;
};

class Knight : public Piece {
private:
public:
	//implementation -> Knight.cpp
	void calculateAvailableMoves(vector<vector<Piece*>>& b);

	using Piece::Piece;

};

class Bishop : public Piece {
private:
public:
	//implementation -> Bishop.cpp
	void calculateAvailableMoves(vector<vector<Piece*>>& b);

	using Piece::Piece;
	friend class Queen;
};

class Rook : public Piece {
private:
public:
	//implementation -> Rook.cpp
	void calculateAvailableMoves(vector<vector<Piece*>>& b);

	using Piece::Piece;
	friend class Queen;
};

class Queen : public Piece {
private:
public:
	//implementation -> Queen.cpp
	void calculateAvailableMoves(vector<vector<Piece*>>& b);

	using Piece::Piece;
};

class King : public Piece {
private:
public:
	//implementation -> King.cpp
	void calculateAvailableMoves(vector<vector<Piece*>>& b);

	using Piece::Piece;
};

//helpers (aux)
bool inCheck(int color, vector<vector<Piece*>>& b);
int isLegal(int color, int nr, int nc, vector<vector<Piece*>> b);

