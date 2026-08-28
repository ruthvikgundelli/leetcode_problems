class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> st(wordList.begin(), wordList.end());
        if(!st.count(endWord)) return 0;

        queue<string> q;
        q.push(beginWord);
        int ans = 1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                string node = q.front();
                q.pop();
                if(node == endWord) return ans;
                string temp = node;
                for(int i = 0; i < node.size(); i++){
                    for(int j = 0; j < 26; j++){
                        node[i] = 'a' + j;
                        if(node != temp && st.count(node)){
                            q.push(node);
                            st.erase(node);
                        }
                    }
                    node[i] = temp[i];
                }
            }
            ans++;
        }
        return 0;
    }
};