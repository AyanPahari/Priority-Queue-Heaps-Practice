// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        for(int i=0;i<nums.size();i++) mp[nums[i]]++;
        priority_queue<pair<int,int>>maxh;
        vector<int>res;
        for(auto it : mp){
            maxh.push({it.second, it.first});
        }
        while(k--){
            res.push_back(maxh.top().second);
            maxh.pop();
        }
        return res;
    }
};


// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends