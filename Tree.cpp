#include<bits/stdc++.h>
#include<math.h>

using namespace std;

class Node{
    public:
        char data;
        Node* left;
        Node* right;
};

Node* createNode(char key){
    char l,r;
    if(key=='x'){
        return NULL;
    }
    Node* node=new Node();
    node->data=key;
    node->left=NULL;
    node->right=NULL;
    cout<<"Enter Left: ";
    cin>>l;
    node->left=createNode(l);
    cout<<"Enter Right: ";
    cin>>r;
    node->right=createNode(r);
    return node;
}

void preOrder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root){
    if(root==NULL){
        return;
    }

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(Node* root){
    if(root==NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int main(){
    char ch;
    cout<<"Enter key: ";
    cin>>ch;
    Node* root=createNode(ch);
    cout<<endl<<"PreOrder: ";
    preOrder(root);
    cout<<endl<<"InOrder: ";
    inOrder(root);
    cout<<endl<<"PostOrder: ";
    postOrder(root);


    return 0;
}
