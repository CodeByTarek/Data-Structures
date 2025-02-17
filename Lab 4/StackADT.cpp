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
    cout << "item pushed" << endl;
}

void Stack::pop(){
    if(head==NULL){
        cout << "Stack is empty" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;

    delete temp;
    cout << "item popped" << endl;
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
void sequence(string exp);

int main(){
    Stack* stack1 = new Stack;
    char key;
    // reading a character array
    //char name[1024];
    //cin.getline(name, 1024);

     //reading a string
    //string name;
    //getline(cin, name);
    string value;
    getline(cin,value);
    sequence(value);



    cout << "This program will create a CHARACTER stack" << endl;
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
    //print(stack1, &key);
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
/*void sequence(Stack* stack1){
    Node* p=stack1->head;
    while(p!=NULL){
        if(*(p->key)=='('||*(p->key)='{'||*(p->key)='['){
            stack1=p;
           }
    }
}*/
void sequence(string value){
    int i=0;
    for(i=0;i<value.length();i++){
        //cout<<exp<<" "<<endl;
        Stack* s1;
        if(value[i]=='('||value[i]=='{'||value[i]=='['){
            s1->push(&value[i],1);
       }
       if(value[i]==')'||value[i]=='}'||value[i]==']'){
            if(*(char *)(s1->top())==value[i]){
                //s1->pop();
                cout<<""<<endl;
            }

       }

    }

}
