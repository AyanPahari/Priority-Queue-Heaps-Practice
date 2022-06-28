class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int>mp;
        int i = 0, j = 0;
        for(int i=0;i<s1.length();i++) mp[s1[i]]++;
        int count = mp.size();
        
        while(j < s2.length()){
            if(mp.find(s2[j]) != mp.end()){
                mp[s2[j]]--;
                if(mp[s2[j]] == 0) count--;
            }
            if(j - i + 1 < s1.length()) j++;
            else if(j - i + 1 == s1.length()){
                if(count == 0) return true;
                if(mp.find(s2[i]) != mp.end()){
                    mp[s2[i]]++;
                    if(mp[s2[i]] == 1) count++;
                }
                i++;
                j++;
            }
        }
        return false;
    }
};