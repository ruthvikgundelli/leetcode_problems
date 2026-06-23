#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int remove_duplicates(vector<int>& nums){
    int k = 1;
    for(int i=1; i<nums.size(); i++){
        if(nums[i]!=nums[k-1]){
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin >> nums[i];
    int k = remove_duplicates(nums);
    for(int i=0;i<k;i++) cout << nums[i] << " "; 
    return 0;
}