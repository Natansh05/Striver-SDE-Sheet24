// link - https://www.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1
// Time Complexity - O(M*N)
// Space Complexity - O(M*N)

class Solution{
    private:
	int lcs(string str,string str2){
	    int n = str.size();
	    int m = str2.size();
	    
	    int t[n+1][m+1];
	    
	    for(int i=0;i<=n;++i){
	        for(int j=0;j<=m;++j){
	            if(i==0 || j==0)
	                t[i][j] = 0;
	            else if(str[i-1]==str2[j-1])
	                t[i][j] = 1 + t[i-1][j-1];
	            else 
	                t[i][j] = max(t[i-1][j] , t[i][j-1]);
	        }
	    }
	    
	    return t[n][m];
	}

	public:
	int minOperations(string str1, string str2) 
	{ 
	    int x = lcs(str1,str2);
	   // cout<<x<<endl;
	    return (str1.size() + str2.size() - 2*x);
	} 
};
