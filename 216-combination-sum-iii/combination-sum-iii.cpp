class Solution {
public:

    vector<vector<int>> ans;
    vector<int> path;

    void backtrack(int start, int k, int target) {

        if(target == 0 && path.size() == k) {
            ans.push_back(path);
            return;
        }

        if(target < 0 || path.size() > k)
            return;

        for(int num = start; num <= 9; num++) {

            path.push_back(num);

            backtrack(num + 1, k, target - num);

            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {

        backtrack(1, k, n);

        return ans;
    }
};