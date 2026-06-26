class Solution {
public:
    bool canEatAll(vector<int>& piles, int h, int k) {
        long long hours = 0;
        for (int bananas : piles) {
            hours += (bananas + k - 1) / k;
        }
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (canEatAll(piles, h, mid)) r = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
};