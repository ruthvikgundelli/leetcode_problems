#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
pair<int,int> TwoSum(vector<int>& nums, int target){
    unordered_map<int,int> sum;
    for(int i=0;i<nums.size();i++){
        int y = target - nums[i];
        if(sum.count(y)){
            return {sum[y],i};
        }
        sum[nums[i]] = i;
    }
    return {-1,-1};
} 
int main(){
    int n,target;
    cin >> n >> target;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin >> nums[i];
    pair<int,int> ans = TwoSum(nums,target);
    cout << ans.first << ans.second << "\n";
    return 0;
}