class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> ngl;
        stack<int> monoSt;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!monoSt.empty() && nums2[i] >= monoSt.top()){
                monoSt.pop();
            }
            if(monoSt.empty()){
                ngl[nums2[i]] = -1;
            }
            else{
                ngl[nums2[i]] = monoSt.top();
            }
            monoSt.push(nums2[i]);
        }
        vector<int> ans(nums1.size());
        for(int i=0;i<nums1.size();i++){
            ans[i] = ngl[nums1[i]];
        }
        return ans;
    }
};