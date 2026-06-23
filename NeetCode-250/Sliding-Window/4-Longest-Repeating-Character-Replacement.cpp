#include<iostream>
using namespace std;
int longest_replacement(string s, int k){
    int l=0, r=0;
    int maxLength=0, maxFreq=0;
    vector<int> hash(26,0);
    while(r < s.size()){
        hash[s[r]-'A']++;
        maxFreq = max(maxFreq,hash[s[r]-'A']);
        if((r-l+1) - maxFreq > k){
            hash[s[l]-'A']--;
            l++;
        }
        maxLength = max(maxLength, r-l+1);
        r++;
    }
    return maxLength;
}
int main(){
    int k;
    string s;
    cin >> s >> k;
    cout << longest_replacement(s,k) << "\n";
    return 0;
}