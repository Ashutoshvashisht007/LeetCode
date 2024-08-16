class Solution {
public:

    pair<int,int> recur(int child,int parent,vector<int> adj[]){
        int ans = 0, subTree = 1;
        int mx = INT_MIN, mn = INT_MAX;

        for(auto &it : adj[child]){
            if(parent != it){
                auto res = recur(it,child,adj);
                ans += res.first;
                subTree += res.second;

                mn = min(mn,res.second);
                mx = max(mx,res.second);
            }
        }

        if(mx == INT_MIN || mx == mn){
            ans++;
        }

        return make_pair(ans,subTree);
    }

    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> adj[n+1];

        for(auto &it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        return recur(0,-1,adj).first;
    }
};