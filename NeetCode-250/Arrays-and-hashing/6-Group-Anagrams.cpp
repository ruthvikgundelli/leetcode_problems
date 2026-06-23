#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
vector<vector<string>> Group_Anagrams(vector<string>& strs){
    unordered_map<string, vector<string>> mp;
    for(string s : strs){
        string key = s;
        sort(key.begin(), key.end());
        mp[key].push_back(s);
    }
    vector<vector<string>> ans;
    for(auto x : mp){
        ans.push_back(x.second);
    }
    return ans;
} // O(n * k log k)
// vector<vector<string>> Group_Anagrams(vector<string>& strs){   // for interview 
//     unordered_map<string, vector<string>> mp;
//     for(auto s : strs){
//         string freq = "";
//         vector<int> hash(26, 0);
//         for(int i=0;i<s.size();i++){
//             hash[s[i]-'a']++;
//         }
//         for(auto x : hash){
//             freq += to_string(x) + "#";
//         }
//         mp[freq].push_back(s);
//     }
//     vector<vector<string>> ans;
//     for(auto x : mp){
//         ans.push_back(x.second);
//     }
//     return ans;
// } // O(n * k)
int main(){
    int n;
    cin >> n;
    vector<string> strs(n);
    for(int i=0;i<n;i++) cin >> strs[i];
    vector<vector<string>> ans = Group_Anagrams(strs);
    for(auto group : ans){
        for(auto word : group){
            cout << word << " ";
        }
        cout << "\n";
    }
    return 0;
}