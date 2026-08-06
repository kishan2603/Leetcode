class Solution {
public:
    int product(int n){
        int ans = 1;
        while(n>0){
            int ld = n%10;
            ans *= ld;
            n = n/10;
        }
        return ans;
    }
    int smallestNumber(int n, int t) {
        while(product(n)%t!=0){
            n++;
        }
        return n;
    }
};