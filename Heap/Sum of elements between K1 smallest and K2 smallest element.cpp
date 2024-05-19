// link - https://www.geeksforgeeks.org/problems/sum-of-elements-between-k1th-and-k2th-smallest-elements3133/1
// Time Complexity - O(NlogN)
// Space Complexity - O(K2)

class Solution{
    private:
    long long ksmallestElements(long long nums[],long long n,long long k){
        priority_queue<int> pq;
        bool flag = 0;
        for(int i=0;i<n;++i){
            pq.push(nums[i]);
            if(flag==0 && pq.size()>k)
                flag = 1;
            if(flag)
                pq.pop();
        }
        return pq.top();
    }
    public:
    long long sumBetweenTwoKth( long long A[], long long n, long long K1, long long K2){
        long long left = ksmallestElements(A,n,K1);
        long long right = ksmallestElements(A,n,K2);
        
        int sum = 0;
        for(int i=0;i<n;++i){
            if(A[i] > left && A[i] < right)
                sum+=A[i];
        }
        return sum;
    }
};
