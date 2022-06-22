class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int>mp;
        for(auto it:s) mp[it]++;
        priority_queue<pair<int, char>>maxh;
        for(auto it:mp) maxh.push({it.second, it.first});
        string str = "";
        while(!maxh.empty()){
            int count = maxh.top().first;
            char val = maxh.top().second;
            while(count--) str.push_back(val);
            maxh.pop();
        }
        return str;
    }
};