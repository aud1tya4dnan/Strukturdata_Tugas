#include <iostream>
#include <list>
#include <queue>
#include <iterator>

using namespace std;

class Graf
{
private:
    int vertex;
    list<int> adj[100];

public:
    Graf(int v)
    {
        vertex = v;
    }
    void addEdge(int v1, int v2)
    {
        adj[v1].push_back(v2);
    }
    void print()
    {
        for (int i = 1; i <= vertex; i++)
        {
            cout << i << "->";
            list<int>::iterator it;
            for (it = adj[i].begin(); it != adj[i].end(); it++)
            {
                cout << *it << " ";
            }
            cout << endl;
        }
    }
    void bfs(int end)
    {
        queue<int> q;
        q.push(1);

        int visited[50];
        for (int i = 1; i <= 50; i++)
        {
            visited[i] = 0;
        }
        visited[1] = 1;

        while (!q.empty())
        {
            int front = q.front();
            list<int>::iterator it;

            for (it = adj[front].begin(); it != adj[front].end(); it++)
            {
                if (visited[*it] == 0)
                {
                    q.push(*it);
                    visited[*it] = 1;
                }
            }

            cout << front << " ";

            if (q.front() == end)
            {
                break;
            }
            q.pop();
        }
    }
};

int main()
{
    Graf graf(20);
    graf.addEdge(1, 2);
    graf.addEdge(1, 3);
    graf.addEdge(1, 4);
    graf.addEdge(2, 8);
    graf.addEdge(2, 10);
    graf.addEdge(2, 14);
    graf.addEdge(3, 7);
    graf.addEdge(5, 6);
    graf.addEdge(8, 9);
    graf.addEdge(10, 11);
    graf.addEdge(11, 12);
    graf.addEdge(12, 13);
    graf.addEdge(14, 15);
    graf.addEdge(14, 16);
    graf.addEdge(15, 17);
    graf.addEdge(17, 18);
    graf.addEdge(18, 19);
    graf.addEdge(16, 20);
    graf.print();

    cout << endl;

    int end;
    cin >> end;
    graf.bfs(end);

    return 0;
}