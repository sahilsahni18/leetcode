class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        vector<vector<string>> ans;
        if (!wordSet.count(endWord)) return ans;

        unordered_map<string, vector<string>> parent;
        unordered_set<string> currentLevel, nextLevel;
        currentLevel.insert(beginWord);

        bool found = false;

        while (!currentLevel.empty() && !found) {
            for (auto &w : currentLevel) wordSet.erase(w);

            for (auto &word : currentLevel) {
                string cur = word;
                for (int i = 0; i < cur.size(); i++) {
                    char orig = cur[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == orig) continue;
                        cur[i] = c;

                        if (wordSet.count(cur)) {
                            nextLevel.insert(cur);
                            parent[cur].push_back(word);
                            if (cur == endWord) found = true;
                        }
                    }
                    cur[i] = orig;
                }
            }

            currentLevel.clear();
            swap(currentLevel, nextLevel);
        }

        if (!found) return ans;

        vector<string> path{endWord};
        dfs(endWord, beginWord, parent, path, ans);
        return ans;
    }

private:
    void dfs(string word, string &beginWord,
             unordered_map<string, vector<string>> &parent,
             vector<string> &path,
             vector<vector<string>> &ans) {

        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        for (auto &p : parent[word]) {
            path.push_back(p);
            dfs(p, beginWord, parent, path, ans);
            path.pop_back();
        }
    }
};
