#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>& nums, int low, int mid, int high){
    vector<int> temp(high - low + 1);
    int i = low;
    int j = mid+1;
    int idx = 0;
    while(i <= mid && j <=high){
        if(nums[i] <= nums[j]) temp[idx++] = nums[i++];
        else temp[idx++] = nums[j++];
    }
    while(i <= mid)  temp[idx++] = nums[i++];
    while(j <= high) temp[idx++] = nums[j++];
    for(int k = low ; k <= high ; k++){
        nums[k] = temp[k - low];
    }
}
void merge_sort(vector<int>& nums, int low, int high){
    if(low >= high) return;
    int mid = low + (high - low)/2;
    merge_sort(nums, low, mid);
    merge_sort(nums, mid+1, high);
    merge(nums, low, mid, high);
}
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin >> nums[i];
    merge_sort(nums,0,n-1);
    for(auto x : nums) cout << x << " ";
    return 0;
}