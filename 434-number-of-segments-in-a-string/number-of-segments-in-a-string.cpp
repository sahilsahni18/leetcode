class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        bool inSegment = false;

        for (char c : s) {
            if (c != ' ') {
                // If the character is not a space, we are in a segment
                if (!inSegment) {
                    inSegment = true;
                    count++;
                }
            } else {
                // If the character is a space, we are not in a segment
                inSegment = false;
            }
        }

        return count;
    }
};