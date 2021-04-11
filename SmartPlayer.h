#ifndef SMARTPLAYER_H_
#define SMARTPLAYER_H_

class SmartPlayer: public Player {
private:

public:
  SmartPlayer(int type, string name="Smart"): Player(type, name) {};

  bool getMove(Board*, int&, int&);
  void showQ(queue<int> Q);
};

void SmartPlayer:: showQ(queue<int> Q) {
  queue<int> tempQ = Q;
  cout << "Queue: ";
  while(!tempQ.empty()) {
    cout << tempQ.front() << " -> ";
    tempQ.pop();
  }
  cout << endl;
}



#endif
