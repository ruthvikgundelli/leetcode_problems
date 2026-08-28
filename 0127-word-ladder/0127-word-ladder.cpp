class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int check = 0;
        for(auto word : wordList){
            if(word == endWord) check++;
        }

        if(!check) return 0;

        int n = beginWord.size();
        int m = wordList.size();

        vector<string> words;
        words.push_back(beginWord);

        for(auto word : wordList){
            words.push_back(word);
        }

        vector<vector<int>> adj(m+1);
        vector<int> vis(m+1, 0);

        for(int i = 0; i < m + 1; i++){
            for(int j = i + 1; j < m + 1; j++){
                int cnt = 0;

                for(int k = 0; k < n; k++){
                    if(words[i][k] != words[j][k]){
                        cnt++;
                    }
                }

                if(cnt == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> dist(m + 1, INT_MAX);
        queue<pair<int,int>> q;
        q.push({0, 1});
        dist[0] = 1;

        while(!q.empty()){
            auto [node, dis] = q.front();
            q.pop();

            if(words[node] == endWord){
                return dis;
            }

            for(auto ad : adj[node]){
                if(dist[ad] == INT_MAX){
                    dist[ad] = dis + 1;
                    q.push({ad, dist[ad]});
                }
            }
        }
        return 0;
    }
};