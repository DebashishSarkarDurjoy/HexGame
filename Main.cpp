/*
 * Main.cpp
 *
 *  Created on: 21/02/2021
 *      Author: dongmo
 */

#include<iostream>
#include<string>
#include <vector>
#include <queue>
#include <time.h>

using namespace std;


#include "stack.h"
#include "Board.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "RandomPlayer.h"
#include "SmartPlayer.h"
#include "HexGame.h"

//SmartPlayer only -1 (Blue)
//HumanPlayer always 1 and -1
//RandomPlayer always -1 and 1
/*
		SmartPlayer always
*/

int displayMenu() {
	int userInput;
	cout << "\n" << "Please choose a following: " << endl;
	cout << "1. Human vs Random." << endl;
	cout << "2. Random vs Random." << endl;
	cout << "3. Human vs Smart." << endl;
	cout << "4. Random vs Smart." << endl;
	cout << ">>>>";
	cin >> userInput;
	return userInput;
}

int main() {
	srand(time(0));

	int input = displayMenu();

	Player *p1;
	Player *p2;

	switch (input) {
		case 1:
			p1 = new HumanPlayer(1, "Human (Red)");
			p2 = new RandomPlayer(-1, "Random (Blue)");
			break;

		case 2:
			p1 = new RandomPlayer(1, "Random (Red)");
			p2 = new RandomPlayer(-1, "Random (Blue)");
			break;

		case 3:
			p1 = new HumanPlayer(1, "Human (Red)");
			p2 = new SmartPlayer(-1, "Smart (Blue)");
			break;

		case 4:
			p1 = new RandomPlayer(1, "Random (Red)");
			p2 = new SmartPlayer(-1, "Smart (Blue)");
			break;
	}

	int boardSize = 5;
	cout <<"Input the size of board:" << endl;
    cin >> boardSize;
	if (boardSize < 3)
		boardSize = 3;

	Board *board = new Board(boardSize);

	HexGame game(board, p1, p2);
	game.play();

	delete board;
	delete p1;
	delete p2;

//	system("pause");
	return 0;
}
