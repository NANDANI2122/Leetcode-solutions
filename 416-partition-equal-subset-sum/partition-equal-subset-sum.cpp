
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < n; i++)
            sum += nums[i];

        if (sum % 2 != 0)
            return false;

        int reqSum = sum / 2;

        vector<vector<bool>> dp(
            n + 1, vector<bool>(reqSum + 1, false)
        );

        for (int i = 0; i <= n; i++)
            dp[i][0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= reqSum; j++) {

                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] ||
                               dp[i - 1][j - nums[i - 1]];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][reqSum];
    }
};
