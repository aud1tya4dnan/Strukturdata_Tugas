#include <iostream>
#include <list>
#include <queue>
#include <iterator>

using namespace std;

class Graf{
    private:
        int vertex;
        int matrix[20][20];

    public:
        Graf(int v){
            vertex = v;
            for(int i = 1; i <= 20; i++){
                for(int y = 1; y <= 20; y++){
                    matrix[i][y] = 0;
                }
            }
        }
        void addEdge(int v1, int v2){
            matrix[v1][v2] = 1;
        }
        void print(){
            for(int i = 1; i <= 20; i++){
                cout << i << "|";
                for(int y = 1; y <= 20; y++){
                    cout << matrix[i][y] << " ";
                }
                cout << endl;
            }
        }
        void bfs(int end){
            queue<int> q;
            q.push(1);

            int visited[20];
            for(int i = 1; i <= 20; i++){
                visited[i] = 0;
            }
            visited[1] = 1;

            while(!q.empty()){
                int front = q.front();
                list<int>::iterator it;

                for(int i = 1; i <= 20; i++){
                    if(matrix[front][i] == 1 && visited[i] != 1){
                        q.push(i);
                        visited[i] = 1;
                    }
                }

                cout << front << " ";

                if(q.front() == end){
                    break;
                }

                q.pop();
            }
        }
};

int main(){
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

    graf.bfs(16);

    return 0;
}