typedef long long ll;
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 1) return 1;
        priority_queue<ll, vector<ll>, greater<ll>>minh;
        minh.push(1);
        while(n!=1){
            long long temp = minh.top();
            minh.pop();
            if(temp % 2 == 0) minh.push(temp * 2);
            else if(temp % 3 == 0){
                minh.push(temp * 2);
                minh.push(temp * 3);
            }
            else{
                minh.push(temp * 2);
                minh.push(temp * 3);
                minh.push(temp * 5);
            }
            n--;
        }
        return minh.top();
    }
};