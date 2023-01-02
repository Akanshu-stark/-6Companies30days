//A smal trick that every time we calculate new F(n) we increase ony by sum of all elements subtract the last element multiply by size of array.

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long ans=0,sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
             ans+=nums[i]*i;
             sum+=nums[i];
        }
        long res=ans;
        for(int i=n-1;i>=0;i--){
            ans+=sum-nums[i]*n;
            res=max(ans,res);
        }
        return res;
    }
};