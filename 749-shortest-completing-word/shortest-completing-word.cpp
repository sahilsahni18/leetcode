class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        
        int i, j, flag=0, flag1=0, c=0;
        char lp;
        string s;
        unordered_map<char, int> m;


        for(i=0 ; i<licensePlate.length() ; i++)
        {
            if(licensePlate[i]>=65 && licensePlate[i]<=90 || licensePlate[i]>=97 && licensePlate[i]<=122)
            {
                lp = tolower(licensePlate[i]);
                m[lp]++;
            }
        }


        for(i=0 ; i<words.size() ; i++)
        {
            c=0;
            flag=0;
            for(auto it:m)
            {
                for(j=0 ; j<words[i].size() ; j++)
                {
                    if(it.first==words[i][j])
                    {
                        c++;
                        if(count(words[i].begin(), words[i].end(), words[i][j])<it.second)
                        {
                            flag=1;
                        }
                        break;
                    }
                }
                if(flag==1)
                {
                    break;
                }
            }
            if(flag==0 && c==m.size() && flag1==0)
            {
                s = words[i];
                flag1=1;
            }
            else if(flag==0 && c==m.size() && flag1==1)
            {
                if(s.length()>words[i].length())
                {
                    s = words[i];
                }
            }
        }
        return s;
    }
};