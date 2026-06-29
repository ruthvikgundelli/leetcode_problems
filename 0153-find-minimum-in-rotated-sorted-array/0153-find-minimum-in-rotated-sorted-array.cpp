class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums[0] < nums[nums.size()-1]) return nums[0];
        int l = 0, r = nums.size()-1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] > nums[r]) l = mid + 1;
            else if(nums[mid] < nums[r]) r = mid;
            else return nums[l];
        }
        return -1;
    }
};