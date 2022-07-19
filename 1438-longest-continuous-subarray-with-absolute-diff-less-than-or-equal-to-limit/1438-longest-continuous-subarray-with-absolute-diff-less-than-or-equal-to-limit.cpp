class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int i = 0, j = 0, mini = INT_MAX, maxi = INT_MIN, ans = 0;
        priority_queue<pair<int,int>>maxh;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>minh;
        
        while(j < nums.size()){
            minh.push({nums[j],j});
            maxh.push({nums[j],j});
            if(maxh.top().first - minh.top().first <= limit) ans = max(ans, j - i + 1);
            else{
                while(maxh.top().first - minh.top().first > limit){
                    i++;
                    while(maxh.top().second < i) maxh.pop();
                    while(minh.top().second < i) minh.pop();
                    
                }
                if(maxh.top().first - minh.top().first <= limit) ans = max(ans, j - i + 1);
            }
            j++;
        }
        return ans;
    }
};