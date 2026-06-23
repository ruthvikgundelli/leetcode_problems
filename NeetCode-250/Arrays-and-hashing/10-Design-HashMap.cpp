#include<iostream>
#include<vector>
using namespace std;
class MyHashMap {
private:
    vector<int> hash;
public:
    MyHashMap() {
        hash.resize(1000001,-1);
    }
    void put(int key, int value) {
        hash[key] = value;
    }
    
    int get(int key) {
        return hash[key];
    }
    
    void remove(int key) {
        hash[key] = -1;
    }
};