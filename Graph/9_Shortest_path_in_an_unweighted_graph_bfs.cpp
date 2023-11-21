vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	vector<vector<int>> adjList(n+1);
	vector<bool> visited(n+1, false);
	vector<int> parent(n+1);
	int a,b;
	for(int i=0; i<m; i++){
		a = edges[i].first;
		b = edges[i].second;
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}
	queue<int> q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(auto neighbour:adjList[node]){
			if(!visited[neighbour]){
				visited[neighbour] = 1;
				parent[neighbour] = node;
				q.push(neighbour);
			}
		}
	}
	vector<int> res;
	res.push_back(t);
	int curNode = t;
	while(curNode != s){
		curNode = parent[curNode];
		res.push_back(curNode);
	}
	
	reverse(res.begin(), res.end());
	//for(auto i:res)	cout<<i<<" ";
	return res;
	
}
