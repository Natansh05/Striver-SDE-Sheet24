// link - https://leetcode.com/problems/merge-intervals/description/
// Time complexity - O(N)
// Space complexity - O(1)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        ans.push_back(arr[0]);
        int temp = arr[0][1];

        for(int j=1;j<n;++j){
            if(arr[j][0]<=temp){
                temp = max(temp,arr[j][1]);
                ans.back()[1] = temp;
            }
            else{
                ans.push_back(arr[j]);
                temp = arr[j][1];
            }
        }
        return ans;
    }
};
