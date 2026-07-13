class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> collision;
        for(int asteroid : asteroids){
            if(asteroid > 0) collision.push(asteroid);
            else{
                while(!collision.empty() && collision.top() > 0 && collision.top() < abs(asteroid)){
                    collision.pop();
                }
                if(!collision.empty() && collision.top() == abs(asteroid)) collision.pop();
                else if(collision.empty() || collision.top() < 0) collision.push(asteroid);
            }
        }
        vector<int> ans(collision.size());
        for(int i = collision.size()-1;i >= 0 ;i--){
            ans[i] = collision.top();
            collision.pop();
        }
        return ans;
    }
};