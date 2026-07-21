class Solution {
public:

    bool canIPlaceQueen(int row, int col, vector<string>& board, int n) {

        // Check left side
        int r = row;
        int c = col;
        while (c >= 0) {
            if (board[r][c] == 'Q')
                return false;
            c--;
        }

        // Check upper-left diagonal
        r = row;
        c = col;
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q')
                return false;
            r--;
            c--;
        }

        // Check lower-left diagonal
        r = row;
        c = col;
        while (r < n && c >= 0) {
            if (board[r][c] == 'Q')
                return false;
            r++;
            c--;
        }

        return true;
    }

    void NQueen(vector<vector<string>>& result, int column,
                vector<string>& board, int n) {

        // Base Case
        if (column == n) {
            result.push_back(board);
            return;
        }

        // Try every row in current column
        for (int row = 0; row < n; row++) {

            if (canIPlaceQueen(row, column, board, n)) {

                // Place Queen
                board[row][column] = 'Q';

                // Recur for next column
                NQueen(result, column + 1, board, n);

                // Backtrack
                board[row][column] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> result;

        string s(n, '.');
        vector<string> board(n, s);

        NQueen(result, 0, board, n);

        return result;
    }
};