class Solution {
public:
    int findJudge(int n, const vector<vector<int>>& trust) {
        
        vector<int> indegree(n);
        vector<int> outdegree(n);

        for (const auto &v : trust) {
            ++outdegree[v.front()-1];
            ++indegree[v.back()-1];
        }

        for (int i{}; i < n; ++i) {
            if (outdegree[i] == 0 && indegree[i] == n-1) {
                return i+1;
            }
        }

        return -1;
    }
};