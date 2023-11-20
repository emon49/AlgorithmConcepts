// https://www.codingninjas.com/studio/problems/dfs-traversal_630462?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <queue>
using namespace std;
void dfs(vector<vector<int>> &adjList, vector<bool> &visited, vector<int> &result, int src){
    visited[src] = true;
    result.push_back(src);
    for(int i=0; i<adjList[src].size(); i++){
        int node = adjList[src][i];
        if(!visited[node]){
            dfs(adjList, visited, result, node);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> ans, adjList(V);
    vector<bool> visited(V,false);
    int u, v, componentCnt=0;
    for(int i=0; i<E; i++){
        u = edges[i][0];
        v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u); 
    }
    for(int i=0; i<V; i++){
        if(!visited[i]){
            componentCnt++;
            vector<int> result;
            dfs(adjList, visited, result, i);
            ans.push_back(result);
        }
    }
    return ans;
}