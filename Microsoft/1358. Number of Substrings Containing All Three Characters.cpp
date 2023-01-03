class Solution {
public:
    int numberOfSubstrings(string s) {
       unordered_map<char,int>mp;
        int count=0;
        int i=0,j=0;
        while(i<=s.size())
        {
            mp[s[i]]++;
            while(mp['a']>0 && mp['b']>0 && mp['c']>0)
            {
                count+=s.size()-i;
                mp[s[j]]--;
                j++;
            }
            i++;
        }
        return count; 
    }
};