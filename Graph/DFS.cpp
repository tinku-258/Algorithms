void dfs(int node,vector<vector<int>>& adj,vector<bool>& visited){
         if(visited[node]) return;
         visited[node]=true;
         for(int& next:adj[node]){
             dfs(next,adj,visited);
         }
}
