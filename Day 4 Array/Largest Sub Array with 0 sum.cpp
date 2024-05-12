// link - https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
// Time Complexity - O(NlogN)
// Space Comlexity - O(N)

class Solution{
    public:
    int maxLen(vector<int>&A, int n){   
        
        if(n==1)
            return A[0]==0;
            
        
        int ans = 0;
        int temp1 = 0;
        // to handle the edge case of total prefix to be zero  
        
        
        map<int,int> mp;
        // ordered map to logN insertion and search
        
        int prefix = A[0];
        mp[A[0]] = 0;
        
        for(int i=1;i<n;++i){
            prefix+=A[i];
        if(prefix==0)
            temp1=(i+1);
            
        auto it = mp.find(prefix);
        
        if(it!=mp.end())
            ans = max(ans,i - it->second);
        else
            mp[prefix] = i;
        
        }
        return max(ans,temp1);
    }
};




// } Driver Code Ends
