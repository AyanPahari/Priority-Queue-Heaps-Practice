class Solution {
public:
    
    int at_most_k_F(string s, int k){
        int i = 0, j = 0, count_F = 0, maxi = INT_MIN;
        while(j < s.length()){
            if(s[j] == 'F') count_F++;
            if(count_F <= k) maxi = max(maxi, j - i + 1);
            else if(count_F > k){
                while(count_F > k){
                    if(s[i] == 'F') count_F--;
                    i++;
                }
                if(count_F <= k) maxi = max(maxi, j - i + 1);
            }
            j++;
        }
        return maxi;
    }
    
    int at_most_k_T(string s, int k){
        int i = 0, j = 0, count_T = 0, maxi = INT_MIN;
        while(j < s.length()){
            if(s[j] == 'T') count_T++;
            if(count_T <= k) maxi = max(maxi, j - i + 1);
            else if(count_T > k){
                while(count_T > k){
                    if(s[i] == 'T') count_T--;
                    i++;
                }
                if(count_T <= k) maxi = max(maxi, j - i + 1);
            }
            j++;
        }
        return maxi;
    }
    
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(at_most_k_F(answerKey, k), at_most_k_T(answerKey, k));
    }
};