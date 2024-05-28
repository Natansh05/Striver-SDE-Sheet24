// link - geeksforgeeks.org/problems/rod-cutting0840/1
// Time Complexity - O(N*N)
// Space Complexity - O(N*N)

class Solution{
    // Standard Unbounded Knapsack Code
    int solve(int price[],int n){
        int t[n+1][n+1];
        
        for(int i=0;i<=n;++i){
            for(int j=0;j<=n;++j){
                if(i==0 || j==0)
                    t[i][j] = 0;
            }
        }
        
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(i<=j)
                    t[i][j] = max(price[i-1] + t[i][j-i] , t[i-1][j]);
                else
                    t[i][j] = t[i-1][j];
            }
        }
        return t[n][n];
    }
  public:
    int cutRod(int price[], int n) {
        return solve(price,n);
    }
};
