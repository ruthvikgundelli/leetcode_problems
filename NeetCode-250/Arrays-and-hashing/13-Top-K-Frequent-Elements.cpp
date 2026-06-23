#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> k_freq_element(vector<int>& nums,int k){
    unordered_map<int,int> mp;
    vector<int> ans;
    for(auto x : nums) mp[x]++;
    vector<vector<int>> bucket(nums.size()+1);
    for(auto x : mp){
        bucket[x.second].push_back(x.first);
    }
    for (int freq = nums.size(); freq >= 1 && ans.size() < k; freq--) {
        for (int num : bucket[freq]) {
            ans.push_back(num);
            if (ans.size() == k)
                break;
        }
    }
    return ans;
}
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(n),ans;
    for(int i=0;i<n;i++) cin >> nums[i];
    ans = k_freq_element(nums,k);
    for(auto x : ans) cout << x << " ";
    return 0;
}