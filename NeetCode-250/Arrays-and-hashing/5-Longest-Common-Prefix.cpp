#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
string CommonPrefix(vector<string>& strs){
    string prefix = strs[0];
    for(int i = 1; i < strs.size(); i++){
        while(strs[i].find(prefix) != 0){
            prefix.pop_back();
        }
    }
    return prefix;
}
int main(){
    int n;
    cin >> n;
    vector<string> strs(n);
    for(int i=0;i<n;i++) cin >> strs[i];
    string ans = CommonPrefix(strs);
    cout << ans << "\n";
    return 0;
}