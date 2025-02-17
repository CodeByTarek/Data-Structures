#include<bits/stdc++.h>
#include "node.h"

using namespace std;
void menu();
void pushFront(int key);
void print();
void erase(int key);
int* topFront();
void removeDuplicate();
void swap();
Node* head = NULL;
Node* tail = NULL;

using namespace std;

int main()
{
    cout<<"\n";
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
            case 2:
                print();
                cout << "operation completed" << endl;
                break;
            case 3:
                //removeDuplicate();
                swap();
                cout << "operation completed" << endl;
                break;
            case 4:
                removeDuplicate();

                cout << "operation completed" << endl;
                break;

            case 5:
                // removeDuplicate();
                cout << "Thank You!! " << endl;
                exit(0);
                break;
        }
    }

    return 0;
}

void menu(){
    cout << "------------------" << endl;
    cout << "Singly Linked List" << endl;
    cout << "------------------" << endl;
    cout << " (1) push front ... (2) print ... (3) swap ...(4) removeDuplicate ..." << endl;
    cout << "(5) exit ..." << endl;
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
void erase(int key){
    Node* temp;
    if(*(topFront())==(key)){
        temp=head;
        head=head->next;
        delete temp;
    }
    else{
         Node* p=head;
         Node* node=new Node;
         while(p!=NULL){
            if(*(p->next->key)==key){
                temp=p->next;
                p->next=p->next->next;
                delete temp;
                break;
            }
            p=p->next;
         }

    }
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
void removeDuplicate(){
    Node* p=head;
    //if(p==NULL || p->next==NULL){
      // return p;
   // }

    Node* k;
    k=p->next;
    Node* temp;
    while(p->next!=NULL){
        k=p;
        while(k->next!=NULL){
            if(*(p->key)==*(k->next->key)){
                temp=k->next;
                k->next=k->next->next;
                delete temp;
            }
            if(k->next==NULL){
                break;
            }
            k=k->next;

        }
        p=p->next;
    }

}

void swap(){
    Node* p= head;
    int temp,temp1;
    while(p!=NULL){
        temp=*(p->key);
        temp1=*(p->next->key);
        *(p->key)=temp1;
        *(p->next->key)=temp;
        p=p->next->next;
    }
}
