class Solution {
public:
    int findGCD(vector<int>& nums) {
        int a = INT_MIN;
        int b = INT_MAX;
        for(int i=0;i<nums.size();i++){
            a = max(a,nums[i]);
            b = min(b,nums[i]);
        }
        while(b!=0){
            int temp = b;
            b = a%b;
            a = temp;
        }
        return a;
    }
};