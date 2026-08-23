class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) 
    {
        int cnt = 0;
        for(vector<string> &s:items)
        {
             
            if(ruleKey == "type")
            {
                if(ruleValue == s[0]) 
                {
                    cnt++; 
                }
            }
            else if(ruleKey == "color")
            {
                if(ruleValue == s[1])
                {
                    cnt++; 
                }
            }
            else
            {
                if(ruleValue == s[2]) 
                {
                    cnt++; 
                }
            }
        }
        return cnt;
    }

};