// LINK - https://leetcode.com/problems/word-break/
// Time Complexity - O(N^3)
// Space Complexity - O(N^2)

class Solution {
    int t[302][302];
    int ans = 0;
    bool solve(int i,int j,string s,set<string> &st){
        if(i>j)
            return 1;
        if(t[i][j]!=-1)
            return t[i][j];
        for(int k=i;k<=j;++k){
            string temp = s.substr(i,k-i+1);
            if(st.find(temp)!=st.end()){
                cout<<temp<<endl;
                ans += solve(k+1,j,s,st);
            }
            else
                continue;
        }
        return t[i][j] = ans;
    }
public:
    bool wordBreak(string s, vector<string>& nums) {
        
        int n = s.size();
        memset(t,-1,sizeof(t));
        set<string> st(nums.begin(),nums.end());
        return solve(0,n-1,s,st);
    }
};
