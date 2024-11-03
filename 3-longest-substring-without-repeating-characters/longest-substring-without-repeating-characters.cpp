// METHOD 2: ALWAYS EASY TO IMPLEMENT

class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int n = str.size();
        if (n == 0)
            return 0;

        int maxans = 0;
        int left = 0, right = 0; 
        unordered_set<char> us;

        while (right < n) {
            // if right char is in the set, remove elements from the left until it's removed
            while (us.find(str[right]) != us.end()) {
                us.erase(str[left]);
                left++;
            }

            // Add the current right character to the set and move right pointer
            us.insert(str[right]);
            right++;

            // Update the max length of substring found  - both are correct
            // maxans = max(maxans, right - left); // Window size
            maxans = max(maxans, (int)us.size()); // Window size

        }
        return maxans;
    }
};


// VVIP NOTE: 
// - us.size(): return an unsigned int
// - max: it requires both of its arguments to be of the same type.
// - so you can't do: max(int, unsigned), even though both are integers, but have different range
// - so we must typecast us.size() from unsigned integer to normal integer (to make datatypes of both the parameters same) 