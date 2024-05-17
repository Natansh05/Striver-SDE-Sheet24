// link - geeksforgeeks.org/problems/help-classmates--141631/1
// Time Complexity - O(N)
// Space Complexity - O(1)


class Solution{
    private:
    vector<int> nsr(vector<int> nums,int n){
        vector<int> ans(n,0);
        stack<int> st;
        for(int i = n-1;i>=0;--i){
            while(1){
                if(st.empty()){
                    ans[i] = -1;
                    st.push(nums[i]);
                    break;
                }
                else if(st.top()<nums[i]){
                    ans[i] = st.top();
                    st.push(nums[i]);
                    break;
                }
                else{
                    st.pop();
                }
            }
        }
        return ans;
    }
    public:
    vector<int> help_classmate(vector<int> arr, int n) { 
        return ngl(arr,n);
    } 
};
