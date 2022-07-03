// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        unordered_map<char,int>mp;
        int i = 0, j = 0, count, mini = INT_MAX;
        for(int i=0;i<str.length();i++) mp[str[i]]++;
        count = mp.size();
        mp.clear();
        
        while(j < str.length()){
            mp[str[j]]++;
            if(mp[str[j]] == 1) count--;
            while(count == 0){
                mini = min(mini, j - i + 1);
                mp[str[i]]--;
                if(mp[str[i]] == 0) count++;
                i++;
            }
            j++;
        }
        return mini;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends