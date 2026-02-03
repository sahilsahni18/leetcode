class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
	int seen[52] = {0};
	for(auto r : ranges) 
		seen[r[0]]++, seen[r[1] + 1]--;
	for(int i = 1; i < 52; i++)
		seen[i] += seen[i - 1];
	for(int i = left; i <= right; i++) 
		if(!seen[i]) return false;
	return true;

}
};