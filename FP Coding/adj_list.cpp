#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

bool foundDFSNode = false;

class Graph
{
  int numVertices;
  list<pair<int, int>> *adjLists;
  map<int, bool> visitedDfsNode;
  bool *visited;

  public:
    Graph(int vertices);
    void addEdge(int src, int dest, int weight);
    void BFS(int startVertex, int endVertex);
    void shortestPath(int src, int dest);
    void DFS(int v, int end);
    void showList();
};

// Create a graph with given vertices,
// and maintain an adjacency list
Graph::Graph(int vertices)
{
  numVertices = vertices;
  adjLists = new list<pair<int, int>>[vertices];
}

// Add edges to the graph
void Graph::addEdge(int src, int dest, int weight)
{
  adjLists[src].push_back(make_pair(dest, weight));
  // adjLists[dest].push_back(src);
}

// BFS algorithm
void Graph::BFS(int startVertex, int endVertex)
{
  visited = new bool[numVertices];
  for (int i = 0; i < numVertices; i++)
    visited[i] = false;

  list<int> queue;

  visited[startVertex] = true;
  queue.push_back(startVertex);

  // list<int>::iterator i;
  list<pair<int, int>>::iterator i;

  while (!queue.empty())
  {
    int currVertex = queue.front();
    // Fungsi memberhentikan BFS
    if (currVertex == endVertex)
    {
      break;
    }
    //
    cout << "(V" << currVertex << ")";
    queue.pop_front();

    for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i)
    {
      int adjVertex = (*i).first;
      if (!visited[adjVertex])
      {
        visited[adjVertex] = true;
        queue.push_back(adjVertex);
      }
    }
  }
  cout << endl;
}

void Graph::shortestPath(int src, int dest)
{
    // Create a set to store vertices that are being
    // processed
    set< pair<int, int> > setds;
 
    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    vector<int> dist(numVertices, INF);
 
    // Insert source itself in Set and initialize its
    // distance as 0.
    setds.insert(make_pair(0, src));
    dist[src] = 0;
 
    /* Looping till all shortest distance are finalized
       then setds will become empty    */
    while (!setds.empty())
    {

        // The first vertex in Set is the minimum distance
        // vertex, extract it from set.
        pair<int, int> tmp = *(setds.begin());
        setds.erase(setds.begin());
 
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        int u = tmp.second;
 
        // 'i' is used to get all adjacent vertices of a vertex
        list<pair<int, int>>::iterator i;
        for (i = adjLists[u].begin(); i != adjLists[u].end(); ++i)
        {   
            // Get vertex label and weight of current adjacent
            // of u.
            int v = (*i).first;
            int weight = (*i).second;
            //    If there is shorter path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                if (dist[v] != INF)
                {
                  setds.erase(setds.find(make_pair(dist[v], v)));
                }
 
                // Updating distance of v
                dist[v] = dist[u] + weight;
                setds.insert(make_pair(dist[v], v));
            }
        }
    }
 
    // Print shortest distances stored in dist[]
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < numVertices; ++i)
    {
      if (i == dest)
      {
        break;
      }
      
      printf("%d \t\t %d\n", i, dist[i]);
    }
}

void Graph::DFS(int v, int end)
{
    if (foundDFSNode == false)
    {
    // Mark the current node as visited and
    // print it
    visitedDfsNode[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent
    // to this vertex
    list<pair<int, int>>::iterator i;
 
    // for (i = adjMatrix[v].begin(); i != adjMatrix[v].end(); ++i)
    // {
    //   if (visitedDfsNode[(*i).first] == end)
    //   {
    //     foundDFSNode = true;
    //     break;
    //   }
    // }

      for (i = adjLists[v].begin(); i != adjLists[v].end(); ++i)
      {

        if (v == end)
        {
          foundDFSNode = true;
          // break;
        }
        if (!visitedDfsNode[(*i).first])
        {
          DFS((*i).first, end);
        }
      }
    }
    
    else
    {

    }
}

void Graph::showList()
{
  for (int i = 0; i < numVertices; i++)
  {
    cout << i << ": ";
    list<pair<int, int>>::iterator it;
      for(it = adjLists[i].begin(); it != adjLists[i].end(); ++it){
        cout << (*it).first << " ";
      }
    cout << endl;
  }
}

int main()
{
  Graph main(23);
  main.addEdge(0, 1, 1);
  main.addEdge(0, 2, 1);
  main.addEdge(0, 3, 1);
  main.addEdge(1, 4, 2);
  main.addEdge(1, 5, 1);
  main.addEdge(5, 7, 1);
  main.addEdge(4, 8, 1);
  main.addEdge(8, 15, 2);
  main.addEdge(15, 16, 1);
  main.addEdge(16, 17, 2);
  main.addEdge(17, 18, 2);
  main.addEdge(18, 19, 1);
  main.addEdge(19, 20, 1);
  main.addEdge(20, 21, 1);
  main.addEdge(19, 22, 1);
  main.addEdge(2, 9, 3);
  main.addEdge(2, 6, 4);
  main.addEdge(3, 10, 4);
  main.addEdge(10, 11, 1);
  main.addEdge(11, 12, 2);
  main.addEdge(12, 13, 3);
  main.addEdge(13, 14, 1); //selesai


  cout << endl << "=============== BFS ===============" << endl;
  main.BFS(0, 14);
  cout << endl << "=============== DFS ===============" << endl;
  main.DFS(0, 14);
  cout << endl << endl << "=============== Dijkstra ===============" << endl;
  main.shortestPath(0, 14);
  cout << endl << "=============== Adj. Lists ===============" << endl;
  main.showList();

  return 0;
}