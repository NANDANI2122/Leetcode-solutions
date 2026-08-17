class Solution {
public:
    int ans = 0;

    void backtrack(int row, int n,
                   vector<bool>& col,
                   vector<bool>& diag1,
                   vector<bool>& diag2) {
        if (row == n) {
            ans++;
            return;
        }

        for (int c = 0; c < n; c++) {
            int d1 = row - c + n - 1; // main diagonal
            int d2 = row + c;         // anti-diagonal

            if (col[c] || diag1[d1] || diag2[d2])
                continue;

            col[c] = diag1[d1] = diag2[d2] = true;

            backtrack(row + 1, n, col, diag1, diag2);

            col[c] = diag1[d1] = diag2[d2] = false;
        }
    }

    int totalNQueens(int n) {
        vector<bool> col(n, false);
        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);

        backtrack(0, n, col, diag1, diag2);
        return ans;
    }
};