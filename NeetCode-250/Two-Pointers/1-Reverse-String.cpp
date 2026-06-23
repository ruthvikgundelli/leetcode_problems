#include<iostream>
#include<vector>
#include<string>
using namespace std;
void reverse_string(vector<string>& s){
    int i=0, j = s.size()-1;
    while(i<=j){
        swap(s[i++],s[j--]);
    }
}
int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i=0;i<n;i++) cin >> s[i];
    reverse_string(s);
    for(int i=0;i<n;i++) cout << s[i] << " ";
    return 0;
}