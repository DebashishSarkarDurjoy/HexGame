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

   bool isStackEmpty();
   void insertNode(int value);
   int pop();
   void showStack();
   int size();
   bool isNew(int num);
 };

 bool stack:: isStackEmpty() {
   if (Top == NULL) {
     return true;
   }
   else return false;
 }

 void stack:: insertNode(int value) {
   Node* newNode = new Node();
   newNode->coor = value;
   newNode->next = Top;

   Top = newNode;
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
   if (isStackEmpty()) cout << "\nCan not show empty stack!\n";
   else {
     Node* current = Top;
     cout << "Top ";
     while(current != NULL) {
       cout << " -> " << current->coor;
       current = current->next;
     }
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
