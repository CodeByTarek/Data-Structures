#include<bits/stdc++.h>
using namespace std;

class Node{
    char* key;
    Node* next;
    Node(){
    next=NULL;
    }
    Node(char value){
        key=new char(value);
        next=NULL;
    }
    ~Node(){}
};
Node* head1=NULL;
Node* head2=NULL;
Node* tail1=NULL;
Node* tail2=NULL;
void menu();
void pushHead1(char key);
void pushHead2(char key);

int main(){
    cout<<"\n";
    int choice;
    int key;
    while(true){
        switch(choice){
            cout<<"Enter choice: ";
            cin>>choice;
            case 1:
                cout<<"Enter key: ";
                cin>>key;
                pushHead1(key);
                break;
            case 2:
                cout<<"Enter key: ";
                cin>>key;
                pushHead2(key);
                break;
            /*case 3:
                compare();
                break;
            case 4:
                printhead1();
                break;
            case 4:
                printhead2();
                break;*/



        }
    }

    return 0;
}
void menu(){
    cout<<"(1)head1................(2)head2.....................(3)compare..............(4)print head1......(5)print head2";
}
void pushHead1(char key){
    Node* node=new Node(key);
    node->next=head1;
    head1=node;
    if(tail1==NULL){
        tail1=head1;
    }
}
void pushHead2(char key){
    Node* node=new Node(key);
    node->next=head2;
    head2=node;
    if(tail2==NULL){
        tail2=head2;
    }
}
