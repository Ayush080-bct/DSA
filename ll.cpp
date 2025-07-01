#include<iostream>
using namespace std;
class linkedlist;
class node
{
    friend linkedlist;
    float data;
    node* next;
    public:
    node()
    {
        data = 0;
        next = NULL;
    }
};
class linkedlist
{
    node* First;
    node* Last;
    node* temp;
    node* newnode;
    public:
    linkedlist()
    {
        First = NULL;
        Last = NULL;
        temp = NULL;
        newnode = NULL;
    }
    node* createnewnode(float dat)
    {
        newnode = new node;
        newnode->data = dat;
        return newnode;
    }
    void insertionfrombeg(int data)
    {
        temp = First;
        First = createnewnode(data);
        First->next = temp;
        if(temp==NULL)
            Last = First;
    }
    void insertionfromend(int data)
    {
        temp = createnewnode(data);
        if(Last == NULL)
            First = Last = temp;
        else
        {
            Last->next = temp;
            Last = temp;
        }    
    }
    void insertionatpos(int data, int pos)
    {
        temp = First;
        int i = 1;
        while(i < pos-1 && temp != NULL)
        {
            temp = temp->next;
            i++;
        }
        if(temp == NULL && pos!=1)
            cout << "Invalid Attempt." << endl;
        else if(pos == 1)
            insertionfrombeg(data);
        else if(temp == Last)
            insertionfromend(data);
        else
        {
            node* tempp = createnewnode(data);
            tempp->next = temp->next;
            temp->next = tempp;
        }
    }
    void display()
    {
        temp = First;
        if(temp == NULL)
            cout << "List is Empty" << endl;
        while(temp != NULL)
        {
            cout << "-> " << temp->data << endl;
            temp = temp->next;
        }
    }
};
int main()
{
    linkedlist li;
    li.insertionfrombeg(5);
    li.insertionfrombeg(6);
    li.insertionfromend(7);
    li.insertionfromend(8);
    li.insertionatpos(9,3);
    li.insertionatpos(10,6);
    li.display();
    return 0;
}