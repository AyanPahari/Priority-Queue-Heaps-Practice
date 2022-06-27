class Solution {   
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>v;
        priority_queue<pair<int,pair<int,int>>>pq;
        for(auto x:nums1){
            if(pq.size()==k&&x+nums2[0]>=pq.top().first)
                break;
            for(auto y:nums2){
                pq.push({(x+y),{x,y}});
                while(pq.size()>k)
                    pq.pop();
                if(pq.size()==k&&(x+y)>=pq.top().first)
                    break;
            }
        }
        while(pq.size()){
            v.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        
        return v;
    }
};