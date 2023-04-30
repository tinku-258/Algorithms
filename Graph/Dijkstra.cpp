//  if distance only from 'src' to 'dst' is required,pass optional parameter dst

 vector<long long> dijkstra(vector<vector<pair<int,int>>>& adj,int src,int dst=0){
        
        int n=adj.size();
        vector<long long> dist(n,1e14);
        dist[src]=0;
        
        priority_queue<pair<long long,int>> pq;
        pq.push({0,src});
        
        while(!pq.empty()){
            long long cost=-pq.top().first;
            int node=pq.top().second;
            pq.pop();

            // if(node==dst) return cost; //if only 'src' to 'dst' distance is required
            for(auto& next:adj[node]){
                if(dist[next.first]>cost+next.second){
                    dist[next.first]=cost+next.second;
                    pq.push({- dist[next.first],next.first});
                }
            }
        }
        // return dist[dst]; //if only 'src' to 'dst' distance is required
        return dist;
    }
