//Atcoder dp

#include<bits/stdc++.h>
using namespace std;
unordered_map<int,vector<int>> graph;
void dfs(int node,vector<int>&dist,vector<int>&visited,vector<int>&indegree){
    visited[node]=1;
    for(auto neigh:graph[node]){
        //visited[neigh]=1;
        dist[neigh]=max(dist[neigh],1+dist[node]);
        indegree[neigh]--;
        if(indegree[neigh]==0)
            dfs(neigh,dist,visited,indegree);
        
    }
}
int main() {
	// your code goes here
	graph.clear();
	int n,m;
	cin>>n>>m;
	
	int u,v;
	vector<int> indegree(n+1,0);
	for(int i=0;i<m;i++){
	    cin>>u>>v;
	    graph[u].push_back(v);
	    indegree[v]++;
	    //graph[v].push_back(u);
	}
	vector<int> dist(n+1,0),visited(n+1,0);
	for(int i=1;i<=n;i++){
	    if(!visited[i] and indegree[i]==0){
	        dfs(i,dist,visited,indegree);
	    }
	}
// 	for(int i=1;i<=n;i++)
// 	    cout<<dist[i]<<" ";
// 	  cout<<endl;
	int res=0;
	for(int i=1;i<=n;i++)
	    res = max(res,dist[i]);
	cout<<res<<endl;
	return 0;
}
