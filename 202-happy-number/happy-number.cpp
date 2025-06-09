class Solution {
public:
    int sum_of_square_of_digits(int n){
        int sum = 0;
        while(n>0){
            int i = n%10;
            sum += (i*i);
            n/=10;
        }
        return sum;
    }

    bool isHappy(int n) {
       int slow = n;
       int fast = sum_of_square_of_digits(n);
       while(fast!=1 && slow != fast){
            slow = sum_of_square_of_digits(slow);
            fast = sum_of_square_of_digits(sum_of_square_of_digits(fast));
       }
       return fast == 1;
    }
};