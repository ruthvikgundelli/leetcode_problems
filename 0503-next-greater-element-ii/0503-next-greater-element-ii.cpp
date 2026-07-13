class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ngl(nums.size(),-1);
        stack<int> monoSt;
        for(int i=2*nums.size()-1;i>=0;i--){
            int idx = i%nums.size();
            while(!monoSt.empty() && nums[idx] >= monoSt.top()){
                monoSt.pop();
            }
            if(i < nums.size()){
                if(!monoSt.empty()) ngl[idx] = monoSt.top();
            }
            monoSt.push(nums[idx]);
        }
        return ngl;
    }
};