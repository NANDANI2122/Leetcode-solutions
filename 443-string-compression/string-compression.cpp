class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();

        int index = 0;
        int i = 0;

        while(i < n){
            char curr_char = chars[i];
            int char_count = 0;

            while(i<n && chars[i] == curr_char){
                i++;
                char_count ++;
            }

            chars[index] = curr_char;
            index++;

            if(char_count>1){
                string cnt_str = to_string(char_count);

                for(char &ch:cnt_str){
                    chars[index]=ch;
                    index++;
                }
            }
        }
        return index;
    }
};