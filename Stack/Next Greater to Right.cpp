// link - https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1
// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> nums, int n){
        vector<long long> ans(n,0);
        stack<long long> st;
        for(int i=n-1;i>=0;--i){
            while(1){
                if(st.empty()){
                    ans[i]= -1;
                    st.push(nums[i]);
                    break;
                }
                else if(st.top()>nums[i]){
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
};
