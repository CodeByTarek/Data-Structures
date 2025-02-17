class Node{
    public:
        int* key;
        Node* next;
        Node(){next = NULL;}
        Node(int value){
            key = new int (value);
            next = NULL;
        }
        ~Node(){}
};
