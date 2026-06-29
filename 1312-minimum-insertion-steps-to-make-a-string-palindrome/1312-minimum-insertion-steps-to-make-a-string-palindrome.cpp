class Solution {
public:
    int lcs(int i, int j, int m, int n, string &text1,
            string &text2) {

        // Space Optimized DP
        vector<int> prev(n, 0);
        vector<int> curr(n, 0);

        // Traverse the table
        for (int i = 0; i < m; i++) {

            // Reset current row
            curr.assign(n, 0);

            for (int j = 0; j < n; j++) {

                // Characters match
                if (text1[i] == text2[j]) {

                    int diagonal = 0;

                    if (i > 0 && j > 0)
                        diagonal = prev[j - 1];

                    curr[j] = 1 + diagonal;
                }
                else {

                    int left = 0;
                    int up = 0;

                    if (j > 0)
                        left = curr[j - 1];

                    if (i > 0)
                        up = prev[j];

                    curr[j] = max(left, up);
                }
            }

            prev = curr;
        }

        return prev[n - 1];
    }

    int minInsertions(string s) {
        string text1 = s;

        reverse(s.begin(), s.end());

        string text2 = s;

        int m = text1.size();
        int n = text2.size();

        return m-lcs(m - 1, n - 1, m, n, text1, text2);
    }
};