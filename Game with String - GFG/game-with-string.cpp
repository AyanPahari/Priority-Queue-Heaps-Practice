// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        unordered_map<char, int>mp;
        for(int i=0;i<s.length();i++) mp[s[i]]++;
        priority_queue<int>maxh;
        for(auto it:mp) maxh.push(it.second);
        
        while(!maxh.empty()){
            int temp = maxh.top();
            maxh.pop();
            temp--;
            maxh.push(temp);
            k--;
            if(k == 0) break;
        }
        
        int res = 0;
        while(!maxh.empty()){
            res += maxh.top() * maxh.top();
            maxh.pop();
        }
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}  // } Driver Code Ends