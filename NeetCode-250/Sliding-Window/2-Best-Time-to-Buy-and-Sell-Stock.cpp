#include<iostream>
using namespace std;
int max_profit(vector<int> prices){
    int l = 0;
    int r = 0;
    int profit = 0;
    while(r < prices.size()){
        if(prices[r] < prices[l]) l = r;
        else{
            profit = max(profit, (prices[r]-prices[l]));
        }
        r++;
    }
    return profit;
}
int main(){
    int n;
    cin >> n;
    vector<int> prices(n);
    for(int i=0;i<n;i++) cin >> prices[i];
    cout << max_profit(prices) << "\n";
    return 0;
}