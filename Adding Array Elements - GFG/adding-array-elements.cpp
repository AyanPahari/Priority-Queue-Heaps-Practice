// { Driver Code Starts

#include <bits/stdc++.h>

using namespace std;



 // } Driver Code Ends


class Solution{
  public:
    int minOperations(int arr[], int n, int k) {
        int op = 0;
        priority_queue<int, vector<int>, greater<int>>minh;
        for(int i=0;i<n;i++) minh.push(arr[i]);
        while(1){
            if(minh.size() == 1 && minh.top() < k) return -1;
            int temp1 = minh.top();
            if(temp1 >= k) break;
            minh.pop();
            int temp2 = minh.top();
            minh.pop();
            minh.push(temp1 + temp2);
            op++;
        }
        return op;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution obj;
        int ans = obj.minOperations(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends