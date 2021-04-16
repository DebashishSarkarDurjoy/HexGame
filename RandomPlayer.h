#ifndef RANDOMPLAYER_H_
#define RANDOMPLAYER_H_


class RandomPlayer: public Player {
public:
	RandomPlayer(int t, string name = "Random") :
		Player(t, name) {}

		bool getMove(Board*, int&, int&);
};

bool RandomPlayer:: getMove(Board *board, int &x, int &y) {
		bool flag = false;

		int randCoorIndex = rand() % board->emptyCells.size();
		int randCoor;
		int randRow, randCol;
		randCoor = board->emptyCells[randCoorIndex];

		randCol = randCoor % 10;
		randRow = randCoor / 10;

		x = randRow - 1;
		y = randCol - 1;
		flag = board->validInput(x, y);
		if (flag == false)
			cout << "Invalid input! Please input again." << endl;

    board->emptyCells.erase(board->emptyCells.begin() + randCoorIndex);
		return true;
}

#endif
