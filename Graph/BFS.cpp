void bfs(int start,vector<vector<int>>& adj,vector<bool>& visited){
         queue<int> q;
         q.push(start);
         while(!q.empty()){
             int node=q.front();
             q.pop();
             if(visited[node]) continue;
             visited[node]=true;
             for(int& next:adj[node]){
                q.push(next);
             }   
         }
 }
