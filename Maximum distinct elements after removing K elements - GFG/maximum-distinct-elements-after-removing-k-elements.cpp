// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    int maxDistinctNum(int arr[], int n, int k)
    {
    	priority_queue<int>maxh;
    	unordered_map<int,int>mp;
    	for(int i=0;i<n;i++) mp[arr[i]]++;
    	for(auto it:mp) maxh.push(it.second);
    	while(k--){
    	    if(maxh.size() == 0) break;
    	    int temp = maxh.top();
    	    maxh.pop();
    	    temp--;
    	    if(temp > 0) maxh.push(temp);
    	}
    	return maxh.size();
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,i,k;
	cin>>n>>k;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout <<ob.maxDistinctNum(arr, n, k)<<"\n";
	  }
	return 0;
}
  // } Driver Code Ends