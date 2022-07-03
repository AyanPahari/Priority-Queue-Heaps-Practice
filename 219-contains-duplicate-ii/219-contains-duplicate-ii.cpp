class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i = 0, j = 0;
        unordered_map<int,int>mp;
        
        while(j < nums.size()){
            mp[nums[j]]++;
            if(mp.size() < j - i + 1){
                while(mp.size() < j - i + 1){
                    if(abs(j - i) <= k) return true;
                    mp[nums[i]]--;
                    if(mp[nums[i]] == 0) mp.erase(nums[i]);
                    i++;
                }
            }
            j++;
        }
        return false;
    }
};