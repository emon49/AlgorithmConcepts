vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<vector<int>> adjList(v);
    vector<int> inDegree(v,0);
    int a, b;
    for(int i=0; i<e; i++){
        a = edges[i][0];
        b = edges[i][1];
        adjList[a].push_back(b);
        inDegree[b]++;
    }
    queue<int> q;
    for(int i=0; i<v; i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }
    vector<int> ans;
    while(!q.empty()){
        int node = q.front();
        ans.push_back(node);
        q.pop();
        for(auto neighbour: adjList[node]){
            inDegree[neighbour] --;
            if(inDegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }
    return ans;
}