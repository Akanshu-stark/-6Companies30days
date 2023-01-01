class Solution {
public:
    string getHint(string secret, string guess) {
        int len = secret.size();
        int bnum = 0, cnum = 0; // bnum is number of bulls, cnum is number of cows
        vector<int> cnt1(10, 0), cnt2(10, 0);
        for(int i = 0; i < len; i ++) {
            int n1 = secret[i] - '0', n2 = guess[i] - '0';
            if(n1 == n2) bnum ++;
            else {
                if(cnt2[n1]) {
                    cnum ++;
                    cnt2[n1] --;
                }
                else cnt1[n1] ++;
                if(cnt1[n2]) {
                    cnum ++;
                    cnt1[n2] --;
                }
                else cnt2[n2] ++;
            }
        }
        return to_string(bnum) + "A" + to_string(cnum) + "B"; 
    }
};