class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i = 0, j = 0, count = 0;
        double sum = 0, avg;
        
        while(j < arr.size()){
            sum += arr[j];
            if(j - i + 1 < k) j++;
            else if(j - i + 1 == k){
                avg = sum / k;
                if(avg >= threshold) count++;
                sum -= arr[i];
                i++;
                j++;
            }
        }
        return count;
    }
};