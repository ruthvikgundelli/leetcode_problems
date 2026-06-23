#include <iostream>
#include <vector>
using namespace std;
class MyHashSet {
private:
    vector<bool> hash;
public:
    MyHashSet() {
        hash.resize(1000001, false);
    }
    void add(int key) {
        hash[key] = true;
    }
    void remove(int key) {
        hash[key] = false;
    }
    bool contains(int key) {
        return hash[key];
    }
};
int main() {
    MyHashSet obj;
    obj.add(5);
    obj.add(10);
    cout << obj.contains(5) << "\n";   // 1
    obj.remove(5);
    cout << obj.contains(5) << "\n";   // 0
}

