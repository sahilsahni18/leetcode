class Solution {
public:
	char findTheDifference(string s, string t) {
		char res = t[s.size()];
		for(int i = 0; i < s.size(); i++){
			res ^= s[i] ^ t[i];
		}
		return res;
	}
};