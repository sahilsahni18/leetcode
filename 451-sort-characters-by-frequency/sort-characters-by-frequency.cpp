class Solution {
public:
    string frequencySort(string s) { //USING MULTIMAP
        unordered_map<char,int> mp;
        multimap<int,char> r;
        string ss="";

        for(auto a : s)
            mp[a]++;

        for(auto a : mp)
            r.insert({a.second, a.first});
            
        for(auto it = r.rbegin(); it != r.rend(); ++it){
           for (int i = 0; i < it->first; ++i) {
                  ss += it->second;
                }
        } 

        return ss;
    }
};

