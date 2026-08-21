class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = matrix.size();
        int colm = matrix[0].size();

        int top = 0, bottom = row-1;
        int left = 0, right = colm-1;

        while(top<= bottom && left <= right){

            //left to right, top const
            for(int j = left; j <= right; j++){
                ans.push_back(matrix[top][j]);
            }
                top++;
            
            // top to bottom, right const
            for(int i = top; i <= bottom ; i++){
                ans.push_back(matrix[i][right]);
            }
                right--;
         
            

            //right to left, bottom const
        if(top <= bottom){
            for(int j=right; j>= left; j--){
                ans.push_back(matrix[bottom][j]);
            }
                bottom--;
        }

        if( left <= right){  
            // bottom to top, left const
            for(int i = bottom; i>=top; i--){
                ans.push_back(matrix[i][left]);
            }
                left++;
        }
            
 
        }
        return ans;
    }
};