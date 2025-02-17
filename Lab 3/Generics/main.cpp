#include<bits/stdc++.h>
#include "node.h"

using namespace std;

void menu();
void pushFront(int key);
int* topFront();
void print();

Node* head = NULL;
Node* tail = NULL;

int main(){
    int choice;
    int key;
    int* p;

    while(true){
        menu();
        cout << "Enter choice: ";
        cin >> choice;
        switch(choice){
        case 1:
            cout << "Enter key: ";
            cin >> key;
            pushFront(key);
            cout << "operation completed" << endl;
            break;
        case 3:
            p = topFront();
            cout << "top front: " << *p << endl;
            cout << "operation completed" << endl;
            break;
        case 12:
            print();
            cout << "operation completed" << endl;
            break;
        case 13:
            cout << "thank you!" << endl;
            exit(0);
        }
    }
}

void menu(){
    cout << "------------------" << endl;
    cout << "Singly Linked List" << endl;
    cout << "------------------" << endl;
    cout << " (1) push front ... (2) pop front ... (3) top front ..." << endl;
    cout << " (4) push back .... (5) pop back .... (6) top back ...." << endl;
    cout << " (7) find key ..... (8) erase key ... (9) empty ......." << endl;
    cout << "(10) add before .. (11) add after .. (12) print ......." << endl;
    cout << "(13) exit ..." << endl;
    cout << "------------------" << endl;
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
        cout << *(p->key) << " ";
        p = p->next;
    }
    cout << endl;
}

