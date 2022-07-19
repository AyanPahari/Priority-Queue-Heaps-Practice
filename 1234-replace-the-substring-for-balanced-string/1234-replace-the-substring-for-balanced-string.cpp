class Solution {
public:
    
    bool isValid(unordered_map<char,int>& mp, int target){
        for(auto it: mp){
            if(it.second > target) return false;
        }
        return true;
    }
    
    int balancedString(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++) mp[s[i]]++;
        int target = s.length() / 4;
        if(isValid(mp, target)) return 0;
        
        int i = 0, j = 0, mini = INT_MAX;
        while(j < s.length()){
            mp[s[j]]--;
            if(isValid(mp, target)){
                while(isValid(mp, target)){
                    mini = min(mini, j - i + 1);
                    mp[s[i]]++;
                    i++;
                }
            }
            j++;
        }
        return mini;
    }
};