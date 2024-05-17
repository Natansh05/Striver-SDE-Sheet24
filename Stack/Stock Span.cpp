// link -  https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1
// Time Complexity - O(N)
// Space Complexity - O(1) ---considering ki jo answer return karna hai wo auxilliary space me nai ata

class Solution
{
    private:
    vector<int> ngl(int nums[], int n){
        vector<int> ans(n,0);
        stack<pair<int,int>> st;
        for(int i=0;i<n;++i){
            while(1){
                if(st.empty()){
                    ans[i]= -1;
                    st.push({nums[i],i});
                    break;
                }
                else if(st.top().first>nums[i]){
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
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n){
        vector<int> ans = ngl(price,n);
        for(int i=0;i<n;++i){
            ans[i] = i-ans[i];
        }
        return ans;
    }
};
