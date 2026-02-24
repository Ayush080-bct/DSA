#include <iostream>
using namespace std;
struct DQ {
    int data;
    DQ* next;
};
struct DQ *front = NULL, *rear = NULL;
void Enqueue(int value) 
{
    DQ*newnode=new DQ();
    if(newnode == NULL) cout<<"Memory allocation failed "<<endl;
    else{
        newnode->data=value;
        newnode->next=NULL;
    }
    if(front==NULL){
        front =rear=newnode;
    }
    else 
    {
        rear->next=newnode;
        rear=newnode;
        newnode->next=NULL;
        
    }
}
void Dequeue()
{
    if(front==NULL){
        cout<<"Empty!"<<endl;
    }
    else{
        if(front->next=NULL)
        {
            DQ*temp=front;
            front=rear=NULL;
            delete temp;
        }
        else{
            DQ*t=front;
            front=front->next;
            delete t;
        }
    }
}

int main() {
    Enqueue()
    return 0;
}