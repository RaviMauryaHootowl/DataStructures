#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* link;
};

void insertInBack(Node** head,int newData)
{
    Node* newNode = new Node();
    Node* last = *head;
    newNode->data = newData; 
    newNode->link = NULL;

    if (*head == NULL)  
    {  
        *head = newNode;  
        return;  
    }  
  
    
    while (last->link != NULL)  
        last = last->link;  

    last->link = newNode;
}
void insertAtLoc(Node* prevNode, int newData)  
{  
    if (prevNode == NULL)  
    {  
        cout<<"Previous node cannot be NULL";  
        return;  
    }  
  
    Node* new_node = new Node(); 
  
    new_node->data = newData;  
    new_node->link = prevNode->link;  
    prevNode->link = new_node;  
}   
void insertInFront(Node** head, int newData)  
{  
    Node* new_node = new Node(); 
  
    new_node->data = newData;  
  
    new_node->link = (*head);  
  
    (*head) = new_node;  
}
void insertInSorted(Node* node,int newData)
{
    while(node!=NULL)
    {
        if(node->data > newData)
            insertInFront(&node,newData);
            break;
    }
}

Node* deleteFirst(Node* head)
{
    if (head == NULL) 
        return NULL; 
  
    Node* temp = head; 
    head = head->link; 
  
    delete temp; 
    
    return head;
}
Node* deleteLast(Node* head)
{
    if (head == NULL) 
        return NULL; 
  
    if (head->link == NULL) { 
        delete head; 
        return NULL; 
    } 
  
    
    Node* second_last = head; 
    while (second_last->link->link != NULL) 
        second_last = second_last->link; 
  
    
    delete (second_last->link); 
  
    second_last->link = NULL; 
  
    return head;
}

void deleteNode(Node **head, int newData) 
{ 
    struct Node* temp = *head, *pre; 
  
    if (temp != NULL && temp->data == newData) 
    { 
        *head = temp->link;   
        delete temp;               
        return; 
    } 
  
    while (temp != NULL && temp->data != newData) 
    { 
        pre = temp; 
        temp = temp->link; 
    } 
  
    if (temp == NULL) 
        return; 
  
    pre->link = temp->link; 
    delete temp;  
}
void printList(Node* node)  
{  
    while (node != NULL)  
    {  
        cout<<" "<<node->data;  
        node = node->link;  
    }  
}

int count(Node* node)  
{  
    int count=0;
    while (node != NULL)  
    {  
        ++count;  
        node = node->link;  
    }  
    return count;
}

void listSplitter(Node* node,Node** head1,Node** head2,int count)
{
    int i=1;
    int len=((count)/2)+1;
    while(node != NULL)
    {
        if(i<=len)
        {
            insertInBack(head1,node->data);
        }
        else
        {
            insertInBack(head2,node->data);
        }
        ++i;  
        node = node->link;  
    }
}

void sortList(Node *start) 
{ 
    int swap, i; 
    struct Node *ptr; 
    struct Node *tmp;
    struct Node *backptr = NULL; 
   
    if (start == NULL) 
        return; 
  
    do
    { 
        swap = 0; 
        ptr = start; 
  
        while (ptr->link != backptr) 
        { 
            if (ptr->data > ptr->link->data) 
            {  
                tmp=ptr;
                ptr=ptr->link;
                ptr->link=tmp;

                swap = 1; 
            } 
            ptr = ptr->link; 
        } 
        backptr = ptr; 
    } 
    while(swap); 
} 

void listMerger(Node* node1,Node* node2,Node** mergeHead)
{
    while(node1!= NULL || node2!= NULL)
    {
        if(node1->data <= node2->data)
        {
            insertInBack(mergeHead,node1->data);
            node1=node1->link;
        }
        else
        {
            insertInBack(mergeHead,node2->data);
            node2=node2->link;
        }
    }

    // add rest of the elements
    while(node1 != NULL)
    {
        insertInBack(mergeHead,node1->data);
        node1=node1->link;
    }
    while(node2 != NULL)
    {
        insertInBack(mergeHead,node2->data);
        node2=node2->link;
    }

}

int main()
{
    Node* head=NULL;
    Node* tmphead=NULL;

    insertInBack(&tmphead,2);
    insertInBack(&tmphead,4);
    cout<<"After inserting two elements at back - "<<endl;
    printList(tmphead);

    insertInFront(&tmphead,1);
    cout<<"After inserting one element in front - "<<endl;
    printList(tmphead);

    insertInSorted(tmphead,3);
    cout<<"After inserting integer '3' in sorted list - "<<endl;
    printList(tmphead);

    tmphead = deleteFirst(tmphead);
    cout<<"After deleting from front - "<<endl;
    printList(tmphead);

    tmphead = deleteLast(tmphead);
    cout<<"After deleting from back - "<<endl;
    printList(tmphead);

    deleteNode(&tmphead,3);
    cout<<"After deleting integer '3' from list - "<<endl;
    printList(tmphead);

    cout<<endl;
    cout<<"New List"<<endl;
    
    //inserting elements
    insertInBack(&head,5);
    insertInBack(&head,3);
    insertInBack(&head,15);
    insertInBack(&head,7);
    insertInBack(&head,11);

    // heads for two different lists
    Node* firstHead=NULL;
    Node* secHead=NULL;
    Node* mergeHead=NULL;

    //count number of elements in main list
    int l=count(head);

    cout<<"Original List - "<<endl;
    printList(head);

    // split the list into two small lists
    listSplitter(head,&firstHead,&secHead,l);

    cout<<"First List before Sorting - "<<endl;
    printList(firstHead);
    cout<<"First List after Sorting - "<<endl;
    sortList(firstHead);
    printList(firstHead);

    cout<<"Second List before Sorting - "<<endl;
    printList(secHead);
    cout<<"Second List after Sorting - "<<endl;
    sortList(secHead);
    printList(secHead);

    cout<<"List after merging - "<<endl;
    listMerger(firstHead,secHead,&mergeHead);
    printList(mergeHead); 

    return 0;
}