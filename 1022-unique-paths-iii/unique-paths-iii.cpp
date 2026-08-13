class Solution {
public:
    int m, n;
    int nonObs;
    int result;
    vector<vector<int>>directions{{0,1}, {1,0}, {-1,0}, {0,-1}};

    void backTrack(vector<vector<int>>& grid, int i, int j, int count){

        if( i<0 || i>=m || j<0 || j >=n || grid[i][j] == -1) return ;

        if(grid[i][j] == 2){
            if(count == nonObs){
                result ++;
            }
            return;
        }

        grid[i][j] = -1;

        for(auto &dir : directions){
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            backTrack(grid, new_i, new_j, count+1);
        }

        grid[i][j] = 0;

    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        result = 0;
        nonObs = 0;

        int start_x = 0,start_y = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){

                if(grid[i][j] == 0) nonObs++;

                if(grid[i][j] == 1){
                    start_x = i;
                    start_y = j;
                }
            }
        }
        nonObs += 1;
        int count = 0;
        backTrack(grid, start_x, start_y, count);

        return result;


    }
};