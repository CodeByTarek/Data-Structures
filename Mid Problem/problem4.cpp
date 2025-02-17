#include<bits/stdc++.h>

using namespace std;
class Node{
    public:
        int* data;
        Node* next;
        Node(){next = NULL;}
        Node(int value){
            data = new int(value);
            next = NULL;
        }
        ~Node(){}
};
class Stack{
    public:
       Node* top;
       Stack(){
       top=NULL;
       }
    void push(int data);
    void pop();
    int peek();
    void print();
    void removeSmallest();
};

void Stack::push(int key){
    Node* node=new Node(key);
    node->next=top;
    top=node;
}
void Stack::print(){
    Node* p = top;
    if(top==NULL){
        cout << "The queue or list is empty" << endl;
        return;
    }
    while(p!= NULL){
        cout<<*(p->data)<<endl;
        p = p->next;
    }
    cout << endl;
}


void Stack::pop(){
    top=top->next;
}
int Stack::peek(){
    cout<<*(top->data)<<endl;
}

void menu();


int main(){
    cout<<"\n";
    Stack* q=new Stack;
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
            cout << "Enter key: ";
            cin >> key;
            q->push(key);
            cout << "operation completed" << endl;
            break;

        case 2:
            q->print();
            cout << "operation completed" << endl;
            break;

        case 3:

            q->removeSmallest();
             cout << "operation completed" << endl;
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
}
void menu(){
    cout<<"(1)Enqueue/Push Back.......(2)Print..........(3)Remove Smallest....(4)Exit"<<endl<<endl;
}
void Stack::removeSmallest(){
    Node* p=top;
    int value=*(p->data);
    p=p->next;
    while(p->next!=NULL){
        if(value>=*(p->data)){
            value=*(p->data);

        }

        p=p->next;
    }
    if(value>=*(p->data)){
        value=*(p->data);
    }
    if(value==*(p->data)){
            Node* g=top;
            if(g->next->next!=NULL){
                g=g->next;
            }
        g->next->next=NULL;
    }//remove last element

    Node* k=top;
    if(value==*(k->data)){
        top=top->next;
    }//remove first element

    Node* f=top;
    if(value!=*(p->data)&&value!=*(k->data)){
        while(f->next!=NULL){
        if(value==*(f->next->data)){
            Node* temp=f->next;
            f->next=f->next->next;
            delete temp;
            break;
        }
        f=f->next;
    }
  }
}
