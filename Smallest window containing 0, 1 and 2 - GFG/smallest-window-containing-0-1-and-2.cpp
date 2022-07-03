// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        int i = 0, j = 0;
        int count = 3, mini = INT_MAX;
        unordered_map<char, int>mp;
        mp['0']++;
        mp['1']++;
        mp['2']++;
        
        while(j < S.length()){
            mp[S[j]]--;
            if(mp[S[j]] == 0) count--;
            if(count == 0){
                while(count == 0){
                    mini = min(mini, j - i + 1);
                    mp[S[i]]++;
                    if(mp[S[i]] == 1) count++;
                    i++;
                }
            }
            j++;
        }
        return mini == INT_MAX ? -1 : mini;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}  // } Driver Code Ends