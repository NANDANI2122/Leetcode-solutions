class Solution {
public:
    int n;

    bool isPallin(string s, int i,int j){

        while(i < j){
            if(s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }

    void backtrack(string &s, int idx, vector<vector<string>>&result,vector<string>&curr){

        if(idx == n){
            result.push_back(curr);
            return;
        } 

        for(int i=idx; i<n; i++){

            if(isPallin(s,idx,i)){
                curr.push_back(s.substr(idx, i-idx+1));
                backtrack(s, i+1, result, curr);
                curr.pop_back();
            }
        }
    }


    vector<vector<string>> partition(string s) {
        
        n = s.length();
        vector<vector<string>>result;
        vector<string>curr;

        backtrack(s,0,result,curr);

        return result;

    }
};