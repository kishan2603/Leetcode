class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> v;
        string str; 
        for(int i=0;i<m;i++){
            str = "";
            if(i==0){
                for(int j=0;j<n;j++) str+=".";
            }
            else{
                for(int j=0;j<n;j++){
                    if(j==n-1) str+=".";
                    else str+="#";
                }
            }
            v.push_back(str);
        }
        return v;
    }
};