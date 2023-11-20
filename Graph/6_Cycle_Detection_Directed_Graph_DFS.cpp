// https://www.codingninjas.com/studio/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include <iostream>
#include <vector>
using namespace std;
void makeGraph(vector < pair < int, int >> & edges, vector<vector<int>> &adjList){
  for(int i=0; i<edges.size(); i++){
    int u = edges[i].first;
    int v = edges[i].second;
    adjList[u].push_back(v);
  }
}

bool dfsDetectCycleInDirectedGraph(vector<vector<int>> &adjList, vector<bool> &visited, vector<bool> &dfsVisited, int node){
  visited[node] = true;
  dfsVisited[node] = true;
  for(auto neighbour:adjList[node]){
    if(!visited[neighbour]) dfsDetectCycleInDirectedGraph(adjList, visited, dfsVisited, neighbour);
    if(dfsVisited[neighbour] == true) return true;
  }
  dfsVisited[node] = false;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  vector<vector<int>> adjList(n+1);
  makeGraph(edges, adjList);
  vector<bool> visited(n+1, false), dfsVisited(n+1, false);
  for(int i=1; i<=n; i++){
    if(!visited[i]){
      bool cycleDetect = dfsDetectCycleInDirectedGraph(adjList, visited, dfsVisited, i);
      if(cycleDetect) return 1;
    }
  }
  return 0;
}