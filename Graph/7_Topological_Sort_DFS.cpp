https://www.codingninjas.com/studio/problems/topological-sort_982938?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION
#include <bits/stdc++.h> 
using namespace std;
void topSort(vector<vector<int>> &adjList, vector<bool> &visited, stack<int> &s, int node){
    visited[node] = true;
    
    for(auto neighbour:adjList[node]){
        if(!visited[neighbour]){
            topSort(adjList, visited, s, neighbour);
        }
    }
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    stack<int> s;
    vector<vector<int>> adjList(v);
    vector<bool> visited(v, false);
    int a,b;
    for(int i=0; i<e; i++){
        a = edges[i][0];
        b = edges[i][1];
        adjList[a].push_back(b);
    }
    for(int i=0; i<v; i++){
        if(!visited[i]){
            topSort(adjList, visited, s, i);
        }
    }
    vector<int> res;
    while(!s.empty()){
        res.push_back( s.top() );
        s.pop();
    }
    return res;
}