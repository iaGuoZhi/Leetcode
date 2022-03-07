class Solution {
public:
    int addDigits(int num) {
        int res = 0;
        int i;
        if(num <= 0)
            return 0;

        while(num > 0){
            i = num % 10;
            num /= 10;

            res = (res + i + (res + i)/10) % 10;
        }
        return res;
    }
};
