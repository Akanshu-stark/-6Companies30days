class Solution {
private:
    long evaluated(long fop,long sop, char op){
        if(op=='+'){
            return fop+sop;
        }else if(op=='-'){
            return fop-sop;
        }else if(op=='*'){
            return (long)fop*sop;
        }
        return fop/sop;
    }
    public:
    int evalRPN(vector<string>& tokens) {
        stack<long> st;
        int s=tokens.size();
        for(int i=0;i<s;i++){
            if(tokens[i].size()==1 && tokens[i][0]<48){
            string op=tokens[i];
                long sop=st.top();
                st.pop();
                long fop=st.top();
                st.pop();
                long ans=evaluated(fop,sop,op[0]);
                st.push(ans);
            }
            else{
                st.push(stol(tokens[i]));
            }
        }
        return st.top();
    } 
};