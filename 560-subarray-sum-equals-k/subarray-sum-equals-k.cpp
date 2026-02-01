/*Given an array of integers arr and an integer k,
return the total number of subarrays whose sum equals to k.*/
class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int count = 0;
        int sum = 0;
        unordered_map<int, int> mp;
        mp.insert({0, 1});
        for (int it : arr) {
            sum += it;
            count += mp[sum - k];
            mp[sum]++; 
        }
        return count;
    }
};