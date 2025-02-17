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
Node* head = NULL;
Node* tail = NULL;
Node* node1;
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
    cout<< "Priority: "<<*(head->priority)<<" and Key: "<<*(head->key)<<endl;
}

void menu();

int main(){
    cout<<"\n";
    cout<<"\t\t\t------------------"<<endl;
    cout<<"\t\t\t Max Priority Queue"<<endl;
    cout<<"\t\t\t\------------------"<<endl<<endl;


    Queue* q=new Queue;
    int choice;
    int key;
    int priority;
    int* p;
    while(true){
        menu();
         cout << "Enter choice: ";
        cin >> choice;
        switch(choice){
        case 1:
            cout << "Enter Priority: ";
            cin >> priority;
            cout << "Enter key: ";
            cin >> key;
            q->enqueue(priority,key);
            cout << "operation completed" << endl;
            break;

        case 2:
            q->print();
            cout << "operation completed" << endl;
            break;

        case 3:
            q->dequeue();

        case 4:
            q->top();

        case 5:
            q->empty();

        case 6:
            exit(0);
        }
    }
    return 0;
}
void menu(){
    cout<<"(1)Enqueue.......(2)Print..........(3)Dequeue"<<endl;
    cout<<"(4)Top..........(5)Empty..............(6)Exit"<<endl<<endl;
}
