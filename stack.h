#ifndef STACK
#define STACK

 struct Node{
   int coor;
   Node* next = NULL;
 };

 class stack {
 private:
   Node *Top;

 public:
   stack () {
     Top = NULL;
   }
   ~stack () {
     delete Top;
   }

   int getTop();
   bool isEmpty();
   bool insertNode(int value);
   int pop();
   void showStack();
   int size();
   bool isNew(int num);
 };

 int stack:: getTop() {
   return Top->coor;
 }

 bool stack:: isEmpty() {
   if (Top == NULL) {
     return true;
   }
   else return false;
 }

 bool stack:: insertNode(int value) {
   if (this->isNew(value)) {
     Node* newNode = new Node();
     newNode->coor = value;
     newNode->next = Top;

     Top = newNode;
     return 1;
   }
   else return 0;
 }

 int stack:: pop() {
   int popData;
   Node* ptr;
   ptr = Top;
   Top = Top->next;
   popData = ptr->coor;
   delete ptr;
   return popData;
 }

 void stack:: showStack() {
   if (isEmpty()) cout << "\nCan not show empty stack!\n";
   else {
     Node* current = Top;
     cout << "Top ";
     while(current != NULL) {
       cout << " -> " << current->coor;
       current = current->next;
     }
     cout << endl;
   }

 }

 int stack:: size() {
   Node* current;
   int counter = 0;
   current = Top;
   while(current != NULL) {
     counter++;
     current = current->next;
   }
   return counter;
 }

 bool stack:: isNew(int num) {
   Node* current;
   current = Top;
   while (current != NULL) {
     if (current->coor == num) return false;
     current = current->next;
   }
   return true;
 }

#endif
