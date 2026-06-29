class Solution {
public:
    bool canShip(vector<int>& weights, int days, int maxWeight){
        int daysUsed = 1;
        int capacity = 0;
        for (int x : weights) {
            if (capacity + x <= maxWeight) capacity += x;
            else {
                daysUsed++;
                capacity = x;
                if (daysUsed > days) return false;
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = 0;
        for(int x : weights) high += x;
        while(low < high){
            int mid = low + (high - low) / 2;
            if (canShip(weights,days,mid)) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};