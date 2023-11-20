// https://www.codingninjas.com/studio/problems/cycle-detection-in-undirected-graph_1062670?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION
#include <queue>
#include <vector>
#include <string>
using namespace std;

bool isCycleBFS(vector<vector<int>> &adjList, vector<bool> &visited, vector<int> &parent, int src){
    queue<int> q;
    q.push(src);
    visited[src] = true;
    parent[src] = -1;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(auto neighbour:adjList[front]){
            if(visited[neighbour] == true && neighbour != parent[front])    return true;
            if (!visited[neighbour]) {
              q.push(neighbour);
              visited[neighbour] = true;
              parent[neighbour] = front;
            }
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<vector<int>> adjList(n+1);
    int u,v;
    vector<bool> visited(n+1, false);
    vector<int> parent(n+1);
    for(int i=0; i<edges.size(); i++){
        u= edges[i][0];
        v= edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            if(isCycleBFS(adjList, visited, parent, i)){
                return "Yes";
            }
        }
    }
    return "No";
}
