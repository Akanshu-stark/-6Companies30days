class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        long long  area=0;
       long long int xmin=INT_MAX;
       long long int xmax=INT_MIN;
       long long int ymin=INT_MAX;
       long long int ymax=INT_MIN;
        multiset<pair<int,int>>st;
        for(auto u:rectangles){
            xmin=min(xmin,u[0]*1ll);
            ymin=min(ymin,u[1]*1ll);
            xmax=max(xmax,u[2]*1ll);
            ymax=max(ymax,u[3]*1ll);
            area+=((u[2]-u[0])*1ll*(u[3]-u[1]))*1ll;  ////calculate total area of all rectangle 
            if(st.find({u[0],u[1]})!=st.end())
                st.erase({u[0],u[1]});    ///// if a corner already present int multi set then we will
            else st.insert({u[0],u[1]});  ///// erase it so that at the end only odd number of corners
        
            if(st.find({u[0],u[3]})!=st.end())///// left, if any corner left accept 4 outer corner
                st.erase({u[0],u[3]});   ///// it is not a rectange
            else st.insert({u[0],u[3]});
            
            if(st.find({u[2],u[1]})!=st.end())
                st.erase({u[2],u[1]});
            else st.insert({u[2],u[1]});
            
            if(st.find({u[2],u[3]})!=st.end())
                st.erase({u[2],u[3]});
            else st.insert({u[2],u[3]});
        }
       
        if(st.find({xmin,ymin})==st.end()||st.find({xmin,ymax})==st.end()||st.find({xmax,ymin})==st.end()||st.find({xmax,ymax})==st.end()|| st.size()!=4)return false;  //// checking that whether all 4 corner present or not and other than these 4 corner are present are not 
        return area==(xmax-xmin)*(ymax-ymin); 
    }
};