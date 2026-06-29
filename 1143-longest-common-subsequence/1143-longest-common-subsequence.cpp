class Solution {
public:

int lcs(int i, int j, int m, int n, string &text1,
            string &text2, vector<vector<int>> &dp) {
        
        //for space optimize
        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);

                 // Base case
        // if (i < 0 || j < 0)
        //     return 0;

        // DP check
        // if (dp[i][j] != -1)
        //     return dp[i][j];



        // Traverse the entire DP table
        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                // If characters match
                if (text1[i] == text2[j]) {

                    int a = 0;

                    // Take diagonal value if it exists
                    if (i > 0 && j > 0) {
                        a = prev[j - 1];
                    }

                    curr[j] = 1 + a;
                }

                // If characters do not match
                else {

                    int b = 0;
                    int c = 0;

                    // Left value
                    if (j > 0) {
                        b = curr[j - 1];
                    }

                    // Upper value
                    if (i > 0) {
                        c = prev[j];
                    }

                    curr[j] = max(b, c);
                }
            }
             prev = curr;
        }

         // // Match
        // if (text1[i] == text2[j]) {
        //     return dp[i][j] = 1 + lcs(i - 1, j - 1, text1, text2, dp);
        // }

        // Not Match
        // return dp[i][j] = max( lcs(i - 1, j, text1, text2, dp), lcs(i, j - 1, text1, text2, dp)
        // );
    

        // Final answer
        return prev[n - 1];
    }

       
int longestCommonSubsequence(string text1, string text2) {

        int m = text1.size();
        int n = text2.size();

        // DP table initialized with 0
        vector<vector<int>> dp(m, vector<int>(n, 0));

        return lcs(m - 1, n - 1, m, n, text1, text2, dp);
    }
};