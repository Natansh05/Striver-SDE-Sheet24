class Solution{
    public:
    //Complete this function
    void printNos(int N){
        if(N==0)
            return;
        printNos(N-1);
        cout<<N<<" ";
        return;
    }
};

// Print N to 1
class Solution{
    public:
    //Complete this function
    void printNos(int N){
        if(N==0)
            return;;
        cout<<N<<" ";
        printNos(N-1);
        return;
    }
};
