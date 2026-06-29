class Solution {
public:

    int lcs(int i, int j, string &text1, string &text2,
            vector<vector<int>> &dp) {

        // Base case
        if (i < 0 || j < 0)
            return 0;

        // DP check
        if (dp[i][j] != -1)
            return dp[i][j];

        // Match
        if (text1[i] == text2[j]) {
            return dp[i][j] = 1 + lcs(i - 1, j - 1, text1, text2, dp);
        }

        // Not Match
        return dp[i][j] = max(
            lcs(i - 1, j, text1, text2, dp),
            lcs(i, j - 1, text1, text2, dp)
        );
    }

    int longestCommonSubsequence(string text1, string text2) {

        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return lcs(m - 1, n - 1, text1, text2, dp);
    }
};