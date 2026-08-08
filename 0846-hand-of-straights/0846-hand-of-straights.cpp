class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize!=0) return false;
        map<int,int> mp;
        for(int i=0;i<n;i++) mp[hand[i]]++;
        while(!mp.empty()){
            int x = mp.begin()->first;
            for(int i=1;i<=groupSize;i++){
                if(mp[x]==0) return false;
                mp[x]--;
                if(mp[x]==0) mp.erase(x);
                x++;
            }
        }
        return true;
    }
};