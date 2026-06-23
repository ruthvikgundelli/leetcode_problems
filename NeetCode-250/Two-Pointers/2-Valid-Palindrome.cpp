#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool isalnum(char ch){
    return (ch >= '0' && ch <= '9') ||
           (ch >= 'A' && ch <= 'Z') ||
           (ch >= 'a' && ch <= 'z');
}
char tolowercase(char ch){
    if(ch >= 'A' && ch <= 'Z')
        ch += 'a' - 'A';

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
int main(){
    string s;
    cin >> s;
    bool ans = isPalindrome(s);
    cout << ans << " ";
    return 0;
}