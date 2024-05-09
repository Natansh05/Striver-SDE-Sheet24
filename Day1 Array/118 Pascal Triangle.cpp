// LINK - https://leetcode.com/problems/pascals-triangle/description/

// TIME COMPLEXITY - O((N-1)*(N-2)/2)
// SPACE COMPLEXITY - O(N)

class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        temp.push_back(1);
        ans.push_back(temp);
        if(n==1)
            return ans;

        temp.push_back(1);
        ans.push_back(temp);
        if(n==2)
            return ans;

        for(int i=2;i<n;++i){
            vector<int> temp2(i+1,1);
            for(int j = 1;j<i;++j){
                temp2[j] = ans[i-1][j] + ans[i-1][j-1];
            }
            ans.push_back(temp2);
        }

        return ans;

    }
};
