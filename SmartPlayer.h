#ifndef SMARTPLAYER_H_
#define SMARTPLAYER_H_

class SmartPlayer: public Player {
private:
  SmartQ* traceQ;

public:
  SmartPlayer(int type, string name="Smart"): Player(type, name) {
    traceQ = new SmartQ();
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
    int maxCol = board->getBoardSize();
    cout << traceQ->getSize();
    if (traceQ->getSize() == 0) {

      for (int i = maxCol-1; i >= 0; i++) {
        if (board->getGrid() == 0 && board->validInput()) {
          
          traceQ->push();
          traceQ->show();
          return true;
        }
      }
    }
    else {
      cout << "hot here" ;
      int coor = traceQ->getCurrentCoor();
      int tempR, tempC;
      tempR = (coor / 10) -1;
      tempC = (coor % 10) -1;
      if (board->validInput(tempR, maxCol-1) && board->getGrid(tempR, maxCol-1) == 0 ) {
        x = tempR;
        y = maxCol-1;
        traceQ->push(x, y, board);
        traceQ->show();
        return true;
      }
      if (board->validInput(tempR+1, maxCol-1) && board->getGrid(tempR+1, maxCol-1) == 0) {
        x = tempR+1;
        y = maxCol-1;
        traceQ->push(x, y, board);
        traceQ->show();
        return true;
      }
      if (board->validInput(tempR+1, maxCol) && board->getGrid(tempR+1, maxCol) == 0) {
        x = tempR;
        y = maxCol-1;
        traceQ->push(x, y, board);
        traceQ->show();
        return true;
      }
    }
  return false;
}



#endif
