class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int sqr = (int)(sqrt(r));
        vector<bool> prime(sqr + 1,true);
        for (int p = 2; p * p <= sqr; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i <= sqr; i += p)
                    prime[i] = false;
            }
        }

        int count = 0;

        for(int i=2;i<=sqr;i++){
            if(prime[i]){
                int square = i*i;
                if(square >= l && square <= r){
                    count++;
                }
            }
        }

        int totalNum = r - l + 1;

        return totalNum - count;
    }
};