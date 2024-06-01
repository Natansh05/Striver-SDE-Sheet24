// link - https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
// Time Complexity - O(N^3)
// Space Complexity - O(N^2)

int solve(int i, int j,int arr[])
    {
        if(i>=j)return 0;

        int ans=INT_MAX;
        for(int k=i;k<=j-1;k++)
        {
            int tempAns = solve(i,k,arr) + solve(k+1,j,arr)
                          + arr[i-1]*arr[k]*arr[j];
            
            ans=min(ans,tempAns);                        
        }
        return ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        return solve(1,N-1,arr);
    }
