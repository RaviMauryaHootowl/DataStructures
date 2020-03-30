#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* next;
};

class linked_list
{
private:
    node* head;
    node* tail;
public:
    linked_list(){
        head = NULL;
        tail = NULL;
    }

    void addNode(int n){
        node* tempNode = new node();
        tempNode->data = n;
        tempNode->next = NULL;
        if(head == NULL){
            head = tempNode;
            tail = tempNode;
        }else{
            tail->next = tempNode;
            tail = tail->next;
        }
    }

    node* getHead(){
        return head;
    }

    static void join(node* a, node* b){
        while(a->next != NULL){
            a = a->next;
        }
        a->next = b;
    }

    void addAtFront(int n){
        node* tempNode = new node();
        tempNode->data = n;
        tempNode->next = head;
        head = tempNode;
    }

    void addAfter(node* a, int n){
        node* tempNode = new node();
        tempNode->data = n;
        tempNode->next = a->next;
        a->next = tempNode;
    }

    void delAfter(node* a){
        if(a->next != NULL){
            node* tempNode = a->next;
            a->next = a->next->next;
            delete tempNode;
        }
    }

    // Displays this List
    void display(){
        node* tempNode = head;
        if(tempNode == NULL){
            cout << "NULL" << endl;
        }
        while(tempNode != NULL){
            cout << tempNode->data << " ";
            tempNode = tempNode->next;
        }
        cout << endl;
    }

    // Displays any Linked List (as this is static)
    static void displayList(node *head){
        if(head == NULL){
            cout << "NULL";
        }
        while(head != NULL){
            cout << head->data << " ";
            head = head->next;
        }
        cout << endl;
    }

};


int main(){
    linked_list a, b;
    a.addNode(5);
    a.addNode(11);
    b.addNode(4);
    b.addNode(54);
    cout << "LL A : ";
    a.display();
    cout << "LL B : ";
    b.display();
    linked_list::join(a.getHead(), b.getHead());
    cout << "Joining A & B ..." << endl;
    linked_list::displayList(a.getHead());

    linked_list c;
    c.addNode(7);
    c.addNode(14);
    c.addNode(84);
    c.addNode(47);
    cout << "LL C : ";    
    c.display();
    c.addAfter(c.getHead()->next, 62);   // Add 62 after 14
    cout << "LL C : ";
    c.display();
    c.delAfter(c.getHead()->next);   // Delete 62 (which is after 14)
    cout << "LL C : ";
    c.display();

}