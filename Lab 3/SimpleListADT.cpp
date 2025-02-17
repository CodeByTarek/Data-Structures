#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        char* key;
        Node* next;
        Node(){next = NULL;}
        Node(int value){
            key = new char (value);
            next = NULL;
        }
        ~Node(){}
};

class Stack{
public:
    Node* head;
    Node* tail;
    Stack(){
        head = NULL;
        tail = NULL;
    }
    void pushFront(char key);
    char* topFront();
    void print();
    void popFront();



};





int main(){
    int choice;
    char key;
    int* p;

    Stack* list1 = new Stack();

    list1->pushFront('5');
    list1->pushFront('4');
    list1->pushFront('3');
    list1->pushFront('2');
    list1->pushFront('1');

    list1->print();

    Stack* list2 = new Stack();

    list2->pushFront('5');
    list2->pushFront('4');
    list2->pushFront('3');
    list2->pushFront('2');
    list2->pushFront('1');

    list2->print();
    list1->popFront();
    list1->print();


    // write your code
}

void Stack::pushFront(char key){
    Node* node = new Node(key);
    node->next = head;
    head = node;
    if(tail == NULL)
        tail = head;
}

char* Stack::topFront(){
    return head->key;
}

void Stack::print(){
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
void Stack::popFront(){
    if(head==NULL){
        cout<<"List is empty"<<endl;
    }
    head=head->next;
}


