#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    char c;
    Node* next;
    Node* prev;
};

class List{
    public:
    Node *head, *tail;
    List(){
        head=NULL;
        tail=NULL;
    }
    void push(char ch);
    void print();
    void removeVowels(Node* head);
};


int main(){
    string s1;
    List* list = new List();
    cout<<"Enter String: ";
    getline(cin,s1);
    int i,l;
    l=s1.length();
    for(i=0;i<l;i++){
            list->push(s1[i]);

    }
    list->print();
    list->removeVowels(list->head);
    list->print();
    return 0;
}

void List::push(char ch){
    Node* node=new Node();
    node->c=ch;
    node->next=NULL;
    node->prev=NULL;

    if(head==NULL){
        head=node;
        tail=node;
    }
    else{
        tail->next=node;
        node->prev=tail;
        node->next=NULL;
        tail=node;
    }
}
void List::print(){
    Node* p=head;
    if(p==NULL){
        cout<<"List is empty";

    }
    else{
        while(p!=NULL){
        cout<<(p->c)<<" ";
        p=p->next;
    }
 }

    cout<<endl;

}
void List::removeVowels(Node* h){
    Node* p=h;

//    return;
    if(head==tail){
        if(head->c=='a'||head->c=='e'||head->c=='i'||head->c=='o'||head->c=='u'){
            head=NULL;
            tail=NULL;
            return;
        }
    }
    if((tail->c)=='a' || (tail->c)=='e' || (tail->c)=='i' || (tail->c)=='o' || (tail->c)=='u'){
            Node* l=head;
            tail->prev->next=NULL;
            }

   while(p->next!=NULL){
       if((p->next->c)=='a' || (p->next->c)=='e' || (p->next->c)=='i' || (p->next->c)=='o' || (p->next->c)=='u'){
           Node* temp=p->next;
           p->next=p->next->next;
          // p->next->next->prev=p;
           delete temp;

        }

       p=p->next;

   }
   Node* f=h;
   if((f->c)=='a' || (f->c)=='e' || (f->c)=='i' || (f->c)=='o' || (f->c)=='u'){


        Node* t=head;
        head=head->next;
        head->prev=NULL;
        //Node* t=head;
        delete t;

    }

}


