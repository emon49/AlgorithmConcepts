// https://www.codingninjas.com/studio/problems/bfs-in-graph_973002?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <queue>
using namespace std;

void prepareAdjList(unordered_map<int,set<int>> &adjList, vector<pair<int, int>> &edges){
    int u,v;
    for(int i=0; i<edges.size(); i++){
        u = edges[i].first;
        v = edges[i].second;
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfsTraversal(unordered_map<int,set<int>> &adjList,unordered_map<int, bool> &visited,vector<int> &ans,
            int node){

                queue<int> q;
                visited[node] =true;
                q.push(node);

                while(!q.empty()){
                    int front = q.front();
                    ans.push_back(front);
                    q.pop();
                    for(auto i:adjList[front]){
                        if(!visited[i]){
                            visited[i]=true;
                            q.push(i);
                        }
                    }
                }
            }

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int,set<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;

    prepareAdjList(adjList, edges);

    for(int i=0; i<vertex; i++){
        if(!visited[i]){
            bfsTraversal(adjList, visited, ans, i);
        }
    }
    return ans;
    
}







