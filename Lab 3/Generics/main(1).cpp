#include<bits/stdc++.h>
#include "node.h"
#include "SinglyLinkedList.h"

using namespace std;

void menu();
void print(SinglyLinkedList* list);

int main(){
    int choice;
    int key;
    int* p;

    SinglyLinkedList* listInt = new SinglyLinkedList();


    while(true){
        menu();
        cout << "Enter choice: ";
        cin >> choice;
        switch(choice){
        case 1:
            int key;
            cout << "Enter key: ";
            cin >> key;
            listInt->pushFront(&key, sizeof(int));
            cout << "operation completed" << endl;
            break;
        case 2:
            listInt->popFront();
            cout << "operation completed" << endl;
            break;
        case 3:
            p = (int*) listInt->topFront();
            cout << "top front: " << *p << endl;
            cout << "operation completed" << endl;
            break;
        case 12:
            print(listInt);
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

void print(SinglyLinkedList* list){
    Node* p = list->head;
    if(p==NULL){
        cout << "List is empty" << endl;
        return;
    }
    while(p!= NULL){
        cout << *(int*) (p->key)<< " -> ";
        p = p->next;
    }
    cout << " NULL " << endl;
}

