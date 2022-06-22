typedef pair<int,int> pi;

class Compare{
    public:
        bool operator()(pair<int,int> a, pair<int,int> b){
            if(a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        }
};

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it:nums) mp[it]++;
        priority_queue<pi, vector<pi>, Compare>minh;
        for(auto it : mp) minh.push({it.second, it.first});
        vector<int>res;
        
        while(!minh.empty()){
            int count = minh.top().first;
            int val = minh.top().second;
            while(count--) res.push_back(val);
            minh.pop();
        }
        return res;
    }
};