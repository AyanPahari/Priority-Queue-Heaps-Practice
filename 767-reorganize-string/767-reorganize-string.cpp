class Solution {
public:
    string reorganizeString(string s) {
        string str;
        unordered_map<char,int>mp;
        priority_queue<pair<int,char>>maxh;
        for(int i=0;i<s.length();i++) mp[s[i]]++;
        for(auto it: mp) maxh.push({it.second, it.first});
        
        pair<int,char> block = maxh.top();
        maxh.pop();
        str.push_back(block.second);
        block.first = block.first - 1;
        while(!maxh.empty()){
            pair<int,char> temp = maxh.top();
            maxh.pop();
            str.push_back(temp.second);
            temp.first = temp.first - 1;
            if(block.first > 0) maxh.push(block);
            block = temp;
        }
        if(block.first > 0) return "";
        else return str;
    }
};