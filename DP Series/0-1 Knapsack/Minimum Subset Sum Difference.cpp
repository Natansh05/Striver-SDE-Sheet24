// link - https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1
// Time Complexity - O(N*sum/2)
// Space Complexity - O(N*Sum/2)

class Solution{
    int solve(int ans[],int n,int target){
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
        int maxi = 0;
        // now we will return maximum value of s1 for which diff will be minimum 
        
        for(int i=0;i<=target;++i){
            if(t[n][i])
                maxi = i;
        }
        
        return maxi;
    }
    
  public:
	int minDifference(int arr[], int n)  { 
	    int sum = 0;
	    for(int i=0;i<n;++i)
	        sum+=arr[i];
	   // we are interested in finding s1 such that s2 = sum - s1 , so for returning only absolute vale
	   // we can answer only on the basis of s1 and left will be sum - 2*s1;
	    int ans = solve(arr,n,sum/2);
	    return sum-2*ans;
	} 
};
