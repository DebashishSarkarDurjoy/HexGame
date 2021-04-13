#ifndef SMARTQ_H_
#define SMARTQ_H_

struct BigNode {
  int currentCoor = 0;
  BigNode* next1 = NULL;
  BigNode* next2 = NULL;
  BigNode* next3 = NULL;
  BigNode* previous = NULL;
  bool visited = false;
};

class SmartQ {
private:
  BigNode* Top;
  int size;
  Board* board;
public:
  SmartQ() {
    Top = NULL;
    size = 0;
  }
  int getCurrentCoor();
  BigNode* getNext1();
  BigNode* getNext2();
  BigNode* getNext3();
  void show();
  bool push(int x, int y, Board* board);
  BigNode* getTop();
  int getSize();

};

int SmartQ:: getSize() {
  return size;
}

BigNode* SmartQ:: getTop() {
  return Top;
}

int SmartQ:: getCurrentCoor() {
  return Top->currentCoor;
}

BigNode* SmartQ:: getNext1() {
  return Top->next1;
}

BigNode* SmartQ:: getNext2() {
  return Top->next2;
}

BigNode* SmartQ:: getNext3() {
  return Top->next3;
}

void SmartQ:: show() {
  BigNode* current = Top;
  cout << "SmartQ: ";
  while (current != NULL ) {
    if (!current->visited)  {
      cout << current->currentCoor << " -> ";
      current->visited = true;
    }
    if (current->next1 != NULL && !current->next1->visited) {
      current = current->next1;
      continue;
    }
    if (current->next2 != NULL && !current->next2->visited) {
      current = current->next2;
      continue;
    }
    if (current->next3 != NULL && !current->next3->visited) {
      current = current->next3;
      continue;
    }
    current = current->previous;

  }
  cout << endl;
}

bool SmartQ:: push(int x, int y, Board* board) {
  BigNode* newNode = new BigNode();
  newNode->currentCoor = (x + 1)*10 + (y+1);
  cout << "got here: " << newNode->currentCoor <<":";
  Top = newNode;
  size++;
  if (board->validInput(x, y-1) && board->getGrid(x, y-1) == 0) {
    newNode->next1 = new BigNode();
    newNode->next1->currentCoor = (x + 1)*10 + (y + 1 - 1);
    newNode->previous = newNode;
    size++;
  }
  if (board->validInput(x+1, y-1) && board->getGrid(x+1,y-1) == 0) {
    newNode->next2 = new BigNode();
    newNode->next2->currentCoor = (x+1+1)*10 + (y-1+1);
    newNode->previous = newNode;
    size++;
  }
  if (board->validInput(x+1, y) && board->getGrid(x+1, y) == 0) {
    newNode->next3 = new BigNode();
    newNode->next3->currentCoor = (x+1+1)*10 + (y+1);
    newNode->previous = newNode;
    size++;
  }
  return true;
}

#endif //SMARTQ_H_
