/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    typedef long long ll;
    int guessNumber(int n) {
        ll l=1,h=n;
        ll mid;
        while(1){
            mid = l + (h-l)/2;
            int myGuess = guess(mid);
            if(!myGuess) return mid;
            else if(myGuess == -1) h = mid-1;
            else l = mid+1;
        }
    }
};