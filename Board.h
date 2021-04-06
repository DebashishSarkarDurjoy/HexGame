/*
 * BaseBoard.h
 *
 *  Created on: 21/02/2021
 *      Author: dongmo
 */

#ifndef BOARD_H_
#define BOARD_H_

class Board {
private:
	int boardSize;
	int turn;
	int **grid;
public:
	Board(int bs) {
		boardSize = bs;
		grid = new int*[boardSize];
		for (int i = 0; i < boardSize; i++)
			grid[i] = new int[boardSize];

		for (int i = 0; i < boardSize; i++)
			for (int j = 0; j < boardSize; j++) {
				grid[i][j] = 0;
			}
		turn = 1;
	}

	virtual ~Board() {

		for (int i = 0; i < boardSize; i++)
			delete[] grid[i];

		delete[] grid;
	}

	Board(Board &cboard) {
		boardSize = cboard.getBoardSize();

		grid = new int*[boardSize];
		for (int i = 0; i < boardSize; i++)
			grid[i] = new int[boardSize];

		for (int i = 0; i < boardSize; i++)
			for (int j = 0; j < boardSize; j++)
				grid[i][j] = 0;

		for (int i = 0; i < boardSize; i++)
			for (int j = 0; j < boardSize; j++) {
				grid[i][j] = cboard.getGrid(i, j);
			}

		turn = cboard.getTurn();
	}

	int getBoardSize() {
		return boardSize;
	}

	int getGrid(int x, int y) {
		return grid[x][y];
	}

	int getTurn() {
		return turn;
	}

	bool validInput(int, int);

	bool isBoardFull();

	bool addMove(int playerType, int x, int y);

	bool checkWinningStatus(int playerType); //backtracking algo

	bool isSameMarker(int playerType, int tRow, int tCol);

	stack* checkNeighbors(int playerType, int x, int y);

	void printBoard();
};

bool Board::validInput(int x, int y) {
	if (x < 0 || y < 0 || x >= boardSize || y >= boardSize) {
		cout << "Move (" << x + 1 << ", " << y + 1 << ") out of range!" << endl;
		return false;
	}

	if (grid[x][y] != 0) {
		cout << "Invalid move. The cell has been occupied." << endl;
		return false;
	}

	return true;
}

bool Board:: isSameMarker(int playerType, int tRow, int tCol) {
	if (grid[tRow][tCol] == playerType) return true;
	else return false;
}

bool Board:: isBoardFull() {
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			if (grid[i][j] == 0) return false;
		}
	}

	cout << "\nThe board is full!\n" << endl;
	return true;
}

bool Board::addMove(int playerType, int x, int y) {

	if (playerType != turn) {
		cout << "It is not the player's turn!" << endl;
		return false;
	}

	if (grid[x][y] != 0) {
		cout << "Invalid move. The cell has been occupied." << endl;
		return false;
	}

	grid[x][y] = playerType;

	turn = -1 * turn;
	return true;
}

void Board::printBoard() {
	cout << "   ";
	for (int j = 0; j < boardSize; j++) {
		if (j < 9)
			cout << j + 1 << "   ";
		else
			cout << j + 1 << "  ";
	}
	cout << endl;

	cout << "   ";
	for (int j = 0; j < boardSize; j++) {
		cout << "----";
	}
	cout << endl;

	for (int i = 0; i < boardSize; i++) {
		for (int k = 0; k < i; k++)
			cout << "  ";

		if (i < 9)
			cout << " " << i + 1 << " ";
		else
			cout << i + 1 << " ";

		for (int j = 0; j < boardSize; j++) {
			if (grid[i][j] == 0) {
				if (j == 0) {
					cout << "|   |";
				} else {
					cout << "   |";
				}
			} else if (grid[i][j] == 1) {
				if (j == 0) {
					cout << "| R |";
				} else {
					cout << " R |";
				}
			} else {
				if (j == 0) {
					cout << "| B |";
				} else {
					cout << " B |";
				}
			}
		}
		cout << endl;
	}

	for (int k = 0; k <= boardSize; k++)
		cout << "  ";

	for (int j = 0; j < boardSize; j++) {
		cout << "----";
	}

	cout << endl;
	cout << endl;
}

stack* Board:: checkNeighbors(int playerType, int x, int y) {
	stack* neighbors = new stack();
	int centerRow, centerCol, coor;
	int row = boardSize;
	int col = boardSize;
	int player = playerType;
	centerRow = x;
	centerCol = y;


	// up
	if ( (centerRow - 1) >= 0  ) {
		if (isSameMarker(player, centerRow - 1, centerCol)) {
			coor = ( (centerRow ) * 10) + (centerCol +1);
			neighbors->insertNode(coor);
		}
		//up_left
		if ( ((centerCol - 1) >= 0) && isSameMarker(player, centerRow - 1, centerCol - 1) ) {
			coor = ( (centerRow ) * 10) + (centerCol );
			neighbors->insertNode(coor);
		}
		//up_right
		if ( ((centerCol + 1) < col) && isSameMarker(player, centerRow - 1, centerCol + 1) ) {
			coor = ( (centerRow ) * 10) + (centerCol + 1 +1);
			neighbors->insertNode(coor);
		}
	}

	//down
	if ( (((centerRow + 1) < row) ) ) {
		if (isSameMarker(player, centerRow + 1, centerCol)) {
			coor = ( (centerRow + 1 +1) * 10) + (centerCol +1);
			neighbors->insertNode(coor);
		}
		//down_left
		if ( ((centerCol - 1) >= 0) && isSameMarker(player, centerRow + 1, centerCol - 1))  {
			coor = ( (centerRow + 1 + 1) * 10) + (centerCol -1 +1);
			neighbors->insertNode(coor);
		}
		//down_right
		if ( ((centerCol + 1) < col) && isSameMarker(player, centerRow + 1, centerCol + 1) )  {
			coor = ( (centerRow + 1 +1) * 10) + (centerCol + 1 +1);
			neighbors->insertNode(coor);
		}
	}

	//left
	if ( (centerCol - 1) >= 0 && isSameMarker(player, centerRow, centerCol - 1) ) {
		coor = ( (centerRow + 1) * 10) + (centerCol);
		neighbors->insertNode(coor);
	}
	//right
	if ( (centerCol + 1) < col && isSameMarker(player, centerRow, centerCol + 1) ) {
		coor = ( (centerRow + 1) * 10) + (centerCol + 1 + 1);
		neighbors->insertNode(coor);
	}

	int tRow, tCol;
	char playerChar;
	if (playerType == -1) playerChar = 'B';
	else playerChar = 'R';

	if (neighbors->isStackEmpty()) cout << "No neighbors of [" << playerChar << "] " << "(" << x+1 << "," << y+1 << ") : " << endl;
	else {
		cout << "All neighbors of [" << playerChar << "] " << "(" << x+1 << "," << y+1 << ") : ";
		while (!neighbors->isStackEmpty()) {
			coor = neighbors->pop();
			tCol = coor % 10;
			tRow = coor / 10;
			cout << "(" << tRow << ", " << tCol << ")  ";
		}
		cout << endl;
	}

	return neighbors;
}

bool Board:: checkWinningStatus(int playerType) {
	int winningPosition = 0;
	int rowR = -1, colB = -1;
	int coor;
	int tRow, tCol;
	int R = 1, B = -1;

	if (playerType == -1) { // -1 is B
		colB = boardSize - 1;
		//look for B at Right-End
		vector<int> rightBs;
		for (int i = 0; i < boardSize; i++) {
			if (grid[i][colB] == B) {
				coor = ((i + 1) * 10) + (colB + 1);
				rightBs.push_back(coor);
			}
		}
		cout << "All Right Bs: ";
		for(int i = 0; i < rightBs.size(); i++) {
			cout << rightBs[i] << "\t";
		}
		cout << endl;


		// stack* currentNeighbors;
		// stack* trace = new stack();
		// while(rightBs.size() != 0) {
		// 	coor = rightBs.at(rightBs.size() - 1);
		// 	tRow = coor / 10;
		// 	tCol = coor % 10;
		//
		// 	currentNeighbors = checkNeighbors(playerType, tRow, tCol);
		// 	for (int i = 0; i < currentNeighbors->size(); i++)
		// 						trace->insertNode(coor);
		//
		// 	for (int i = 0; i < trace->size(); i++) {
		// 		cout << trace->pop() << endl;
		// 	}
		// }
	}
	else {
		rowR = boardSize - 1; // 1 is R
		//look for R at bottom
		vector<int> bottomRs;
		for (int i = 0; i < boardSize; i++) {
			if (grid[rowR][i] == R) {
				coor = ((rowR + 1) * 10) + (i + 1);
				bottomRs.push_back(coor);
			}
		}
		cout << "All bottom Rs: ";
		for(int i = 0; i < bottomRs.size(); i++) {
			cout << bottomRs[i] << "\t";
		}
		cout << endl;
	}

	return false;
}

#endif /* BOARD_H_ */
