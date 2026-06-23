class Solution {
public:
    bool isalnum(char ch){
        if(ch < 48 || (ch > 57 && ch < 65) || (ch > 90 && ch < 97) || (ch > 122)) return false;
        return true;
    }
    char tolowercase(char ch){
        if(ch >=65 && ch <= 90) ch += 32;
        return ch;
    }
    bool isPalindrome(string s){
        int i=0, j=s.size()-1;
        while(i<j){
            while(i<j && !isalnum(s[i])) i++;
            while(i<j && !isalnum(s[j])) j--;
            if(tolowercase(s[i]) != tolowercase(s[j])) return false;
            i++;
            j--;
        }
        return true;
}
};