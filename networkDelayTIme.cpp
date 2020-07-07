int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        
        // Uses Dijsktra SPA
        
        map<int,int> dist;
        vector<bool> seenNodes(N+1, false);
        
        // Creates graph , lines 9-13
        map<int, vector<vector<int>>> graph;
        
        for(const auto time: times){
            graph[time[0]].push_back({time[1], time[2]});
        }
        
        // Set dist map to maxDistance which is INT_MAX in this case
        for(int i = 1; i <= N; i++)
            dist[i] = INT_MAX;
        
        // set source node distance to 0
        dist[K] = 0;
        while(true){
            
            int candNode = -1;
            int candDist = INT_MAX;
            
            // Find the node with shortest distance from the source, will be source itself in the first iteration
            
            for(int i = 1; i <= N; i++){
                if(seenNodes[i] == false && dist[i] < candDist){
                    candNode = i;
                    candDist = dist[i];
                }
            }
            
            // if no more nodes to see, break oyut of the loop
            if(candNode == -1) break;
            seenNodes[candNode] = true; // Mark the current node as seen
            
            // Iterate the graph to update the distance of the source's adjacent nodes.
            if(graph.count(candNode)){
                vector<vector<int>> adjacentNodes = graph[candNode];
                for(const auto node : adjacentNodes){
                    dist[node[0]] = min(dist[node[0]], dist[candNode] + node[1]);
                }
            }
        }
        
        // iterate dist map to get the max time delay.
        int ans = 0;
        for(int i = 1; i <= N; i++){
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
