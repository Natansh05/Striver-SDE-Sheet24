// link - https://leetcode.com/problems/k-th-symbol-in-grammar/description/
// Time Complexity - O(N)
// Space Complexity - O(N) Recursion stack space

class Solution {
    int solve(int n,int k,bool ev){
        if(n==1)
            return 0;
        if(k&1)
            ev = 0;
        else
            ev = 1;
        cout<<ev<<endl;
        int ans = solve(n-1,(k+1)/2,ev);
        return ans^ev;
    }
public:
    int kthGrammar(int n, int k) {
        return solve(n,k,!(k&1));
    }
};


// Second observation
class Solution {
    int solve(int n,int k){
        if(n==1)
            return 0;

        int mid = pow(2,n-1)/2;
        if(k>mid)
            return 1 ^ solve(n-1,k-mid);
        else 
            return solve(n-1,k);
    }
public:
    int kthGrammar(int n, int k) {
        return solve(n,k);
    }
};
