// link - geeksforgeeks.org/problems/nearly-sorted-1587115620/1
// Time Complexity - O(nlogK)
// Space Complexity - O(1)

class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    priority_queue<int,vector<int>,greater<int> > minh;
	    for(int i=0;i<n;++i){
	        minh.push(arr[i]);
	        if(minh.size()>k)
	            minh.pop();
	    }
	    
	    vector<int> ans(k,0);
	    for(int i=k-1;i>=0;--i){
	        ans[i] = minh.top();
	        minh.pop();
	    }
	    return ans;
	}

};
