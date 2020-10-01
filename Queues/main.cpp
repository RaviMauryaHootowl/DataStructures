#include<iostream>
#include<Windows.h>
using namespace std;

struct Node 
{ 
    char data; 
    struct Node* link; 
}; 
  
struct Queue 
{ 
    struct Node *front, *back; 
}; 

// EnQueue operation
void enQueue(Queue *node, char value) 
{ 
    struct Node *temp = new Node; 
    temp->data = value; 
    if (node->front == NULL) // if this is the first node
        node->front = temp; 
    else
        node->back->link = temp; 
  
    node->back = temp; // enqueued
    node->back->link = node->front; // link to first node
} 
  
// DeQueue operation
char deQueue(Queue *node) 
{ 
    if (node->front == NULL) 
    { 
        cout<<"Cannot remove element as Queue is empty!!"<<endl; 
        return 0; 
    } 
  
    // If this is the last node to be deleted 
    
    char value; // Value to be dequeued 
    if (node->front == node->back) 
    { 
        value = node->front->data; 
        delete node->front; 
        node->front = NULL; 
        node->back = NULL; 
    } 
    else  // There are more than one nodes 
    { 
        struct Node *temp = node->front; 
        value = temp->data; 
        node->front = node->front->link; 
        node->back->link= node->front; 
        delete temp; 
    } 
  return value;
}

int main()
{
    Queue *q = new Queue; 
    q->front = NULL;
    q->back = NULL; 

    enQueue(q,'r');
    enQueue(q,'y');
    enQueue(q,'g');

    while(true)
    {
        char signal=deQueue(q);
        cout<<"Current Signal:- "<<signal<<endl;

        switch(signal)
        {
            case 'r':
                Sleep(2500);
                break;        
                
            case 'y':
                Sleep(1000);
                break; 

            case 'g':
                Sleep(5000);
                break; 
        }
        enQueue(q,signal);

    }

    return 0;
}