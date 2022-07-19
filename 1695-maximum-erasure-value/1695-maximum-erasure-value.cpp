class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i = 0, j = 0, sum = 0, maxi = 0;
        unordered_map<int,int>mp;
        
        while(j < nums.size()){
            mp[nums[j]]++;
            sum += nums[j];
            if(j - i + 1 == mp.size()){
                maxi = max(maxi, sum);
            }
            else if(j - i + 1 > mp.size()){
                while(j - i + 1 > mp.size()){
                    sum -= nums[i];
                    mp[nums[i]]--;
                    if(mp[nums[i]] == 0) mp.erase(nums[i]);
                    i++;
                }
                if(j - i + 1 == mp.size()){
                maxi = max(maxi, sum);
                }
            }
            j++;
        }
        return maxi;
    }
};