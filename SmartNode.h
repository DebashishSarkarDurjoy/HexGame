#ifndef SMARTQ_H_
#define SMARTQ_H_

struct BigNode {
  int currentCoor;
  SmartNode* next1;
  SmartNode* next2;
  SmartNode* next3;
  SmartNode* previous;
};

class SmartQ {
private:
  BigNode* Top = NULL;
  int boardS;
public:
  bool getCurrentCoor();
  bool getNode1();
  bool getNode2();
  bool getNode3();

};

bool SmartQ:: getCurrentCoor() {
  return Top->currentCoor;
}

bool SmartQ:: getNext1() {
  return Top->next1;
}

bool SmartQ:: getNext2() {
  return Top->next2;
}

bool SmartQ:: getNext3() {
  return Top->next3;
}

//bool SmartNode:: push

#endif //SMARTNODE_H_
