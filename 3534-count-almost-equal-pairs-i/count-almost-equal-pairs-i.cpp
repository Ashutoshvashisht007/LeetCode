class Solution {
public:
    
    int equalPairs(int x,int y){
        string a = to_string(x), b = to_string(y);
        int n = a.size(), m = b.size();
        int mx = max(n,m);
        while(n != mx){
            a = "0" + a;
            n++;
        }
        while(m != mx){
            b = "0" + b;
            m++;
        }

        unordered_map<int,int> mp1,mp2;
        int swaps = 0;
        for(int i=0;i<n;i++){
            swaps += (a[i] != b[i]);
            mp1[a[i]]++;
            mp2[b[i]]++;
        }

        return swaps <= 2 && mp1 == mp2;
    }

    int countPairs(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                ans += equalPairs(nums[i],nums[j]);
            }
        }

        return ans;

    }
};