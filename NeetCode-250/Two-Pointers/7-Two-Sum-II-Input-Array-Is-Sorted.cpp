#include<iostream>
using namespace std;
vector<int> two_sum(vector<int> numbers, int target){
    int i=0, j=numbers.size() - 1;
    while(i<j){
        if(numbers[i]+numbers[j] == target) return {i+1,j+1};
        else if(numbers[i]+numbers[j] < target) i++;
        else j--;
    }
}
int main(){
    int n, target;
    cin >> n >> target;
    vector<int> numbers(n),ans;
    for(int i=0;i<n;i++) cin >> numbers[i];
    ans = two_sum(numbers,target);
    cout << ans[0] << " " << ans[1] << "\n";
    return 0;
}