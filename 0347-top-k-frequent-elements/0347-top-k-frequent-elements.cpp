class Solution {
public:
    static bool cmp(const pair<int,int> a, const pair<int,int> b){
        if(a.second==b.second) return a.first>b.first;
        return a.second>b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) mp[nums[i]]++;
        vector<pair<int,int>> v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),cmp);
        vector<int> result;
        for(int i=0;i<k;i++){
            result.push_back(v[i].first);
        }
        return result;
    }
};