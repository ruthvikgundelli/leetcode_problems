#include<iostream>
using namespace std;
string merge_string(string word1, string word2){
    auto i = word1.begin();
    auto j = word2.begin();
    string ans;
    ans.reserve(word1.size() + word2.size());
    while(i < word1.end() && j < word2.end()){
        ans += *i;
        i++;
        ans += *j;
        j++;
    }
    while(i < word1.end()){
        ans += *i;
        i++;
    }
    while(j < word2.end()){
        ans += *j;
        j++;
    }
    return ans;
}
int main(){
    string word1, word2;
    cin >> word1 >> word2;
    string ans = merge_string(word1, word2);
    cout << ans << "\n"; 
    return 0;
}