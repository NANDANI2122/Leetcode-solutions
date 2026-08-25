class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(), nums.end());

        int cur= k;
        while(st.count(cur)) 
            cur += k;

        return cur;
    }
};