class Solution {
public:
    int reverse(int x) {
        long reverseNum=0;
        while(x){
            int digit=x%10;
            reverseNum=reverseNum*10+digit;
            x=x/10;
             // Check for overflow and underflow
            if (reverseNum > INT_MAX || reverseNum < INT_MIN) {
                return 0;
            }
        }
        return reverseNum;
    }
};