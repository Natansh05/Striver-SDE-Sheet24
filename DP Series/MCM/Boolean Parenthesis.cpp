// link - geeksforgeeks.org/problems/boolean-parenthesization5610/1
// Expected Time Complexity: O(n3)
// Expected Auxiliary Space: O(n2)

class Solution{
    int t[201][201][2];
    int solve(int i,int j,string &s,bool isTrue){
        // base case
        if(i>j)
            return 0;
        if(i==j){
            if(isTrue==1)
                return s[i]=='T';
            else
                return s[i]=='F';
        }
        if(t[i][j][isTrue]!=-1)
            return t[i][j][isTrue];
        
        // hypothesis & loop for k
        int ans = 0; // we will not declare it globally , kyuki hume individual left right k answers chaiye 
        // not total number of cases jo jo possible hai....
        
        for(int k = i+1;k<j;k+=2){
            
            if(t[i][k-1][1]==-1)
                t[i][k-1][1] = solve(i,k-1,s,1);
            int lt = t[i][k-1][1];
            
            if(t[i][k-1][0]==-1)
                t[i][k-1][0] = solve(i,k-1,s,0);
            int lf = t[i][k-1][0];
            
            
            if(t[k+1][j][1]==-1)
                t[k+1][j][1] = solve(k+1,j,s,1);
            int rt = t[k+1][j][1];
            
            if(t[k+1][j][0]==-1)
                t[k+1][j][0] = solve(k+1,j,s,0);
            int rf = t[k+1][j][0];
            
            
            
            if(s[k]=='|'){
                if(isTrue){
                    ans+= lt*rt + lt*rf + lf*rt;
                }
                else{
                    ans+=lf*rf;
                }
            }
            else if(s[k]=='&'){
                if(isTrue)
                    ans+=lt*rt;
                else
                    ans+= lf*rf + lf*rt + lt*rf;
            }
            else if(s[k]=='^'){
                if(isTrue)
                    ans+= lt*rf + rt*lf;
                else
                    ans+= lt*rt + lf*rf;
            }
            
        }
        return t[i][j][isTrue] = ans%1003;
        
    }
public:
    int countWays(int n, string s){
        memset(t,-1,sizeof(t));
        return solve(0,s.size()-1,s,1);
    }
};
