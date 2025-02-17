#include<bits/stdc++.h>

using namespace std;

class SinglyLinkedList{
    public:
        Node* head;
        Node* tail;
        SinglyLinkedList(){
            head=NULL;
            tail=NULL;
        }
        void pushFront(void* key, int bytes);
        void popFront();
        void* topFront();
};

void SinglyLinkedList::pushFront(void* key, int bytes){
    Node* node = new Node;
    node->key = static_cast<void *>(malloc(bytes));
    memcpy(node->key, (char*) key, bytes );
    node->next = head;
    head = node;
    if(tail == NULL)
        tail = head;
}

void SinglyLinkedList::popFront(){
    if(head==NULL)
        return;

    Node* temp = head;

    head = head->next;

    if(head==NULL)
        tail = head;

    delete temp;

}

void* SinglyLinkedList::topFront(){
    return head->key;
}


