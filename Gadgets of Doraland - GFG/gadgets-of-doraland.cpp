// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    vector<int> TopK(vector<int>& array, int k){
        unordered_map<int,int>mp;
        for(int i=0;i<array.size();i++) mp[array[i]]++;
        priority_queue<pair<int,int>>maxh;
        vector<int>res;
        for(auto it:mp) maxh.push({it.second, it.first});
        while(k--){
            res.push_back(maxh.top().second);
            maxh.pop();
        }
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k ;
        cin>>n;
        
        vector<int>array(n);
        
        for(int i=0; i<n; i++)
            cin>>array[i];
            
        cin>>k;
        
        Solution obj;
        vector<int> result = obj.TopK(array,k);
        
        for(int i=0; i<result.size();i++)
            cout<<result[i]<<" ";

        cout<<"\n";

    }
    return 0;
}  // } Driver Code Ends