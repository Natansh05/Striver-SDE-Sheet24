// link - https://www.geeksforgeeks.org/problems/smallest-number-on-left3403/1
// Time Complexity - O(N)
// Space Complexity - O(1)


class Solution{
    vector<int> nsl(int nums[],int n){
        vector<int> ans(n,0);
        stack<int> st;
        for(int i=0;i<n;++i){
            while(1){
                if(st.empty()){
                    ans[i]= -1;
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
    vector<int> leftSmaller(int n, int a[]){
        return nsl(a,n);
    }
};
