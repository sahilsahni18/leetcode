class FreqStack {
public:
    unordered_map<int, int> freqMap;                 
    unordered_map<int, stack<int>> groupMap;         
    int maxFreq = 0;

    FreqStack() {}

    void push(int val) {
        int freq = ++freqMap[val];                   
        maxFreq = max(maxFreq, freq);                
        groupMap[freq].push(val);                    
    }

    int pop() {
        int val = groupMap[maxFreq].top();
        groupMap[maxFreq].pop();
        freqMap[val]--;                              
        if (groupMap[maxFreq].empty()) {
            maxFreq--;                               
        }
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */