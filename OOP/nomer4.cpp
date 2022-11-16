#include <bits/stdc++.h>
#include <iterator>
#include <list>

using namespace std;

class Vertex {
    protected:
        list<int> adj;
    
    public:
        void addEdge(int u, int v){
            if(adj.empty()) 
                adj.push_back(u);
                adj.push_back(v);
        }

        void showList(){
            list<int>::iterator it;
            for(it = adj.begin(); it != adj.end(); ++it){
                cout << *it << " ";
            }
            cout << "\n";
        }
};

class Graph {
    protected:
        int len;
        Vertex vertex[100];
        

    public:
        Graph(int _len) {
            len = _len;
        }

    void AddEdgetoVertex(int u, int v){
            vertex[u].addEdge(u,v);
            vertex[v].addEdge(v,u);
        }

    void showAllVertex(){
            for (int i = 0; i < len; i++)
            {
                vertex[i].showList();
            }
            
        }
};


int main(){
    Graph graph1(5);

    graph1.AddEdgetoVertex( 0, 2);
    graph1.AddEdgetoVertex( 0, 6);
    graph1.AddEdgetoVertex( 1, 4);
    graph1.AddEdgetoVertex( 1, 8);
    graph1.AddEdgetoVertex( 1, 3);
    graph1.AddEdgetoVertex( 2, 1);
    graph1.AddEdgetoVertex( 3, 3);

    graph1.showAllVertex();
}