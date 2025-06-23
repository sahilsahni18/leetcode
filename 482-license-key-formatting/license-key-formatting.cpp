class Solution {
public:
    string licenseKeyFormatting(string s, int k) {

        string l;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!='-')
            {
                l.push_back(toupper(s[i]));
            }
        }
        reverse(l.begin(),l.end());
        int count=0;
        string ans;

        for(int i=0;i<l.length();i++)
        {
            count++;
            ans.push_back(l[i]);

            if(count==k&&i!=l.length()-1)
            {
                ans.push_back('-');
                count=0;
            }
              
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};