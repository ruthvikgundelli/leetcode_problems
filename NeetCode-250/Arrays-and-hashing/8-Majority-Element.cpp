#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// int majority_element(vector<int>& nums){ // Better
//     unordered_map<int,int> mp;
//     for(auto x : nums){
//         mp[x]++;
//     }
//     int mx = 0;
//     int ans = 0;
//     for(auto x : mp){
//         if(x.second > mx){
//             mx = x.second;
//             ans = x.first;
//         }
//     }
//     return ans;
// }
int majority_element(vector<int>& nums){ // Boyer-Moore voting, optimal
    int el, cnt = 0;
    for(auto x : nums){
        if(cnt == 0){
            el = x;
            cnt++;
        }
        else if(x == el){
            cnt++;
        }
        else cnt--;
    }
    return el;
}
int main(){
    int n,val;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin >> nums[i];
    cin >> val;
    int k = majority_element(nums);
    cout << k << "\n";
    return 0;
}