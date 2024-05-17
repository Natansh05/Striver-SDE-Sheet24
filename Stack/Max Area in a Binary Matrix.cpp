// link - https://leetcode.com/problems/maximal-rectangle/description/
// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution {
    private:
    vector<int> nsl(vector<int> nums,int n){
        vector<int> ans(n,0);
        stack<pair<int,int>> st;
        for(int i=0;i<n;++i){
            while(1){
                if(st.empty()){
                    ans[i]= -1;
                    st.push({nums[i],i});
                    break;
                }
                else if(st.top().first<nums[i]){
                    ans[i] = st.top().second;
                    st.push({nums[i],i});
                    break;
                }
                else{
                    st.pop();
                }
            }
        }
        return ans;
    }

    vector<int> nsr(vector<int> nums,int n){
        vector<int> ans(n,0);
        stack<pair<int,int>> st;
        for(int i = n-1;i>=0;--i){
            while(1){
                if(st.empty()){
                    ans[i] = n;
                    st.push({nums[i],i});
                    break;
                }
                else if(st.top().first<nums[i]){
                    ans[i] = st.top().second;
                    st.push({nums[i],i});
                    break;
                }
                else{
                    st.pop();
                }
            }
        }
        return ans;
    }

    int MAH(vector<int> &heights,int n){
        vector<int> right = nsr(heights,n);
        vector<int> left = nsl(heights,n);

        int ans = 0;
        int cal = 0;
        for(int i=0;i<n;++i){
            cal = heights[i] * (right[i]-left[i]-1);
            ans = max(cal,ans);
        }
        return ans;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        ios_base::sync_with_stdio(0);
        int n = matrix[0].size();
        int m = matrix.size();

        int ans = -1;
        int cnt = -1;

        vector<int> temp(n,0);
        for(int j=0;j<m;++j){
            for(int i=0;i<n;++i){
                if(matrix[j][i]=='1'){
                    temp[i]++;
                }
                else{
                    temp[i]=0;
                }
            }
            
            cnt = MAH(temp,n);
            ans = max(cnt,ans);

        }

        return ans;

    }
};
