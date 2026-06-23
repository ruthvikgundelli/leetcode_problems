#include<iostream>
#include <vector>
using namespace std;
void merge_sorted_array(vector<int>& nums1, vector<int> &nums2, int m, int n){
    int i = m-1;
    int j = n-1;
    int k = n + m - 1;
    while(i>=0 && j >=0){
        if(nums1[i]>nums2[j]){
            nums1[k] = nums1[i];
            k--;
            i--;
        }
        else{
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
    while (j >= 0){
        nums1[k] = nums2[j];
        k--;
        j--;
    }
}
int main(){
    int n,m;
    cin >> m >> n;
    vector<int> nums1(n+m), nums2(n);
    for(int i=0;i<n+m;i++) cin >> nums1[i];
    for(int i=0;i<n;i++) cin >> nums2[i];
    merge_sorted_array(nums1,nums2,m,n);
    for(int i=0;i<n+m;i++) cout << nums1[i] << " ";
    return 0;
}