class Solution {
public:
    
    int get_count(unordered_map<char, int> &mp){
        int maxi = 0;
        for(auto it:mp){
            maxi = max(maxi, it.second);
        }
        return maxi;
    }
    
    int characterReplacement(string s, int k) {
        int i = 0, j = 0;
        unordered_map<char,int>mp;
        int maxi = 0;
        
        while(j < s.length()){
            mp[s[j]]++;
            if(j - i + 1 - get_count(mp) <= k){
                maxi = max(maxi, j - i + 1);
            }
            else{
                while(j - i + 1 - get_count(mp) > k){
                    mp[s[i]]--;
                    i++;
                }
                if(j - i + 1 - get_count(mp) <= k){
                maxi = max(maxi, j - i + 1);
                }
            }
            j++;
        }
        return maxi;
    }
};