class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int g=numsDivide[0];
        sort(nums.begin(),nums.end());
        for(int i=0;i<numsDivide.size();i++){  
            g=gcd(g,numsDivide[i]);
        }
        for(int i=0;i<nums.size() and nums[i]<=g;i++){
            if(g%nums[i]==0) return i;
        }      
        return -1;
    }
};