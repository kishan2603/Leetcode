class Solution {
public:
    static bool cmp(const pair<char,int>& a,const pair<char,int>& b){
        if(a.second==b.second){
            return a.first>b.first;
        }
        return a.second>b.second;
    }
    int minimumPushes(string word) {
        unordered_map<char,int> mp;
        for(char c : word) mp[c]++;
        vector<pair<char,int>> v;
        for(auto pp : mp) v.push_back(pp);
        sort(v.begin(),v.end(),cmp);
        int ans = 0;
        int counter = 0;
        for(auto pp : v){
            counter++;
            if(counter>24) ans += pp.second*4;
            else if(counter>16) ans += pp.second*3;
            else if(counter>8) ans += pp.second*2;
            else ans += pp.second;
        }
        return ans;
    }
};