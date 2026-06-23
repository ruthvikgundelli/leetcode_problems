#include<iostream>
using namespace std;
bool Anagram(string s, string t){
    if(s.size() != t.size()) return false;
    vector<int> alphabet(26,0);
    for(auto x : s){
        alphabet[x - 'a']++;
    }
    for(auto x : t){
        alphabet[x - 'a']--;
    }
    for(auto x : alphabet){
        if(x!=0) return false;
    }
    return true;
}
int main(){
    string s,t;
    cin >> s >> t;
    bool anagram = Anagram(s,t);
    cout << anagram;
    return 0;
}