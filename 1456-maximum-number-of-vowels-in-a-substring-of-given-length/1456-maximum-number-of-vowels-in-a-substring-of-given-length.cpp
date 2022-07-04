class Solution {
public:
    int maxVowels(string s, int k) {
        for(int i=0;i<s.length();i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') s[i] = '1';
            else s[i] = '0';
        }
        int i = 0, j = 0, count = 0, maxi = INT_MIN;
        while(j < s.length()){
            if(s[j] == '1') count++;
            if(j - i + 1 == k){
                maxi = max(maxi, count);
                if(s[i] == '1') count--;
                i++;
            }
            j++;
        }
        return maxi;
    }
};