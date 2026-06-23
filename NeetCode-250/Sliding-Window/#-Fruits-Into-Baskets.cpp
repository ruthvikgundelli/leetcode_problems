#include<iostream>
#include<unordered_map>
using namespace std;
int maxFruits(vector<int>& fruits) {
    unordered_map<int,int> mp;
    int l=0,r=0;
    int maxfruits = 0;
    while(r < fruits.size()){
        mp[fruits[r]]++;
        if(mp.size()>2){
            mp[fruits[l]]--;
            if(mp[fruits[l]] == 0) mp.erase(fruits[l]);
            l++;
        }
        if(mp.size()<=2) maxfruits = max(maxfruits, r-l+1);
        r++;
    }
    return maxfruits;
}
int main(){
    int n;
    cin >> n;
    vector<int> fruits(n);
    for(int i=0;i<n;i++) cin >> fruits[i];
    cout << maxFruits(fruits) << "\n";
    return 0;
}