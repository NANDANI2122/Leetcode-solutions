class Solution {
public:
    int n;
    int t[501][501];
    int MOD = 1e9+7;

    int solve(int idx, int steps){

        if(idx < 0 || idx >= n) return 0;

        if(steps == 0) return idx == 0;

        if(t[idx][steps] != -1) return t[idx][steps];

        int res = solve(idx+1, steps-1);

        res = (res + solve(idx-1, steps-1)) % MOD;
        res = (res + solve(idx, steps-1)) % MOD;

        return t[idx][steps] = res;

    }

    int numWays(int steps, int arrLen) {
        arrLen = min(steps,arrLen);

        n = arrLen;
        memset(t, -1, sizeof(t));
        return solve(0,steps);   
    }
};