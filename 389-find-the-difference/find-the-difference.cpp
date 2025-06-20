class Solution {
public:
	char findTheDifference(string s, string t) {
		int sum1 = 0;
		int sum2 = t[s.size()];
		for(int i = 0; i < s.length(); i++){
			sum1 += s[i];
			sum2 += t[i];
		}
		return char(abs(sum2 - sum1));
	}
};