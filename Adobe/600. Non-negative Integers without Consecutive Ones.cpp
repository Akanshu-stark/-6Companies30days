class Solution {
public:
    int upperLimit; // n
    int count = 1; // ans has an initial value of 1 because of the number 0 being a viable answer to all 1<=n<=1e9
    
    void dfs(int currentNum, int lastBit) {
        if (currentNum > upperLimit) return; // our current value is greater than n, stop traversing
        ++count;  // viable value, increment count
        if (lastBit == 0) dfs(currentNum * 2 + 1, 1);
        dfs(currentNum*2, 0);
    }
    
    
public:
    int findIntegers(int n) {
        upperLimit = n;
        dfs(1,1);
        return count;
    }
};