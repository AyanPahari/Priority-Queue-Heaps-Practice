class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int i = 0, j = 0, unused = INT_MAX, sum = 0, total_sum = 0;
        int window = cardPoints.size() - k;
        for(int i=0;i<cardPoints.size();i++) total_sum += cardPoints[i];
        
        if(window <= 0) return total_sum;
        
        while(j < cardPoints.size()){
            sum += cardPoints[j];
            if(j - i + 1 < window) j++;
            else if(j - i + 1 == window){
                unused = min(unused, sum);
                sum -= cardPoints[i];
                i++;
                j++;
            }
        }
        return total_sum - unused;
    }
};