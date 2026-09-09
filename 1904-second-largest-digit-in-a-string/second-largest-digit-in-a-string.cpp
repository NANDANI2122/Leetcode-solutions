class Solution {
public:
    int secondHighest(string s) {
        int firstLar = INT_MIN, secLar = INT_MIN;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                if (firstLar == INT_MIN)
                    firstLar = s[i] - '0';
                else {
                    if (firstLar < s[i] - '0') {
                        secLar = firstLar;
                        firstLar = s[i] - '0';
                    } else if (secLar < s[i] - '0' && firstLar != (s[i] - '0'))
                        secLar = s[i] - '0';
                }
            }
        }
        return (secLar == INT_MIN) ? -1 : secLar;
    }
};