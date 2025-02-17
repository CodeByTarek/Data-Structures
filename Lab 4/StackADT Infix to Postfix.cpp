#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        void* key;
        Node* next;
};

class Stack{
    public:
        Node* head;
        Stack(){
            head=NULL;
        }
        void push(void* key, int bytes);
        void pop();
        void* top();
        bool empty();
};

void Stack::push(void* key, int bytes){
    Node* node = new Node;
    node->key = malloc(bytes);
    memcpy(node->key, (char*) key, bytes);
    node->next = head;
    head = node;
    //cout << "item pushed" << endl;
}

void Stack::pop(){
    if(head==NULL){
        cout << "Stack is empty" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;

    delete temp;
    //cout << "item popped" << endl;
}
void* Stack::top(){
    return head->key;
}
bool Stack::empty(){
    if(head==NULL)
        return true;
    else
        return false;
}

template<typename T>
void print(Stack*, T*);

int main(){
    //Stack* stack1 = new Stack;
    Stack* stack=new Stack;
    char value[1024];
    cin.getline(value,1024);
    char output[10];
    int i=0;
    while(value[i]!='\0'){
        if(value[i]=='('|| value[i]=='+'|| value[i]=='-' || value[i]=='*'|| value[i]=='/'){
            stack->push(&value[i],1);
           }
        else if(value[i]>='a' && value[i]<='z'){
            output[i]=value[i];
        }
        else if(value[i]==')'){
            while(*(char*)stack->top()!='('){
                  if(*(char*)stack->top()!=')'||*(char*)stack->top()!='('){
                    output[i]=*(char*)stack->top();
                  }
                stack->pop();
            }
        }
        i++;

    }
    int j=0;
    while(output[j]!='\0'){
        cout<<output[j]<<endl;
        j++;
    }
    //char key;
    // reading a character array
    //char name[1024];
    //cin.getline(name, 1024);

    // reading a string
    //string name;
    //getline(cin, name);

   /* cout << "This program will create a CHARACTER stack" << endl;
    // creating a stack
    cout << "Enter items to push (x to stop)" << endl;
    while(true){
        cin >> key;
        if(key == 'x')
            break;
        stack1->push(&key, 1);
    }
    // popping two elements
    stack1->pop();
    stack1->pop();
    // printing the top after popping two elements
    cout << "Top: " << *(char *)stack1->top() << endl;
    // printing the complete stack using a template function
    print(stack1, &key);*/
}

// using a template fucntion (Generic methods in Java)
// if you don't understand, write your own print function accordingly
template <typename T>
void print(Stack* stack, T* a){
    Node* p = stack->head;
    if(p==NULL){
        cout << "Stack is empty" << endl;
        return;
    }
    while(p!= NULL){
        cout << *(T*) (p->key)<< " ";
        p = p->next;
    }
    cout << endl;
}

