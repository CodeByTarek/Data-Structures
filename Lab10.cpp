#include<bits/stdc++.h>
using namespace std;
#include<limits.h>
int VISITED[100];
int DIST[100];
int PARENT[100];
int TIME=0;
int FINISH[100];
int DISC[100];
class Graph{
public:
    list<int>* lists;
    int total_nodes;
    int start_node;
    Graph(int n, int node){
        total_nodes = n;
        lists = new list<int> [total_nodes];
        start_node = node;
    }
    print(){
        list<int>::iterator it;
        for(int i=0;i<total_nodes;i++){
                cout<< i+1<< "-> ";
            for(it = lists[i].begin(); it!=lists[i].end();it++){
                cout<<*it<< " ";
            }
            cout<<endl;
        }

    }


};
void BFS(Graph* g){

    queue<int>* q= new queue<int>;
    int src;
    src= g->start_node-1;

    q->push(src);

    VISITED[src]=1;
    DIST[src]=0;
    PARENT[src]=-1;
    list<int>::iterator it;
    while(!q->empty()){

         int k= q->front();

         for(it = g->lists[k].begin(); it!=g->lists[k].end();it++){
                //int v= *it-1;
            if(VISITED[*it-1]==0){
                q->push(*it-1);
                VISITED[*it-1]=1;
                PARENT[*it-1]=k;
                DIST[*it-1]=DIST[k]+1;
            }

         }
         q->pop();

    }


}

void printNew(Graph* g){
    for(int i=0;i<g->total_nodes;i++){
        cout<<i+1<<"-->"<< "dist: "<< DIST[i]<< "Parent: "<< PARENT[i]+1<<endl;
    }
}

void DFS_visit(Graph*g,int k){
     TIME=TIME+1;
     DISC[k]=TIME;
     VISITED[k]=1;
     list<int>::iterator it;
     for(it = g->lists[k].begin(); it!=g->lists[k].end();it++){
                int v= *it-1;
            if(VISITED[v]==0){
                PARENT[*it-1]=k;
                DFS_visit(g,v);
            }

         }
         TIME++;
         FINISH[k]=TIME;


}
void DFS(Graph* g){
    for(int i=0;i<100;i++){
        PARENT[i]=0;
        VISITED[i]=0;
        DISC[i]=-1;

    }
    TIME= 0;
    PARENT[g->start_node-1]=-1;
    DFS_visit(g,g->start_node-1);
    for (int i=0;i<g->total_nodes;i++){
        if(VISITED[i]==0){
            DFS_visit(g,i);
        }
    }

}
void DFSPrint(Graph*g){
    for(int i=0;i<g->total_nodes;i++){
        cout<<i+1<<"-->"<< "dist: "<< DISC[i]<<"/"<<FINISH[i]<< " Parent: "<< PARENT[i]+1<<endl;
    }

}

int main(){
    cout<< "Graph Input"<<endl;
    int n;
    cout<< "Number of Nodes: ";
    cin >> n;
    cout<< "Enter Start Node: ";
    int s;
    cin>>s;
   // cout<< "Enter  Node: ";
    int v;

    Graph* g = new Graph(n,s);

    for (int i=0;i<g->total_nodes;i++){
        cout << " Enter Adjacency List for "<< i+1<< ":(-1 tp stop)";
        while(true){
            cin>>v;
            if(v==-1){
                break;
            }
            g->lists[i].push_back(v);
        }

    }

    g->print();

    BFS(g);
    cout<< "BSF"<<endl;
    printNew(g);

    DFS(g);
    cout<< "DSF"<<endl;
    DFSPrint(g);

}
