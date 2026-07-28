class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> s;
        vector<int> result;
        for(int i=0;i<n;i++){
            if(asteroids[i]>0) s.push(i);
            else{
                while(!s.empty() && asteroids[s.top()]<abs(asteroids[i])) s.pop();
                if(s.empty()) result.push_back(asteroids[i]);
                if(!s.empty() && asteroids[s.top()]==abs(asteroids[i])) s.pop();
            }
        }
        vector<int> temp;
        while(!s.empty()){
            temp.push_back(asteroids[s.top()]);
            s.pop();
        }
        for(int i=temp.size()-1;i>=0;i--){
            result.push_back(temp[i]);
        }
        return result;
    }
};