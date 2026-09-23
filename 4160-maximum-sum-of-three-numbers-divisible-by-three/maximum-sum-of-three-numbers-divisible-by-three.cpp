class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int> l0, l1, l2;
        
        for (int x : nums) {
            int p = x % 3;
            if (p == 0) l0.push_back(x);
            else if (p == 1) l1.push_back(x);
            else l2.push_back(x);
        }
        
        int ans = 0;
        
        sort(l0.begin(), l0.end(), greater<int>());
        sort(l1.begin(), l1.end(), greater<int>());
        sort(l2.begin(), l2.end(), greater<int>());
        
        if (l0.size() >= 3)
            ans = max(ans, l0[0] + l0[1] + l0[2]);
        
        if (l1.size() >= 3)
            ans = max(ans, l1[0] + l1[1] + l1[2]);
        
        if (l2.size() >= 3)
            ans = max(ans, l2[0] + l2[1] + l2[2]);
        
        if (l0.size() >= 1 && l1.size() >= 1 && l2.size() >= 1)
            ans = max(ans, l0[0] + l1[0] + l2[0]);
        
        return ans;
    }
};