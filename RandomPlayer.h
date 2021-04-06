#ifndef RANDOMPLAYER_H_
#define RANDOMPLAYER_H_

using namespace std;

class RandomPlayer: public Player {
public:
	RandomPlayer(int t, string name = "Random") :
		Player(t, name) {}

		bool getMove(Board*, int&, int&);
};

bool RandomPlayer:: getMove(Board *board, int &x, int &y) {
		bool flag = false;
		vector <int> emptyCells;
		int max = board->getBoardSize();
		for (int i = 0; i < max; i++) {
			for (int j = 0; j < max; j++) {
				if (board->getGrid(i, j) == 0) {
					emptyCells.push_back(((i + 1) * 10) + (j + 1));
				}
			}
		}
		// show available cells
		// for (int i = 0; i < emptyCells.size(); i++) {
		// 	cout << emptyCells[i] << "  ";
		// }
		// cout << endl;
		//
		// cout << "hot here";

		int randCoorIndex = rand() % emptyCells.size();
		int randCoor;
		int randRow, randCol;
		randCoor = emptyCells[randCoorIndex];

		emptyCells.erase(emptyCells.begin() + randCoorIndex);

		// for (int i = 0; i < emptyCells.size(); i++) {
		// 	cout << emptyCells[i] << "  ";
		// }
		// cout << endl;

		// cout << randCoor << endl;
		randCol = randCoor % 10;
		randRow = randCoor / 10;
		// cout << randRow << " " << randCol << endl;

		x = randRow - 1;
		y = randCol - 1;
		flag = board->validInput(x, y);
		if (flag == false)
			cout << "Invalid input! Please input again." << endl;

		return true;
}

#endif
