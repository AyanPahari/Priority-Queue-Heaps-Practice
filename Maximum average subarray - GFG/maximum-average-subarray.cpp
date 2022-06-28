// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int findMaxAverage(int nums[], int n, int k) {
        int i = 0, j = 0, index = 0;
        double avg = INT_MIN, sum = 0;
        
        while(j < n){
            sum += nums[j];
            if(j - i + 1 < k) j++;
            else if(j - i + 1 == k){
                // avg = max(avg, sum / k);
                if(avg < sum / k){
                    avg = sum / k;
                    index = i;
                }
                sum -= nums[i];
                i++;
                j++;
            }
        }
        return index;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxAverage(arr, n, k);
        for (int i = ans; i < ans + k; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends