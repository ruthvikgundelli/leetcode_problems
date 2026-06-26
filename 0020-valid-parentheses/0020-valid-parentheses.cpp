class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        for(int i=0;i<s.size();i++){
            if(s[i] == '}' || s[i] == ']' || s[i] == ')'){
                if (brackets.empty()) return false;
                char top = brackets.top();
                if ((s[i] == ')' && top != '(') ||
                    (s[i] == ']' && top != '[') ||
                    (s[i] == '}' && top != '{'))
                    return false;
                brackets.pop();
            }
            else brackets.push(s[i]);
        }
        return brackets.empty();
    }
};