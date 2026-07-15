class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = n*(2 + (n-1)*2)/2;
        int sumEven = n*(4 + (n-1)*2)/2;
        int a = max(sumOdd,sumEven);
        int b = min(sumOdd,sumEven);
        while(b!=0){
            int temp = b;
            b = a%b;
            a = temp;
        }
        return a;
    }
};