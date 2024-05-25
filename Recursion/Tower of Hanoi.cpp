// link - https://www.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1
// Time Complexity - O(2^N)
// Space Complexity - O(1)

long long toh(int n, int s, int d, int h) {
        if(n==0)
            return 0 ;
        toh(n-1,s,h,d);
        ++ans;
        cout<<"move disk "<<n<<" from rod "<<s<<" to rod "<<d<<endl;
        toh(n-1,h,d,s);
        return ans;
    }
