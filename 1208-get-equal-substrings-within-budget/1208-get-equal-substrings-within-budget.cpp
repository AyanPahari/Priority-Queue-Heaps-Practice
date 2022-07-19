class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i = 0, j = 0, sum = 0, maxi = 0;
        
        while(j < s.length()){
            sum += abs(s[j] - t[j]);
            if(sum <= maxCost) maxi = max(maxi, j - i + 1);
            else{
                while(sum > maxCost){
                    sum -= abs(s[i] - t[i]);
                    i++;
                }
                if(sum <= maxCost) maxi = max(maxi, j - i + 1);
            }
            j++;
        }
        return maxi;
    }
};