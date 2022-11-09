#include <iostream>
#include <iterator>
#include <list>
using namespace std;

class Graph {
    protected:
        int v;
        list<int> adj[100];

    public:
    Graph(int len) {
        v = len;
    }

    void setLen(int len){
        v = len;
        adj[v];
    }

    void addEdge(int u, int v){
        if(adj[u].empty()) adj[u].push_back(u);
        if(adj[v].empty()) adj[v].push_back(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void showGraph(){
        for (int i = 0; i <= v; i++)
        {
            list<int>::iterator it;
            for(it = adj[i].begin(); it != adj[i].end(); ++it){
                cout << *it << " ";
            }
            cout << endl;
        }
    }
};


int main(){
    Graph graph1(5);

    graph1.addEdge( 0, 2);
    graph1.addEdge( 0, 8);
    graph1.addEdge( 1, 10);
    graph1.addEdge( 1, 8);
    graph1.addEdge( 1, 5);
    graph1.addEdge( 2, 35);
    graph1.addEdge( 3, 6);

    graph1.showGraph();

}
