// link - https://www.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1
// Time Complexity - O(N^2logK)
// Space Complexity - O(K)

class Solution{
public:
    int kthLargest(vector<int> &nums,int n,int k){
        int sum=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;++i){
            sum=0;
            for(int j=i;j<n;++j){
                sum=sum+nums[j];
                if(pq.size()<k)
                    pq.push(sum);
                else{
                    if(sum>pq.top()){
                        pq.pop();
                        pq.push(sum);
                    }
                }
            }
        }
        return pq.top();
    }
};
