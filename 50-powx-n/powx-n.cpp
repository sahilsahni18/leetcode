class Solution {
public:
    double func(double x,long long N){
      if(N==0)  return 1;
      if(N==1)  return x;
      
      if(N & 1) return x*func(x*x,N>>1);
      else return func(x*x,N>>1);
    }
    
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(x==0) return 0;
        if(x==1) return x;
        if (x == -1) {     
            return (n % 2 == 0) ? 1 : -1;
        }
        
        long long N=n;
        if(N<0){
            N=abs(N);
            x=1/x;
        }

        return func(x,N);
    }
};