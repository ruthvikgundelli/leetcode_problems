class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt_subString = 0;
        vector<int> ch(3,-1);
        int idx = 0;
        while(idx < s.size()){
            ch[s[idx] - 'a'] = idx;
            if(find(ch.begin(),ch.end(),-1) != ch.end()){
                idx++;
                continue;
            }
            cnt_subString += (*min_element(ch.begin(),ch.end())+1);
            idx++;
        }
        return cnt_subString;
    }
};