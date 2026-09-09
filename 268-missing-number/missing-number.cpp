class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xorS=nums.size();
        for(int i=0; i<nums.size(); i++){
            xorS^=i^nums[i];
        }
        return xorS;
    }
};