class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,pair<int,int>> mp;

        for(int i = 0; i < arr.size(); i++){
            if(mp.find(arr[i]) != mp.end())
            {
                int temp = mp[arr[i]].first;
                mp[arr[i]] = {temp+1,i};
            }
            else
                mp[arr[i]] = {1,i};
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>> pq;

        for(auto &it : mp)
        {
            if(it.second.first == 1)
            {
                pq.push({it.second.second,it.first});
            }
        }

        while(!pq.empty() && k > 0){
            auto it = pq.top();
            pq.pop();
            k--;
            if(k == 0){
                return it.second;
            }
        }

        return "";
    }
};