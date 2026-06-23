class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        int l=0,r=0;
        int maxfruits = 0;
        while(r < fruits.size()){
            mp[fruits[r]] = r;
            if(mp.size()>2){
                auto it = min_element(mp.begin(),mp.end(),
                [](const auto &a, const auto &b) {return a.second < b.second;});
                l = it->second + 1;
                mp.erase(it);
            }
            maxfruits = max(maxfruits, r-l+1);
            r++;
        }
        return maxfruits;
    }
};