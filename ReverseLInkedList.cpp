#include <iostream>
using namespace std;

struct sll {
    int data;
    sll* next; 
};

sll* first = NULL;
sll* last = NULL;

void insertionatbeg(int a) {
    sll* newnode = new sll();
    newnode->data = a;
    newnode->next = NULL;

    if (first == NULL) {
        first = last = newnode;
    } else {
        newnode->next = first;
        first = newnode;
    }
}

void insertionatend(int a)
{
    sll *newnode = new sll();
    newnode->data = a;
    newnode->next = NULL;
    if (first == NULL)
    {
        first = last = newnode;
    }
    else
    {
        last->next = newnode;
        last = newnode;
    }
}

void inseratspecpos(int a,int pos)
{
   
    sll* newnode = new sll();
    newnode->data = a;
    newnode->next = NULL;
    if (first == NULL)
    {
        cout << "List is Empty! " << endl;
    }
    else if(pos==1)
    {
        insertionatbeg(a);
        return;
    }
    else
    {
        sll* temp;
        temp = first;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}


void deletionatbeg()
{
    sll*temp;
    if (first == NULL) {
        cout << "List is Empty!" << endl;
        return;
    }
    else if (first->next==NULL)
    {
        temp=first;
        first=last=NULL;
        delete temp;
        
    }
    else
    {
        temp=first;
        first=first->next;
        delete temp;
    }
}

void deletionatend()
{
    sll*temp;
    if (first == NULL) {
        cout << "List is Empty!" << endl;
        return;
    }
    else if(first->next==NULL)
    {
        temp=first;
        first=last=NULL;

        delete temp;
        
    }
    else{
        temp=first;
        while(temp->next!=last)
        {
            temp=temp->next;
        }
        last=temp;
        temp=last->next;
        delete temp;
        last->next=NULL;
    }


}


void deletionatspecpos(int pos)
{
    sll*temp;
    if (first == NULL) {
        cout << "List is Empty!" << endl;
        return;
    }
    else if(pos==1){
        deletionatbeg();
    }
    else{
        temp=first;
        for(int i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        if(temp->next==last)
        {
            deletionatend();
        }
        else
        {
            sll*tempp=temp->next;
            temp->next=tempp->next;
            delete tempp;
        }
    }

}

void search(int key)
{
    int   flag=0;

  if(first==NULL)
  {
    cout<<"List is Empty! "<<endl;

  }
  else{
    sll* temp=first;
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            flag=1;
            cout<<"Element found ! "<<endl;
            break;

        }
        temp=temp->next;
    }
    if(flag==0)
    {
        cout<<"Element not found! "<<endl;
    }
  }
}

void display() {
    sll* temp = first;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
void reverse()
{
    sll* prev = NULL;
    sll* temp = first;
    sll* next = NULL;

    while (temp != NULL)
    {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }

    
    last = first;
    first = prev;
}



int main() {
    insertionatbeg(5);
    insertionatbeg(10);
    insertionatend(20);
    insertionatbeg(30);
   

    display();
    reverse();
    display();

    return 0;
}
