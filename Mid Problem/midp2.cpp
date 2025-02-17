#include<bits/stdc++.h>

using namespace std;
class Node{
public:
    char c;
    Node *next;
};
//Node* head=NULL;
//Node* tail= NULL;

/*Node* newNode(char ch){
    Node* tmp;
    tmp->c = ch;
    tmp->next=NULL;
    return tmp;
}*/

class List{
public:
    Node *head,*tail;
    List(){
        head=NULL;
        //tail=NULL;
    }
   void* push(char car);
   //bool check(Node* head1,Node* head2);

};
void* List::push(char car){
    Node* node=new Node();
    node->c= car;
    node->next=NULL;
    if(head==NULL){
        head=node;
        //tail=node;

    }
    else{
        Node* cur= head;
        while(cur->next!=NULL){

            cur=cur->next;
        }
        cur->next= node;
           }

}

bool check(Node* head1,Node* head2){


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
        return false;
    }
    else{
            int i=0;
        for(i=0;i<c1;i++){
            if(cur11->c!=cur22->c){
                return false;
            }
            cur11=cur11->next;
            cur22=cur22->next;
        }
        return true;
    }
}



int main(){
 string s1;
 string s2;

    List* list1= new List();
    List* list2= new List();


 getline(cin,s1);
int k= s1.length();
 cout<<endl;
 int i;
 for(i=0;i<k;i++){
    list1->push(s1[i]);
 }
 getline(cin , s2);
 int l= s2.length();
 cout<< endl;
 for(i=0;i<l;i++){
   list2->push(s2[i]);
 }






 if(check(list1->head,list2->head)){
    cout<<"Same string";
 }
 else{
    cout<< "Not Same string";
 }
}
