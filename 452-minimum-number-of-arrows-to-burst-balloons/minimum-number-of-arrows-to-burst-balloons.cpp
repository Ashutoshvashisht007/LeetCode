class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<vector<int>> ans;
        if(points.size() == 0)
        {
            return 0;
        }
        sort(points.begin(),points.end());
        ans.push_back(points[0]);
        int j = 0;
        for(int i=1;i<points.size();i++)
        {
            if(ans[j][1] >= points[i][0])
            {
                ans[j][1] = min(ans[j][1],points[i][1]);
            }
            else
            {
                j++;
                ans.push_back(points[i]);
            }
        }

        return ans.size();
    }
};