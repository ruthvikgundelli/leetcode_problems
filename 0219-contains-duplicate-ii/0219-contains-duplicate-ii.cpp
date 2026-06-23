class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;
        int l = 0, r = 0;
        while(r < nums.size()){
            if(r-l > k) window.erase(nums[l++]);
            if(window.count(nums[r])) return true;
            else window.insert(nums[r++]);
        }
        return false;
    }
};