#include<math.h>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int* key;
        Node* next;
        Node(){
            next=NULL;
        }
        Node(int k){
            key=new int (k);
            next=NULL;
        }
};

class Stack{
    public:
        Node* head;
        Stack(){
            head=NULL;
        }
        void push(int key);
        void pop();
        int* top();
        void print();
        bool empty();
};

void Stack::push(int k){
    Node* node = new Node(k);
    node->next = head;
    head = node;
}

void Stack::pop(){
    if(head==NULL){
        cout << "Stack is empty" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;

    delete temp;
}
int* Stack::top(){
    return head->key;
}
bool Stack::empty(){
    if(head==NULL)
        return true;
    else
        return false;
}

void Stack::print(){
    Node* p=head;
    if(p==NULL){
        cout << "Stack is empty" << endl;
        return;
    }
    while(p!= NULL){
        cout <<*(p->key)<< " ";
        p = p->next;
    }
    cout << endl;
}

int main(){
    int digit1,opt,digit2,i=0,result=0;
    Stack* stack1 = new Stack;
    cout<<"Enter Postfix Notation: ";

    char ch[10000];
    cin.getline(ch,10000);

    while(ch[i]!='\0'){
            if(ch[i]>='0' && ch[i]<='9'){
                stack1->push(ch[i]);
            }

            else if(ch[i]=='+'){
                digit1=*(stack1->top());

                if(digit1>=48){
                    digit1=digit1-48;
                }
                stack1->pop();
                digit2=*(stack1->top());
                if(digit2>=48){
                    digit2=digit2-48;
                }
                stack1->pop();
                result=digit2+digit1;
                stack1->push(result);
            }

             else if(ch[i]=='-'){
                digit1=*(stack1->top());

                if(digit1>=48){
                    digit1=digit1-48;
                }
                stack1->pop();
                digit2=*(stack1->top());
                if(digit2>=48){
                    digit2=digit2-48;
                }
                stack1->pop();
                result=digit2-digit1;
                stack1->push(result);
            }

            else if(ch[i]=='*'){
                digit1=*(stack1->top());
                if(digit1>=48){
                    digit1=digit1-48;
                }
                stack1->pop();
                digit2=*(stack1->top());
                if(digit2>=48){
                    digit2=digit2-48;
                }
                stack1->pop();
                result=digit2*digit1;
                stack1->push(result);
            }

             else if(ch[i]=='/'){
                digit1=*(stack1->top());

                if(digit1>=48){
                    digit1=digit1-48;
                }
                stack1->pop();
                digit2=*(stack1->top());
                if(digit2>=48){
                    digit2=digit2-48;
                }
                stack1->pop();
                result=digit2/digit1;
                stack1->push(result);
            }

            else if(ch[i]=='^'){
                digit1=*(stack1->top());

                if(digit1>=48){
                    digit1=digit1-48;
                }
                stack1->pop();
                digit2=*(stack1->top());
                if(digit2>=48){
                    digit2=digit2-48;
                }
                stack1->pop();
                result=pow(digit2,digit1);
                stack1->push(result);
            }

            else{
                cout<<endl<<"Wrong input"<<endl;
            }
        i++;
    }
    cout<<endl<<"Result: ";
    stack1->print();

    return 0;
}
