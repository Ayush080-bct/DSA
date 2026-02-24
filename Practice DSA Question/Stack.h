#ifndef MY_STACK  // if not define
#define MY_STACK
#define MAX 100
class Stack {
   private:
    int tos;
    float data[MAX];

   public:
    Stack(int t);
    bool IsFull(Stack *s);
    bool IsEmpty(Stack *s);
    void push(Stack *s, float element);
    float pull(Stack*s);
    void display(Stack*s);

};

#endif