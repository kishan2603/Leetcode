class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int x = n/8;
        int y = n%8;
        if(x==0) return y;
        else if(x==1) return 8 + (x+1)*y;
        else if(x==2) return 24 + (x+1)*y;
        return 48 + (x+1)*y;
    }
};