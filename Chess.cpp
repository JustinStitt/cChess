#include "Chess.hpp"

pair<int, int> parseInput(char&, char&);//aux helper

void Chess::setupBoard() {
	this->board.resize(ROWS);//setup rows
	for (auto& r : this->board) {
		r.resize(COLS);
		for (auto& c : r) {
			c = new Empty();
		}
	}

	//pawns
	for (int c{}; c < COLS; ++c) {
		this->board[1][c] = new Pawn(0, 0, make_pair(1, c));//second_rank
	}
	for (int c{}; c < COLS; ++c) {
		this->board[6][c] = new Pawn(1, 0, make_pair(6, c));//seventh_rank
	}
	//knights
	this->board[0][1] = new Knight(0, 1, make_pair(0, 1)); //white queen's knight
	this->board[0][6] = new Knight(0, 1, make_pair(0, 6)); //white king's knight
	this->board[7][1] = new Knight(1, 1, make_pair(7, 1)); //black queen's knight
	this->board[7][6] = new Knight(1, 1, make_pair(7, 6)); //black king's knight
	//bishops
	this->board[0][2] = new Bishop(0, 2, make_pair(0, 2));//white queen's bishop
	this->board[0][5] = new Bishop(0, 2, make_pair(0, 5));//white kings's bishop
	this->board[7][2] = new Bishop(1, 2, make_pair(7, 2));//black queen's bishop
	this->board[7][5] = new Bishop(1, 2, make_pair(7, 5));//black kings's bishop
	//rooks
	this->board[0][0] = new Rook(0, 3, make_pair(0, 0));//white queen's rook
	this->board[0][7] = new Rook(0, 3, make_pair(0, 7));//white king's rook
	this->board[7][0] = new Rook(1, 3, make_pair(7, 0));//black queen's rook
	this->board[7][7] = new Rook(1, 3, make_pair(7, 7));//black king's rook
	//queens
	this->board[0][3] = new Queen(0, 4, make_pair(0, 3));//white queen
	this->board[7][3] = new Queen(1, 4, make_pair(7, 3));//black queen
	//kings
	this->board[0][4] = new King(0, 5, make_pair(0, 4));//white king
	this->board[7][4] = new King(1, 5, make_pair(0, 4));//black king


}

void Chess::startGame() {
	this->current_player = 0;//starts with player 0 (white)
	//setup the board
	this->setupBoard();
	//prompt user for their move
	while(true)
	this->prompt();
}

void Chess::prompt() {
	system("CLS");//clears the console (on windows)
	//first step is to print the board
	this->printBoard();
	cout << "Player: " << (this->current_player == 0 ? "White" : "Black") << endl;
	cout << "select piece to move [A-H][1-8]: ";
	char col, row;
	auto [r,c] = parseInput(col, row);
	if (r < 0 || r > ROWS - 1 || c < 0 || c > COLS - 1) {
		this->prompt();
		return;
	}
	Piece* chosen = this->board[r][c];
	if (chosen->getInfo().first != this->current_player) {
		this->prompt();
		return;
	}
	//now show available moves for this piece
	chosen->calculateAvailableMoves(this->board);
	vector<pair<int, int>> moveset = chosen->getAvailableMoves();
	if (moveset.empty()) {
		this->prompt();
		return;
	}
	cout << "availble moves: { ";
	for (auto& [r, c] : moveset) {
		char row = r + '1';
		char col = c + 65;
		cout << col << row << " ";
	}cout << "} for piece at " << col << row << endl;

	//now ask user to select a move to make then execute the move
	
	//make sure selected move is within moveset of the piece
	auto f = moveset.begin();//f is an iterator to pair<int,int> in moveset
	int cr, cc;
	do {
		cout << "select move: ";
		tie(cr,cc) = parseInput(col, row);
		f = find(moveset.begin(), moveset.end(), make_pair(cr, cc));//validate move
	}while(f == moveset.end());

	chosen->setPos(make_pair(cr, cc));
	//to-do input validation here
	//move chosen piece to chosen position (r,c)
	delete board[cr][cc];
	board[cr][cc] = chosen;//now set to chosen piece
	board[r][c] = new Empty();//board[r][c] is now empty
	
	this->nextTurn();
}
//aux helper
pair<int,int> parseInput(char& c, char& r) {
	cin >> c >> r;
	//find the piece
	int row = (r - '0') - 1;//0-based
	int col = toupper(c) - 'A';
	return make_pair(row, col);
}

void Chess::nextTurn() {
	this->current_player = !current_player;//toggles between 0 and 1
}


void Chess::printBoard() {
	char black = 178;
	char white = 176;
	char background = black;
	for (int r = this->board.size() - 1; r >= 0; --r) {//reverse order so white is at the bottom
		for (auto& p : this->board[r]) {				
			pair<int, int> info = p->getInfo();
			if (info.first == -1 and info.second == -1)
				cout << "  " << background;//empty cell displayed as 'xx' (prob change this)
			else 
				cout << " " << info.first << info.second;
			background = (background == white ? black : white);
		}
		background = (background == white ? black : white);
		cout << char(179) << " " << r+1 << endl;
	}
	cout << string(COLS * 3, char(196)) << endl << " ";
	for (int x{}; x < COLS; ++x) {
		char p = 65 + x;
		cout << p << "  ";
	} cout << endl << endl;
}


