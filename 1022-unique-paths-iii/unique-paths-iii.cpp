class Solution {
public:
    int dfs(vector<vector<int>>& grid, int x, int y, int remain) {
        int m = grid.size();
        int n = grid[0].size();

        // Out of bounds or obstacle/visited
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == -1)
            return 0;

        // Reached ending square
        if (grid[x][y] == 2) {
            return remain == 1;   // end must be the last cell visited
        }

        int temp = grid[x][y];
        grid[x][y] = -1; // mark visited

        int paths = 0;

        paths += dfs(grid, x + 1, y, remain - 1);
        paths += dfs(grid, x - 1, y, remain - 1);
        paths += dfs(grid, x, y + 1, remain - 1);
        paths += dfs(grid, x, y - 1, remain - 1);

        grid[x][y] = temp; // backtrack

        return paths;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int startX = 0, startY = 0;
        int cells = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != -1)
                    cells++;

                if (grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                }
            }
        }

        return dfs(grid, startX, startY, cells);
    }
};