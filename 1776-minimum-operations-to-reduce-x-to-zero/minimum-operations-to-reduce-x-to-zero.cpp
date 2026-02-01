/*given an integer array nums and an integer x.
In one operation, you can either remove the leftmost
or the rightmost element from the array nums
and subtract its value from x
Return the minimum number of operations
to reduce x to exactly 0 if it is possible, otherwise, return -1.*/
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {//start 
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        int rem = total - x;
        if (rem == 0)
            return nums.size();

        int length = maxSubArrayLen(rem, nums);

        if (length == 0)
            return -1;
        return n - length;
    }

    int maxSubArrayLen(int k, vector<int>& A) {//Code for Maximum size subarray given sum
        int sum = 0;
        int res = 0;
        unordered_map<int, int> mp; 
        mp[0] = -1;

        for (int i = 0; i < A.size(); i++) {
            sum += A[i];
            if (mp.find(sum - k) != mp.end())
                res = max(res, i - mp[sum - k]);

            if (mp.find(sum) == mp.end())
                mp[sum] = i;
        }
        return res;
    }
};