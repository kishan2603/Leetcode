class Solution {
public:
    vector<long long> prefix;
    vector<long long> number;
    vector<long long> digits;
    vector<long long> p;
    const int mod = 1e9+7;
    int f(string& s,int l,int r){
        int n = s.size();
        long long sum;
        long long x;
        if(l==0){
            sum = (prefix[r])%mod;
            x = (number[r])%mod;
        }
        else{
            sum = (prefix[r]-prefix[l-1]+mod)%mod;
            x = (number[r] - (number[l-1]*p[digits[r]-digits[l-1]])%mod + mod)%mod;
        }
        return (sum*x)%mod;
    }
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.size();
        prefix.resize(m,0);
        number.resize(m,0);
        digits.resize(m,0);
        p.resize(m+1,0);
        p[0] = 1;
        for (int i = 1; i <= m; i++) p[i] = p[i - 1] * 10 % mod;
        prefix[0] = 1LL*s[0]-'0';
        number[0] = 1LL*s[0]-'0';
        if(s[0]=='0') digits[0] = 0;
        else digits[0] = 1;
        for(int i=1;i<m;i++){ 
            prefix[i] = prefix[i-1] + 1LL*(s[i]-'0');
            if(s[i]=='0'){
                number[i] = number[i-1];
                digits[i] = digits[i-1];
            }
            else{
                number[i] = (number[i-1]*10 + 1LL*(s[i]-'0'))%mod;
                digits[i] = digits[i-1] + 1LL;
            }
        }
        vector<int> result(queries.size(),0);
        for(int i=0;i<queries.size();i++){
            result[i] = f(s,queries[i][0],queries[i][1]);
        }
        return result;
    }
};