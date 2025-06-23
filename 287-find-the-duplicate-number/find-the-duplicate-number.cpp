class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> numCount; 

    
        for (int num : nums) {
            if (numCount.find(num) != numCount.end()) {
                return num;
            }
            numCount[num] = 1;
        }

        return -1;
    }
};