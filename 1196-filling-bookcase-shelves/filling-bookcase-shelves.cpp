class Solution {
public:
    int recur(int idx, int widthLeft, int height, vector<vector<int>>& books, int shelfWidth, vector<vector<int>>& dp) {

        if (idx == books.size()) {
            return height;
        }

        if (dp[idx][widthLeft] != -1) {
            return dp[idx][widthLeft];
        }

        int newShelf = height + recur(idx + 1, shelfWidth - books[idx][0], books[idx][1], books, shelfWidth, dp);

        int currentShelf = INT_MAX;
        if (books[idx][0] <= widthLeft) {
            currentShelf = recur(idx + 1, widthLeft - books[idx][0], max(height, books[idx][1]), books, shelfWidth, dp);
        }

        return dp[idx][widthLeft] = min(newShelf, currentShelf);
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<vector<int>> dp(n, vector<int>(shelfWidth + 1, -1));
        return recur(0, shelfWidth, 0, books, shelfWidth, dp);
    }
};