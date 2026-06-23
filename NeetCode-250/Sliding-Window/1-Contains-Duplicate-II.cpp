#include<iostream>
#include<unordered_set>
using namespace std;
bool contains_duplicates(vector<int>& nums, int k){
    unordered_set<int> window;
    int l = 0, r = 0;
    while(r < nums.size()){
        if(r-l > k) window.erase(nums[l++]);
        if(window.count(nums[r])) return true;
        else window.insert(nums[r++]);
    }
    return false;
}
int main(){
    int n,k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin >> nums[i];
    cout << contains_duplicates(nums,k) << "\n";
    return 0;
}