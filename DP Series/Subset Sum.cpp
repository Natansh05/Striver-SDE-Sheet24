// link - https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
// Time Complexity - O(N*Sum)
// Space Complexity - O(N*Sum)


class Solution{ 
    // solution by tabulation
    bool solve(vector<int> &ans,int target){
        int n = ans.size();
        bool t[n+1][target+1];
        
        // initialization
        for(int i=0;i<=n;++i){
            for(int j=0;j<=target;++j){
                if(i==0)
                    t[i][j] = 0;
                if(j==0)
                    t[i][j] = 1;
            }
        }
        
        
        // bottom up approach
        for(int i=1;i<=n;++i){
            for(int j=1;j<=target;++j){
                if(ans[i-1]<=j){
                    t[i][j] = t[i-1][j-ans[i-1]] + t[i-1][j];
                }
                else
                    t[i][j] = t[i-1][j];
            }
        }
        
        return t[n][target];
    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        bool ans = solve(arr,sum);   
        return ans;
    }
};
