#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

bool foundDFSNode = false;

class Graph
{
  int numVertices;
  list<pair<int, int>> *adjMatrix;
  map<int, bool> visitedDfsNode;
  bool *visited;

  public:
    Graph(int vertices);
    void addEdge(int src, int dest, int weight);
    void BFS(int startVertex, int endVertex);
    void shortestPath(int src, int dest);
    void showMatrix();
    void DFS(int v, int end);
};

Graph::Graph(int vertices)
{
  numVertices = vertices;
  adjMatrix = new list<pair<int, int>>[vertices];
}

// Add edges to the graph
void Graph::addEdge(int src, int dest, int weight)
{
  adjMatrix[src].push_back(make_pair(dest, weight));
  adjMatrix[src].sort();
}

void Graph::BFS(int startVertex, int endVertex)
{
  visited = new bool[numVertices];
  for (int i = 0; i < numVertices; i++)
    visited[i] = false;

  list<int> queue;

  visited[startVertex] = true;
  queue.push_back(startVertex);

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
    cout <<  currVertex << " ";
    queue.pop_front();

    for (i = adjMatrix[currVertex].begin(); i != adjMatrix[currVertex].end(); ++i)
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
    set<pair<int, int>> setds;
 
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
        for (i = adjMatrix[u].begin(); i != adjMatrix[u].end(); ++i)
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

      for (i = adjMatrix[v].begin(); i != adjMatrix[v].end(); ++i)
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

void Graph::showMatrix()
{
  for (int i = 0; i < numVertices; i++)
  {
    list<pair<int, int>>::iterator it;

    int track = 0;
    int through = 0;
    for (it = adjMatrix[i].begin(); it != adjMatrix[i].end(); ++it)
    {
      // int track = 0;
      int temp = (*it).first;
      if (through == 0)
      {
        while (track < temp)
        {
          cout << "0 ";
          ++track;
          through++;
        }
      }
      else
      {
        while ((track + 1) < temp)
        {
          cout << "0 ";
          ++track;
          through++;
        }
      }
      cout << "1 ";
      through++;
    }
    while ((numVertices - through) > 0)
    {
      through++;
      cout << "0 ";
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
  main.addEdge(13, 14, 1);

  cout << endl << "============= BFS ==============" << endl;
  main.BFS(0, 14);
  cout << endl << "============= DFS ==============" << endl;
  main.DFS(0, 14);
  cout << endl << endl << "============= Dijkstra ===========" << endl;
  main.shortestPath(0, 14);
  cout << endl << "============= Adj. Matrix ==============" << endl;
  main.showMatrix();

  return 0;
}