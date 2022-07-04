class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j = 0, zero_count = 0, maxi = INT_MIN;
        while(j < nums.size()){
            if(nums[j] == 0) zero_count++;
            if(zero_count <= k) maxi = max(maxi, j - i + 1);
            else if(zero_count > k){
                while(zero_count > k){
                    if(nums[i] == 0) zero_count--;
                    i++;
                }
                if(zero_count <= k) maxi = max(maxi, j - i + 1);
            }
            j++;
        }
        return maxi;
    }
};