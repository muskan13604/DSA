
class Solution {
    public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> currentPath;
        backtrack(s, 0, currentPath, result);
        return result;
    }
    private:
    void backtrack(const string& s, int start, vector<string>& currentPath, vector<vector<string>>& result) {
        if (start == s.length()) {
            result.push_back(currentPath);
            return;
            }
            for (int end = start; end < s.length(); ++end) {
                if (isPalindrome(s, start, end)) {
                    currentPath.push_back(s.substr(start, end - start + 1));
                    backtrack(s, end + 1, currentPath, result);
                    currentPath.pop_back();
                }
                }
                }
                bool isPalindrome(const string& s, int low, int high) {
                    while (low < high) {
                        if (s[low] != s[high]) {
                            return false;
                            }
                            low++;
                            high--;
                            }
                            return true;
                            }
};
                       