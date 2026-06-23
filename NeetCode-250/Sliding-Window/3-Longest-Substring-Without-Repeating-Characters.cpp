#include<iostream>
#include<unordered_set>
using namespace std;
int longest_substring(string s){
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
int main(){
    string s;
    cin >> s;
    cout << longest_substring(s) << "\n";
    return 0;
}