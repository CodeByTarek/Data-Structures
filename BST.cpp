#include<bits/stdc++.h>
#include<math.h>

using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

};

class BST{
    public:
        Node* root;
        Node* insert (Node* root, int key);
        void inorder (Node* root);
        Node* search(Node* root, int key);
        Node* findMinimum(Node*  root);
        Node* findMaximum(Node*  root);
        Node* deleteKey(Node* root, int key);
};

Node* BST::deleteKey(Node* root, int key){
    if(root==NULL){
        return root;
    }
    if(root->data > key){
        root->left = deleteKey(root->left,key);
    }
    if(root->data < key){
        root->right = deleteKey(root->right,key);
    }
    //case 1 (no child)
    if(root->data == key){
        if(root->left==NULL && root->right==NULL){
            Node* temp = root;
        delete temp;
        return NULL;
        }

         //case 2(1 child)
    else if(root->left==NULL || root->right==NULL){
        if(root->left!=NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        else{
            Node* temp=root->right;
            delete root;
            return temp;
        }
    }
    //case 3 (2 child)
    else{
         Node* minRight = findMinimum(root->right);
         root->data = minRight->data;
         root->right = deleteKey(root->right, root->data);
    }

  }
     return  root;

}

Node* BST::findMinimum(Node* root){
    if(root->left==NULL){
        return root;
    }
    return findMinimum(root->left);
}

Node* BST::findMaximum(Node* root){
    if(root->right==NULL){
        return root;
    }
    return findMaximum(root->right);
}



Node* BST::search(Node* root, int key){
    if(root==NULL || root->data==key){
        return root;
    }
    else if(root->data < key){
        return search(root->right,key);
    }
    else if(root->data > key){
        return search(root->left,key);
    }

}

Node* BST::insert (Node* root1, int key){

    if(root1==NULL){
        Node* node=new Node;
        node->left=NULL;
        node->right=NULL;
        node->data=key;
        root1=node;
        return root1;
    }
    if(root1->data > key){
        root1->left = insert(root1->left,key);
    }

    if(root1->data < key){
        root1->right = insert(root1->right,key);
    }
    return root1;
}

void BST::inorder (Node* root){
     if(root==NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    BST* bst=new BST();
    bst->root=NULL;
    //Node* root;
    int key,value,value1;
    cout<< "Create nodes in a BST. Enter -1 to stop. "<<endl;
    while(true){

        cin>>key;
        if(key==-1){
            break;
        }
        //insert
        bst->root = bst->insert(bst->root,key);
    }
        //print
        bst->inorder(bst->root);
        //search
        cout<<endl<<endl<<"Enter a key to search: ";
        cin>>value;
        Node* node=NULL;
        node=bst->search(bst->root,value);
        cout<<"Found: "<<node->data<<endl;

        //Find Minimum
        Node* node1 = bst->findMinimum(bst->root);
        cout<<"Minimum: "<<node1->data<<endl;

        //Find Maximum
        Node* node2 = bst->findMaximum(bst->root);
        cout<<"Maximum: "<<node2->data<<endl;

        //delete
        cout<<endl<<endl<<"Enter a key to delete: ";
        cin>>value1;

        bst->root = bst->deleteKey(bst->root,value1);
        bst->inorder(bst->root); // to print
}
