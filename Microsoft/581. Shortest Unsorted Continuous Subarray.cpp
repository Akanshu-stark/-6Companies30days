class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> cp = nums;
        sort(cp.begin(), cp.end());
        int first = 0, last = 0;
        bool flag = false;
        for (int i = 0; i < nums.size(); i++) {
            if (cp[i] != nums[i]) {
                flag = true;
                first = i;
                break;
            }
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (cp[i] != nums[i]) {
                flag = true;
                last = i;
                break;
            }
        }
        if (flag)
            return last - first + 1;
        return 0;
    }
};