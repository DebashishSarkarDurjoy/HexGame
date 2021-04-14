#ifndef SMARTPLAYER_H_
#define SMARTPLAYER_H_

class SmartPlayer: public Player {
private:
  stack* track = new stack();

public:
  SmartPlayer(int type, string name="Smart"): Player(type, name) {

  };

  bool getMove(Board*, int&, int&);
};

// void SmartPlayer:: showQ(SmartQ* Q) {
//   queue<int> tempQ = Q;
//   cout << "Queue: ";
//   while(!tempQ.empty()) {
//     cout << tempQ.front() << " -> ";
//     tempQ.pop();
//   }
//   cout << endl;
// }

bool SmartPlayer:: getMove(Board* board, int& x, int& y) {
  int boardSize = board->getBoardSize();
  if (track->isEmpty()) {
    int i = 0;
    while(track->isEmpty() && i < boardSize) {
      if (board->getGrid(i, boardSize-1) == 0) {
        x = i;
        y = boardSize -1;
        track->insertNode((i+1)*10 + (y+1));
        track->showStack();
        return true;
      }
      i++;
    }
  }

  while(!track->isEmpty()) {
    int coor = track->getTop();
    int tempRow = (coor / 10) -1;
    int tempCol = (coor % 10) -1;
    track->showStack();

    if (tempRow < 0 || tempCol < 0 || tempRow > boardSize || tempCol > boardSize) {
      track->pop();
      continue;
    }

    if (board->validInput(tempRow, tempCol-1) && board->getGrid(tempRow, tempCol-1) == 0) {
      x = tempRow;
      y = tempCol-1;
      track->insertNode((x+1)*10 + (y+1));
      track->showStack();
      return true;
    }
    if (board->validInput(tempRow+1, tempCol-1) && board->getGrid(tempRow+1, tempCol-1) == 0) {
      x = tempRow+1;
      y = tempCol-1;
      track->insertNode((x+1)*10 + (y+1));
      track->showStack();
      return true;
    }
    if (board->validInput(tempRow-1, tempCol) && board->getGrid(tempRow-1, tempCol) == 0) {
      x = tempRow-1;
      y = tempCol;
      track->insertNode((x+1)*10 + (y+1));
      track->showStack();
      return true;
    }
    if (board->validInput(tempRow+1, tempCol) && board->getGrid(tempRow+1, tempCol) == 0) {
      x = tempRow+1;
      y = tempCol-1;
      track->insertNode((x+1)*10 + (y+1));
      track->showStack();
      return true;
    }
    track->pop();
  }

  return false;
}



#endif
