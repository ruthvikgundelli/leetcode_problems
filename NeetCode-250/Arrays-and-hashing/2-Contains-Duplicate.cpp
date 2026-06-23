#include<iostream>
#include<unordered_set>
using namespace std;
bool contains_doubles(vector<int>& nums){
    unordered_set<int> seen;
    for(auto x : nums){
        if(seen.count(x)) return true;
        seen.insert(x);
    }
    return false;
}
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin >> nums[i];
    bool ans = contains_doubles(nums);
    cout << ans;
    return 0;
}