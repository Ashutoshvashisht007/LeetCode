class Solution {
public:

    double dijkstra(int n,int start,int end,vector<pair<int,double>> adj[])
    {
        vector<double> dist(n,0);
        priority_queue<pair<int,double>> pq;
        pq.push({start,1});

        while(!pq.empty()){
            int node = pq.top().first;
            double wt = pq.top().second;
            pq.pop();

            for(auto &it : adj[node]){
                int new_node = it.first;
                double new_wt = it.second;

                if((wt * new_wt) > dist[new_node]){
                    dist[new_node] = wt * new_wt;
                    pq.push({new_node,wt * new_wt});
                }
            }

        }

        return dist[end];
    }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int,double>> adj[n];
        for(int i=0;i<succProb.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }

        return dijkstra(n,start_node,end_node,adj);
    }
};