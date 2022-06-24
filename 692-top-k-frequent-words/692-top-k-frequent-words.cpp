typedef pair<int,string> pis;

class Compare{
    public:
        bool operator()(pair<int,string>a, pair<int,string>b){
            if(a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int>mp;
        for(int i=0;i<words.size();i++) mp[words[i]]++;
        priority_queue<pis, vector<pis>, Compare>minh;
        for(auto it : mp){
            minh.push({it.second, it.first});
            if(minh.size() > k) minh.pop();
        }
        vector<string>res;
        while(!minh.empty()){
            res.push_back(minh.top().second);
            minh.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};