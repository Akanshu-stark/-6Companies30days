class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
     vector <pair <int,int>> projects;
        for(int i = 0; i<profits.size(); i++) 
        projects.push_back({capital[i],profits[i]});
        sort(projects.begin(),projects.end());
        priority_queue <int> pq;
        int currentCapital = w, i=0;
        while(i<projects.size() && k) {
            if(currentCapital >= projects[i].first) {
                pq.push(projects[i++].second); 
            } else {
                if(!pq.empty()){
                    currentCapital += pq.top();
                    pq.pop();
                    k--;
                }
                else return currentCapital; 
            }
        }
        while(!pq.empty() && k > 0) {
            currentCapital += pq.top();
            pq.pop();
            k--;
        }

        return currentCapital;   
    }
};