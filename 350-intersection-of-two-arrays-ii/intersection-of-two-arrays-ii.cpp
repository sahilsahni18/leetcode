class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> counts;
        vector<int> result;

        // Step 1: Count occurrences of nums1 elements
        for (int num : nums1) {
            counts[num]++;
        }

        // Step 2: Traverse nums2 and collect common elements
        for (int num : nums2) {
            if (counts[num] > 0) {
                result.push_back(num);
                counts[num]--;
            }
        }

        return result;
    }
};
