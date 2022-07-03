class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int i = 0, j = 0, mini = INT_MAX;
        unordered_map<int,int>mp;
        
        while(j < cards.size()){
            mp[cards[j]]++;
            if(mp.size() < j - i + 1){
                while(mp.size() < j - i + 1){
                    mini = min(mini, j - i + 1);
                    mp[cards[i]]--;
                    if(mp[cards[i]] == 0) mp.erase(cards[i]);
                    i++;
                }
            }
            j++;
        }
        return mini == INT_MAX ? -1 : mini;
    }
};