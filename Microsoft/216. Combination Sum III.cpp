class Solution {
public:
vector<vector<int>> ans;
    int sum(vector<int> v){
        int s=0;
        for(int x:v){
            s+=x;
        }
        return s;
    }
    void combine(int k,int n,vector<int>& vec,int i){
        if(k==0){
            if(sum(vec)==n){
                ans.push_back(vec);
                return;
            }
        }
        if(i>9){
            return;
        }
        vec.push_back(i);
        combine(k-1,n,vec,i+1);
        vec.pop_back();
        combine(k,n,vec,i+1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> vec;
        combine(k,n,vec,1);
        return ans;
    }
};