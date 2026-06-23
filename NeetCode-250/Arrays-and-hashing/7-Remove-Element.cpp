#include<iostream>
#include <vector>
using namespace std;
int remove_element(vector<int>& nums, int val){
    int k=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i] != val){
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}
int main(){
    int n,val;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin >> nums[i];
    cin >> val;
    int k = remove_element(nums,val);
    cout << k << "\n";
    return 0;
}