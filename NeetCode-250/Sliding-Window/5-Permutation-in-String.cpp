#include<iostream>
using namespace std;
bool permutationString(string s1, string s2){
    if(s1.size() > s2.size()) return false;
    int l=0, r=0;
    vector<int> hash1(26,0), hash2(26,0);
    for(int i=0;i<s1.size();i++) hash1[s1[i] - 'a']++;
    while(r<s2.size()){
        hash2[s2[r]-'a']++;
        if(r-l+1 == s1.size()){
            if(hash1 == hash2){
                return true;
            }
            else{
                hash2[s2[l]-'a']--;
                l++;
            }
        }
        r++;
    }
    return false;
}
int main(){
    string s1, s2;
    cin >> s1 >> s2;
    cout << permutationString(s1,s2) << "\n";
    return 0;
}