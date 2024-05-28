// link - https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1
// Time Complexity - O(N*Sum)
// Space Complexity - O(N*Sum)

class Solution {
    long long M = 1e9 + 7;
    int solve(vector<int> ans,long long target){
        int n = ans.size();
        int t[n+1][target+1];
        
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
            for(int j=0;j<=target;++j){
                // YAHA PE LOOP KE ANDAR J=0 TABHI INCLUDE KARNA PADEGA JAB ELEMENT ME KOI NEGATIVE YA ZERO KA ELEMENT HO
                // ELSE TARGET = 0 KA ALWAYS EK EMPTY SUBARRAY HI ANS HONA CHAIIYE 
                // INCASE 0 OR NEGATIVE ELEMENT EXISTS , THERE MAYBE BE MULTIPLE KIND OF SUBSETS WITH SUM 0
                if(ans[i-1]<=j){
                    t[i][j] = (t[i-1][j-ans[i-1]] + t[i-1][j]) % M;
                }
                else
                    t[i][j] = t[i-1][j] % M;
            }
        }
        
        return t[n][target];
    }
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        int sum = 0;
        for(int i=0;i<n;++i)
            sum+=arr[i];
        if((d+sum)&1)
            return 0;
        else if(sum < d)
            return 0;
        return solve(arr,(d+sum)>>1);
        
    }
};
