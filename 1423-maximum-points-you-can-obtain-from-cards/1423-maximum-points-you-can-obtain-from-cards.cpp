class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0, rsum = 0;
        int sum = 0;
        int l = 0, r = cardPoints.size() - 1;
        while(l<k) lsum += cardPoints[l++];
        int score = lsum;
        l--;
        while(r >= (cardPoints.size() - k) && l >= 0){
            rsum += cardPoints[r--];
            lsum -= cardPoints[l--];
            sum = lsum + rsum;
            score = max(score,sum);
        }
        return score;
    }
};