class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0, j = 0, zero_count = 0, maxi = INT_MIN;
        while(j < nums.size()){
            if(nums[j] == 0) zero_count++;
            if(zero_count <= 1) maxi = max(maxi, j - i + 1);
            else if(zero_count > 1){
                while(zero_count > 1){
                    if(nums[i] == 0) zero_count--;
                    i++;
                }
                if(zero_count <= 1) maxi = max(maxi, j - i + 1);
            }
            j++;
        }
        return maxi - 1;
    }
};