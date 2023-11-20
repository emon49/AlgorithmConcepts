// https://www.codingninjas.com/studio/problems/create-a-graph-and-print-it_1214551?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;
template <typename T>
class Graph {
public:
    unordered_map<T, vector<T>> adjList;
    void addEdge(T u, T v, bool directed) {
        adjList[u].push_back(v);
        if (!directed) {
            adjList[v].push_back(u);
        }
    }
    void printGraph() {
        for (auto i : adjList) {
            cout << i.first << "-> ";
            for (auto j : i.second) {
                cout << j << " ,";
            }
            cout << endl;
        }
    }
};
int main() {
    int n, m, u, v;
    Graph<int> g;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }
    g.printGraph();
}
/*
5 6
0 1
1 2
2 3
3 1
3 4
0 4

*/