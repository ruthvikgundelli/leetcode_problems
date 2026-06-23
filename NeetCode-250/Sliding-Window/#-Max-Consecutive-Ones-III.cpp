#include<iostream>
using namespace std;
int max_consecutive(vector<int> nums, int k){
    int l = 0, r = 0;
    int zeros = 0;
    int maxOnes = 0;
    while(r < nums.size()){
        if(nums[r] == 0) zeros++;
        while(zeros > k){
            if(nums[l] == 0) zeros--;
            l++;
        }
        maxOnes = max(maxOnes, r - l + 1);  
        r++;
    }
    return maxOnes;
}
int main(){
    int n,k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin >> nums[i];
    cout << max_consecutive(nums,k) << "\n";
    return 0;
}