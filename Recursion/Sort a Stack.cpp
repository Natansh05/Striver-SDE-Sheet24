// link - https://www.geeksforgeeks.org/problems/sort-a-stack/1
// Time Complexity - O(N*N)
// Space Complexity - O(N) recursion stack space


void insert(stack<int> &s,int top){
    if(s.empty() || top > s.top()){
        s.push(top);
        return;
    }
    else{
        int el = s.top();
        s.pop();
        insert(s,top);
        s.push(el);
    }
}


void SortedStack :: sort(){
    if(s.size()==0 || s.size()==1)
        return;
    int top = s.top();
    s.pop();
    sort();
    insert(s,top);
    return;
}
