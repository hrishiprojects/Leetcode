class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
         vector<vector<pair<int, int>>> adj(n);
        for(const auto& edge: edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        int min_count = INT_MAX, ans_city;

        
        for(int i = 0; i < n; i++) {
            vector<int> dist(n, INT_MAX); 
            dist[i] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
            pq.push({0, i});

            
            while(!pq.empty()) {
                auto [wt, node] = pq.top(); 
                pq.pop();

                
                for(const auto& it: adj[node]) {
                    auto [adjNode, edgeWt] = it;

                    if(dist[adjNode] > wt + edgeWt) {
                        dist[adjNode] = wt + edgeWt;
                        pq.push({dist[adjNode], adjNode});
                    }
                }
            }

            
            int count = 0;
            for(int d: dist)
                if(d <= distanceThreshold) ++count;
            
            
            if(count <= min_count) {
                min_count = count;
                ans_city = i;
            }
        }

        return ans_city;
    }
};