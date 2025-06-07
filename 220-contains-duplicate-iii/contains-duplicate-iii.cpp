class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        if (valueDiff < 0) return false;  // Constraint invalid

        unordered_map<long long, long long> buckets; // key: bucket ID, value: number in that bucket
        long long width = (long long)valueDiff + 1;  // Width of each bucket (avoid division overlap)

        for (int i = 0; i < nums.size(); ++i) {
            long long num = (long long)nums[i];

            // Step 1: Calculate the bucket ID for current number
            long long bucketId = num / width;
            if (num < 0) bucketId--;  // For negative numbers, adjust bucket mapping

            // Step 2: Check same bucket — value must be within valueDiff
            if (buckets.find(bucketId) != buckets.end()) {
                return true;
            }

            // Step 3: Check neighboring bucket on the left (bucketId - 1)
            if (buckets.find(bucketId - 1) != buckets.end() &&
                abs(num - buckets[bucketId - 1]) <= valueDiff) {
                return true;
            }

            // Step 4: Check neighboring bucket on the right (bucketId + 1)
            if (buckets.find(bucketId + 1) != buckets.end() &&
                abs(num - buckets[bucketId + 1]) <= valueDiff) {
                return true;
            }

            // Step 5: Insert current number into its bucket
            buckets[bucketId] = num;

            // Step 6: Maintain window of size indexDiff
            if (i >= indexDiff) {
                long long oldNum = (long long)nums[i - indexDiff];
                long long oldBucketId = oldNum / width;
                if (oldNum < 0) oldBucketId--;
                buckets.erase(oldBucketId);  // Remove out-of-window value
            }
        }

        return false;  // No pair found
    }
};
