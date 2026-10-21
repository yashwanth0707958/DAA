#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
const int INF = 1e9; 
 vector<vector<int>> dist = {
        {0, 3, 10, INF},
        {INF, 0, 1, 7},
        {INF, INF, 0, 2},
        {INF, INF, INF, 0}
};

 int V = dist.size();
 for (int k = 0; k < V; ++k) {        
 for (int i = 0; i < V; ++i) {    
 for (int j = 0; j < V; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    cout << "Shortest distance matrix:\n";
    for (int i = 0; i < V; ++i) {
    for (int j = 0; j < V; ++j) {
    if (dist[i][j] == INF)
    cout << "INF\t";
    else
    cout << dist[i][j] << "\t";
        }
        cout << "\n";
    }

    return 0;
}
