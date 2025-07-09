class Solution {
public:
    int arrangeCoins(int n) {
        int start=1;
        int end=n;
        int ans;
        long long mid=start+(end-start)/2;
        while(start<=end){
            long long calc=mid*(mid+1)/2; 
            if(calc<=n){
                ans=mid;
                start=mid+1;
            }else if(calc>n){
                end=mid-1;
            }
            mid=start+(end-start)/2;
        }
        return  ans;
    }
};