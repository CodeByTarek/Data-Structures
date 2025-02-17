#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
    list<int>* lists;
    int total_nodes;
    int start_node;
    Graph(int n, int node){
        total_nodes = n;
        lists = new list<int> [n];
        start_node = node;
    }
    print(){
        list<int> :: iterator it;
        for(int i=0; i<total_nodes; i++){
            cout << i+1 << "--> ";
            for(it=lists[i].begin(); it!=lists[i].end(); it++){
                cout << *it << " ";
            }
            cout << endl;
        }
    }

};
int main(){
    int n, node;
    cout << "Graph Input using adjacency list." << endl;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter start node: ";
    cin >> node;
    Graph* g1 = new Graph(n, node);
    for(int i=0; i<n; i++){
        cout << "Enter adjacency list for node " << i+1 << ": (-1 to stop)";
        while(true){
            cin >> node;
            if(node == -1)
                break;
            g1->lists[i].push_back(node);
        }
    }
    g1->print();
}
