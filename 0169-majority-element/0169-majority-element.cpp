class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el, cnt = 0;
        for(auto x : nums){
            if(cnt == 0){
                el = x;
                cnt++;
            }
            else if(x == el){
                cnt++;
            }
            else cnt--;
        }
        return el;
    }
};