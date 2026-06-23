class Solution {
public:
    // void merge(vector<int>& nums, int low, int mid, int high){
    //     vector<int> temp(high - low + 1);
    //     int i = low;
    //     int j = mid+1;
    //     int idx = 0;
    //     while(i <= mid && j <=high){
    //         if(nums[i] <= nums[j]) temp[idx++] = nums[i++];
    //         else temp[idx++] = nums[j++];
    //     }
    //     while(i <= mid)  temp[idx++] = nums[i++];
    //     while(j <= high) temp[idx++] = nums[j++];
    //     for(int k = low ; k <= high ; k++){
    //         nums[k] = temp[k - low];
    //     }
    // }
    // void merge_sort(vector<int>& nums, int low, int high){
    //     if(low >= high) return;
    //     int mid = low + (high - low)/2;
    //     merge_sort(nums, low, mid);
    //     merge_sort(nums,mid+1,high);
    //     merge(nums,low,mid,high);
    // }
    vector<int> sortArray(vector<int>& nums) {
        // merge_sort(nums, 0, nums.size()-1);
        // return nums;
        int mx = *max_element(nums.begin(), nums.end());
        int mi = *min_element(nums.begin(), nums.end());
        vector<int> freq(mx - mi + 1, 0);
        vector<int> s(nums.size());
        for(int i = 0; i < nums.size(); i++){
            freq[nums[i] - mi]++;
        }
        for(int i = 1; i < freq.size(); i++){
            freq[i] += freq[i - 1];
        }
        for(int i = nums.size() - 1; i >= 0; i--){
            freq[nums[i] - mi]--;
            s[freq[nums[i] - mi]] = nums[i];
        }
        nums = s;
        return nums;
    }
};