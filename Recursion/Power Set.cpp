// link - https://www.geeksforgeeks.org/problems/power-set4302/1
// Time Complexity - O(2^N)
// Space Complexity - O(2^N)

class Solution{
    void solve(string ip,string op,int size,vector<string> &ans){
        if(ip==""){
            if(op!="")
                ans.push_back(op);
            return;
        }
        string temp = ip.substr(1,size-1+1);
        solve(temp,op + ip[0] , size - 1, ans);
        solve(temp,op,size-1,ans);
    }
	public:
		vector<string> AllPossibleStrings(string s){
		    vector<string> ans;
		    solve(s,"",s.size(),ans);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};
