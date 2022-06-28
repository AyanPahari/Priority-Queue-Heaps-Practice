// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int countOfSubstrings(string S, int K) {
        int i = 0, j = 0, count = 0, res = 0;
        unordered_map<char, int>mp;
        
        while(j < S.length()){
            mp[S[j]]++;
            if(mp[S[j]] == 1) count++;
            if(j - i + 1 < K) j++;
            else if(j - i + 1 == K){
                if(count == K - 1) res++;
                if(mp.find(S[i]) != mp.end()){
                    mp[S[i]]--;
                    if(mp[S[i]] == 0) count--;
                }
                i++;
                j++;
            }
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        int K;
        cin>>S;
        cin>>K;

        Solution ob;
        cout << ob.countOfSubstrings(S,K) << endl;
    }
    return 0;
}  // } Driver Code Ends