#include<bits/stdc++.h>
#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        int* key;
        Node* next;
        Node(){next = NULL;}
        Node(int value){
            key = new int (value);
            next = NULL;
        }
        ~Node(){}
};

void pushFront(int key);
int* topFront();
void print();
void numberOfElements();

Node* head = NULL;
Node* tail = NULL;

int main(){
    int choice;
    int key;
    int* p;

    pushFront(5);
    pushFront(4);
    pushFront(3);
    pushFront(2);
    pushFront(1);

    print();
    //write your code
    //deleteFirst();
    numberOfElements();
}

void pushFront(int key){
    Node* node = new Node(key);
    node->next = head;
    head = node;
    if(tail == NULL)
        tail = head;
}

int* topFront(){
    return head->key;
}

void print(){
    Node* p = head;
    if(head==NULL){
        cout << "List is empty" << endl;
        return;
    }
    while(p!= NULL){
        cout << *(p->key) << " -> ";
        p = p->next;
    }
    cout << " NULL " << endl;
}
void numberOfElements(){
    int c=0;
    Node* p=head;
    while(p!=NULL){
        c++;
        p=p->next;
    }
    cout<<c<<endl;
}
