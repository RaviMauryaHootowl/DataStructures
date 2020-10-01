#include <iostream>

using namespace std;

// StackNode using Structure Data Structure 
  struct Node { 
    char data; 
    struct Node* link; 
}; 
struct Node* top; // pointer to top of stack

template <typename T>  
void push(T data) 
{ 
    // create new node temp and allocate memory 
    struct Node* temp; 
    temp = new Node(); 
  
    // input new data in StackNode
    temp->data = data; 
  
    // make temp as top of Stack 
    temp->link = top; 
    top = temp; 
} 
  
int isEmpty() 
{ 
    return top == NULL; 
} 

char getTop() 
{ 
    if (!isEmpty()) 
        return top->data;  
} 
    
void pop() 
{ 
    struct Node* temp; 
  
    // check for empty stack 
    if (top == NULL) 
    { 
        cout << "\nStack is Empty" << endl; 
        exit(1); 
    } 

    else 
    { 
        
        temp = top; 
        top = top->link; 
        temp->link = NULL; 
        delete temp;
    } 
} 
   
int main() 
{ 
    // paste code from other two files here to run those two functions 

    // string ans=infixToPostfix("(A-(B/C)*D+E)*F%G"); 
    // cout<<"Postfix Expression - "<<ans<<endl;
    // int value=evaluatePostfix(ans);
    // cout<<"Value of Postfix Exp - "<<value;
    return 0;  
}
