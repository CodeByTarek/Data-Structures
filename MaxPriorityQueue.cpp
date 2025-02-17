#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int* key;
        Node* next;
        int* priority;
        Node(){next = NULL;}
        Node(int value1, int value2){
            priority = new int (value1);
            key = new int (value2);
            next = NULL;
        }
        ~Node(){}
};
class Queue{
    public:
        Node* head;
        Node* tail;

        Queue(){
            head=NULL;
            tail=NULL;
        }
    void enqueue(int p, int v);
    int* top();
    void print();
    void empty();
    void dequeue();
};
//Node* head = NULL;
//Node* tail = NULL;
//Node* node1;
void Queue::enqueue(int p, int v){
    Node* node=new Node(p,v);
    Node* k = head;
    if(head==NULL){
        node->next=head;
        head=node;
    }
    else if(*(node->priority)>*(head->priority)){
        node->next=head;
        head=node;
    }
    else{
        while(k->next!=NULL){

            if(*(k->priority) >= *(node->priority) && *(k->next->priority) < *(node->priority)){
                node->next=k->next;
                k->next=node;
                break;
            }
            k=k->next;
        }
        Node* f=head;
        while(f->next!=NULL){
            f=f->next;
        }
        if(*(f->priority) >= *(node->priority)){
            f->next=node;
        }
    }
}

void Queue::print(){
    Node* p = head;
    if(head==NULL){
        cout << "The queue or list is empty" << endl;
        return;
    }
    while(p!= NULL){
        cout <<"Priority: "<< *(p->priority) << " and Key: "<<*(p->key)<<endl;
        p = p->next;
    }
    cout << endl;
}

void Queue::empty(){
    if(head==NULL){
        cout<<"The queue is empty"<<endl;
    }
    else{
        cout<<"The queue is not empty"<<endl;
    }
}
void Queue::dequeue(){
    head=head->next;
}
int* Queue::top(){
    cout<< "Top: Priority: "<<*(head->priority)<<" and Key: "<<*(head->key)<<endl;
}


int main(){
    cout<<"\n";
    Queue* q=new Queue;
    int choice;
    int key;
    int priority;
    int* p;
    while(true){
            cout<<"** Please enter 34200 to exit **"<<endl<<endl;
            cout << "Enter Priority: ";
            cin >> priority;
            if(priority==34200){
                exit(0);
            }
            cout << "Enter key: ";
            cin >> key;
            q->enqueue(priority,key);
            cout<<endl;
            q->print();
            q->top();
            cout<<endl;
            q->empty();
            cout<<endl;
    }
    return 0;
}
