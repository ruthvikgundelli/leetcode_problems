class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size() == 1) return 1;
        int i = 1;
        int ans = 1;
        int length = 1;
        char curr, prev = '=';
        while(i < arr.size()){
            if(arr[i-1] == arr[i]) curr = '=';
            else if(arr[i-1] < arr[i]) curr = '<';
            else curr = '>';
            if (curr == '=') length = 1;
            else if (prev == '=' || curr != prev) length++;
            else length = 2;
            ans = max(ans,length);
            prev = curr;
            i++;
        } 
        return ans;
    }
};