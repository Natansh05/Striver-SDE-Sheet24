// link - geeksforgeeks.org/problems/merge-k-sorted-arrays/1
// Time Complexity - O(k^2log(k))
// Space Complexity - O(K^2)

typedef pair<int, pair<int,int>> pi;
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k){
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        vector<int> ans;
        for(int i=0;i<k;++i){
            pq.push({arr[i][0],{i,0}});
        }
        while(!pq.empty()){
            pi top = pq.top();
            pq.pop();
            int i = top.second.first;
            int j = top.second.second;
            ans.push_back(top.first);
            j+=1
            if(j<k)
                pq.push({arr[i][j],{i,j}});
        }
        return ans;
    }
};
