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

void menu();
void enqueue(int priority, int key);
void print();
void printMaxPriorityQueue();
void dequeue();
int top();
void empty();


Node* head = NULL;
Node* tail = NULL;
Node* node1;



int main(){
    cout<<"\n";
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
            enqueue(priority,key);
            cout << "operation completed" << endl;
            break;

        case 2:
            print();
            cout << "operation completed" << endl;
            break;

        case 3:
            printMaxPriorityQueue();
            cout << "operation completed" << endl;
            break;

        case 4:
            dequeue();
            cout << "operation completed" << endl;
            break;

        case 5:
            top();
            cout << "operation completed" << endl;
            break;

        case 6:
            empty();
        }


    }
    return 0;
}
void menu(){
    cout<<"(1)Enqueue/Push Back.......(2)Print........(3)Max-Priority-Queue"<<endl;
    cout<<"(4)Dequeue/Pop Front.......(5)Top..........(6)empty()"<<endl<<endl;
}
void enqueue(int priority, int key){
    /*Node* node = new Node(priority,key);
    node->next = head;
    head = node;
    if(tail == NULL)
        tail = head;*/
        Node* node = new Node(priority,key);
        node->next=NULL;
        if(head==NULL){
            head=node;
            tail=head;
        }
        else if(head!=NULL){
            tail->next=node;
            tail=node;
        }
}

void dequeue(){
    head=head->next;
}
int top(){
    cout<< "Priority: "<<*(head->priority)<<" and Key: "<<*(head->key)<<endl;
}
void empty(){
    if(head==NULL){
        cout<<"The queue/list is empty"<<endl;
    }
    else{
        cout<<"The queue/list is not empty"<<endl;
    }
}
void print(){
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
void printMaxPriorityQueue(){
    Node* p = head;
    Node* value=p;;
    *(value->priority)=*(p->priority);
    if(head==NULL){
        cout << "List is empty" << endl;
        return;
    }
     int temp,temp1;
    while(p!=NULL){
            while(p->next!=NULL){
                if(*(p->priority)<*(p->next->priority)){
                    temp=*(p->priority);
                    temp1=*(p->next->priority);
                    *(p->next->priority)=temp;
                    *(p->priority)=temp1;
                }
                p=p->next;
            }
            p=p->next;

    }
    print();
    cout << endl;
}

