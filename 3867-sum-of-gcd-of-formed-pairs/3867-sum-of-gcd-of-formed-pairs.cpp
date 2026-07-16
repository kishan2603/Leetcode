class Solution {
public:
    long long gcd(int a,int b){
        int temp = a;
        a = max(a,b);
        b = min(temp,b);
        while(b!=0){
            int t = b;
            b = a%b;
            a = t;
        }
        return a;
    }
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n,1);
        int mx = nums[0];
        prefixGcd[0] = nums[0];
        for(int i=1;i<n;i++){
            mx = max(mx,nums[i]);
            prefixGcd[i] = gcd(mx,nums[i]);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        int i = 0;
        int j = n-1;
        long long ans = 0;
        while(i<j){
            ans = ans + 1LL*gcd(prefixGcd[i],prefixGcd[j]);
            i++;
            j--;
        }
        return ans;
    }
};