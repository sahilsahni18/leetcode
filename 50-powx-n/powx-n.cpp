class Solution {
public:
    double myPow(double x, int n) {
        long long bf = n;
        if(bf< 0){
            x = 1/x;
            bf*= -1;
        }
        double ans = 1;
        while(bf> 0){
            if(bf% 2 == 1)ans *= x;
            x *= x;
            bf/= 2;
        }
        return ans;
        
    }
};