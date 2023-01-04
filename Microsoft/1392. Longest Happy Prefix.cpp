class Solution {
public:
    string longestPrefix(string s) {
        int n=s.length();
		vector<int> kmp(n);
		int i=1,j=0;
		while(i<n) {
			if(s[i]==s[j]) {
				kmp[i++]=++j;
			}
			else {
				if(j) j=kmp[j-1];
				else i++;
			}
		}
		return s.substr(0,kmp[n-1]);
    }
};