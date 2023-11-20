// https://www.codingninjas.com/studio/problems/cycle-detection-in-undirected-graph_1062670?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION
#include <queue>
#include <vector>
#include <string>
using namespace std;
bool isCycleDFS(vector<vector<int>> &adjList, vector<bool> &visited, int parent, int src){
    visited[src] = true;
    for(auto neighbour:adjList[src]){
        if(!visited[neighbour]){
            bool res =  isCycleDFS(adjList,visited,src,neighbour);
            if(res) return true;
        }
         else if(parent != neighbour)  return true;
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<vector<int>> adjList(n+1);
    int u,v;
    vector<bool> visited(n+1, false);
    for(int i=0; i<edges.size(); i++){
        u= edges[i][0];
        v= edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            if(isCycleDFS(adjList, visited, -1, i)){
                return "Yes";
            }
        }
    }
    return "No";
}

/*
bool isCycleDFS(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited,
int node, int parent){
    visited[node] = true;
    
    for(auto neighbour:adjList[node]){
        if(!visited[neighbour]){
            bool cycleDetected = isCycleDFS(adjList, visited, neighbour, node);
            if(cycleDetected)
                return true;
        }
        else if(neighbour!=parent){
            return true;
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int, list<int>> adjList;
    unordered_map<int, bool> visited;
    //unordered_map<int,int> parent;
    int u,v;
    for(int i=0; i<m; i++){
        u= edges[i][0];
        v= edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    for(int i=0; i<n; i++){
        if(!visited[i]){
            //bool ans = isCycle(adjList, visited, i, parent);
            bool ans = isCycleDFS(adjList, visited, i, -1);
            if(ans)
                return "Yes";
        }
    }
    return "No";   
}
*/