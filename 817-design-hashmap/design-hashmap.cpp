class MyHashMap {
public:
    vector<list<pair<int,int>>>bucket;
    int size=10000;
    MyHashMap() {
        bucket.resize(size);
    }

    int getHashIdx(int key){
        return key%size;
    }
    
    void put(int key, int value) {
        int idx=getHashIdx(key);
        auto &chain=bucket[idx];
        for(auto &it:chain){
            if(it.first==key){
                it.second=value;
                return;
            }
        }
        chain.emplace_back(key, value);
    }
    
    int get(int key) {
        int idx=getHashIdx(key);
        auto &chain=bucket[idx];
        if(chain.empty()) return -1;

        for(auto &it:chain){
            if(it.first==key) return it.second;
        }
        return -1;
    }
    
    void remove(int key) {
        int idx=getHashIdx(key);
        auto &chain=bucket[idx];
        for(auto it=chain.begin();it!=chain.end();){
            if(it->first==key){
                chain.erase(it);
                return;
            }
            it++;
        }
    }
};