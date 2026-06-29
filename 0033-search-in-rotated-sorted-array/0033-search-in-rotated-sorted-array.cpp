class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        if(target > nums[r] && target < nums[l]) return -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] < nums[r]) r = mid;
            else if(nums[mid] > nums[r]) l = mid+1;
            else break;
        }
        if(l==0){
            int left = 0, right = nums.size()-1;
            while(left <= right){
                int mid = left + (right - left)/2;
                if(target == nums[mid]) return mid;
                else if(target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            }
        }
        if(target >= nums[0]){
            int left = 0, right = l-1;
            while(left <= right){
                int mid = left + (right - left)/2;
                if(target == nums[mid]) return mid;
                else if(target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            }
        }
        else{
            int left = l, right = nums.size()-1;
            while(left <= right){
                int mid = left + (right - left)/2;
                if(target == nums[mid]) return mid;
                else if(target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            }
        }
        return -1;
    }
};