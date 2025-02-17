#include<bits/stdc++.h>

using namespace std;
class Node{
public:
    char c;
    Node *next;
};

class List{
public:
    Node *head;
    List(){
        head=NULL;
    }
   void* push(char car);
};

void* List::push(char ch){
    Node* node=new Node();
    node->c= ch;
    node->next=NULL;
    if(head==NULL){
        head=node;
    }
    else{
        Node* cur= head;
        while(cur->next!=NULL){

            cur=cur->next;
        }
        cur->next= node;
           }

}

int compare(Node* head1,Node* head2){

    Node* cur1=head1;
    Node* cur2=head2;
    Node* cur11=head1;
    Node* cur22=head2;
    int c1=0,c2=0;
    while(cur1!=NULL){
        c1++;
        cur1=cur1->next;
    }
    while(cur2!=NULL){
        c2++;
        cur2=cur2->next;
    }

    if (c1!=c2){
        if(c1>c2){
            return 1;
        }
        else if(c1<c2){
            return -1;
        }
    }
    else if(c1==c1){
        int i=0,count=0;
        for(i=0;i<c1;i++){
            if(cur11->c==cur22->c){
                count++;
            }
            cur11=cur11->next;
            cur22=cur22->next;
        }
        if(count==c1 && count==c2){
            return 0;
        }
        else{
            cout<<"Dosn't match"<<endl;
            exit(0);
        }
    }
}

int main(){
 string s1;
 string s2;

    List* list1= new List();
    List* list2= new List();

 cout<<"Enter First String: ";
 getline(cin,s1);
 int k= s1.length();
 cout<<endl;
 int i;
    for(i=0;i<k;i++){
        list1->push(s1[i]);
    }
 cout<<"Enter Second String: ";
 getline(cin , s2);
 int l= s2.length();
 cout<< endl;
    for(i=0;i<l;i++){
        list2->push(s2[i]);
        }

 cout<<compare(list1->head,list2->head)<<endl;

 return 0;
}
