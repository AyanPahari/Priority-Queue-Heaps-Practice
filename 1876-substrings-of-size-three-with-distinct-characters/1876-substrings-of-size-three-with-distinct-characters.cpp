class Solution {
public:
    int countGoodSubstrings(string s) {
        int i = 0, j = 0, count, res = 0;
        unordered_map<char,int>mp;
        
        while(j < s.length()){
            count = 0;
            mp[s[j]]++;
            for(auto it:mp){
                if(it.second > 0) count++;
            }
            if(j - i + 1 < 3) j++;
            else if(j - i + 1 == 3){
                if(count == 3) res++;
                if(mp.find(s[i]) != mp.end()){
                    mp[s[i]]--;
                    if(mp[s[i]] == 0) count--;
                }
                i++;
                j++;
            }
        }
        return res;
    }
};