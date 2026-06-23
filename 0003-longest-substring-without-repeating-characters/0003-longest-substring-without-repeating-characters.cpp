class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> window;
        int l=0;
        int r=0;
        int lenght = 0;
        while(r < s.size()){
            if(window.count(s[r])){
                l = max(l,window[s[r]] + 1);
            }
            window[s[r]] = r;
            lenght = max(lenght, r-l+1);
            r++;
        }
        return lenght;
    }
};