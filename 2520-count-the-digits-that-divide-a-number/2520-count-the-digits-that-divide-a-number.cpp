class Solution {
public:
    int countDigits(int num) {
        int count = 0;
        int orgNum = num;
        while(num>0){
            int divisor = num%10;
            num = num/10;
            if(orgNum%divisor == 0) count++;
        }
        return count;
    }
};