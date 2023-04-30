//         WEIGHTED GRAPH 
      vector<vector<pair<int,int>>> adj(n+1);
       for(auto& e:edges){
           adj[e[0]].push_back({e[1],e[2]});
           adj[e[1]].push_back({e[0],e[2]});
       }
