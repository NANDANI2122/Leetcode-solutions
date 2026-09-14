class Solution {
public:
    int t[201][1001];
    int backtrack(vector<int>& nums, int target,  int idx){

        if(target == 0) {
            return 1;
        }

        if(target < 0 || idx >= nums.size()) return 0;

        if(t[idx][target]!=-1) return t[idx][target];
        //take
        int take = backtrack(nums, target-nums[idx], 0);
        //reject
        int reject = backtrack(nums, target, idx+1);

        return t[idx][target] = take+reject;

    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(t,-1,sizeof(t));
        return backtrack(nums, target, 0);
        
    }
};