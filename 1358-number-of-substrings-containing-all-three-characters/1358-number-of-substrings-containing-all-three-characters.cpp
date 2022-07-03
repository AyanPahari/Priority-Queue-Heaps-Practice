class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int>mp;
        int i = 0, j = 0, count = 3, ans = 0;
        
        while(j < s.length()){
            mp[s[j]]++;
            if(mp[s[j]] == 1) count--;
            while(count == 0){
                ans += s.length() - j;
                mp[s[i]]--;
                if(mp[s[i]] == 0) count++;
                i++;
            }
            j++;
        }
        return ans;
    }
};