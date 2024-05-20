// link - https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/
// Time Complexity - O(N*KlogK)
// Space Complexity - O(K)

class node{
    public:
    int data;
    int row;
    int col;

    node(int d,int r, int c){
        this->data = d;
        this->row = r;
        this->col = c;
    }
};

class cmp{
    public:
    bool operator()(node *a , node *b){
        return a->data > b->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        ios_base::sync_with_stdio(0);
        int k = nums.size();
        int mini = INT_MAX,maxi = INT_MIN;
        priority_queue<node*,vector<node*>,cmp> pq;
        for(int i=0;i<k;++i){
            int val = nums[i][0];
            maxi = max(maxi,nums[i][0]);
            pq.push(new node(val,i,0));
        }
        mini = pq.top()->data;
        int start = mini, end = maxi;
        int diff = end - start;
        while(pq.empty()==0){
            node* temp = pq.top();
            pq.pop();

            if(temp->col + 1< nums[temp->row].size()){
                pq.push(new node(nums[temp->row][temp->col + 1], temp->row , temp->col +1 ));
                maxi = max(maxi,nums[temp->row][temp->col + 1]);   
                mini = pq.top()->data;     
            }
            else{
                break;
            }

            if(maxi-mini < end - start){
                end = maxi;
                start = mini;
            }



        }
        return {start,end};
    }
};
