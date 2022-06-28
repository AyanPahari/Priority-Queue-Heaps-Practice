class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>res(n,-1);
        if(n < 2 * k + 1) return res;
        vector<int>ans;
        for(int i=0;i<k;i++) ans.push_back(-1);
        
        long long i = 0, j = 0, sum = 0, avg = 0;
        while(j < n){
            sum += nums[j];
            if(j - i + 1 < 2 * k + 1) j++;
            else if(j - i + 1 == 2 * k + 1){
                avg = sum / (2 * k + 1);
                ans.push_back(avg);
                sum -= nums[i];
                i++;
                j++;
            }
        }
        
        for(int i=0;i<k;i++) ans.push_back(-1);
        return ans;
    }
};