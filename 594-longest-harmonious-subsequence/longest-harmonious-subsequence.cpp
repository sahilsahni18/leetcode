class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0, r = 1, MaxLen = 0;
        // two-pointer approach
        while (l < nums.size()) {
            while (r < nums.size() && abs(nums[r] - nums[l]) <= 1) {
                if (abs(nums[r] - nums[l]) == 1) {
                    MaxLen = max(MaxLen, r - l + 1); 
                }
                r++; 
            }
            l++; 
        }
        
        return MaxLen;
    }
};