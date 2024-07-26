class Solution {
public:
    bool static cmp(const pair<int,int> p1 ,const pair<int,int> p2)
    {
        if(p1.first != p2.first)
            return p1.first < p2.first;

        return p1.second > p2.second;
    }
    
    void dijkstra(int src,vector<pair<int,int>> adj[],vector<pair<int,int>> &ans,int n,int distance)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dis(n,INT_MAX);
        pq.push({0,src});
        dis[src] = 0;
        
        while(!pq.empty())
        {
            int node = pq.top().second;
            int prev_wt = pq.top().first;
            pq.pop();
            
            for(auto it : adj[node])
            {
                int u = it.first;
                int wt = it.second;
                if(wt + prev_wt < dis[u])
                {
                    dis[u] = wt + prev_wt; 
                    pq.push({dis[u],u});
                }
            }
        }
        
        int count = 0;
        for(int i=0;i<n;i++)
        {
            if(i != src && dis[i] <= distance)
            {
                count++;
            }
        }
        
        ans.push_back({count,src});
        
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        vector<pair<int,int>> ans;
        for(int i=0;i<n;i++)
        {
            dijkstra(i,adj,ans,n,distanceThreshold);
        }
        
        sort(ans.begin(),ans.end(),cmp);
        return ans[0].second;
    }
};