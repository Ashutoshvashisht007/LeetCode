class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int sm = arrays[0][0];
        int lg = arrays[0].back();
        int mx = 0;
        for(int i=1;i<arrays.size();i++){
            mx = max(mx,abs(arrays[i].back() - sm));
            mx = max(mx,abs(arrays[i][0] - lg));
            lg = max(lg,arrays[i].back());
            sm = min(sm,arrays[i][0]);
        }

        return mx;
    }
};