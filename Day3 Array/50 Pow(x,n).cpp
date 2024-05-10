// link - https://leetcode.com/problems/powx-n/description/
// Time Complexity - O(logN)
// Space Complexity - O(logN) ----> Recursive stack space

class Solution {
public:
    double myPow(double x, long long int n) {
      // here in the question , n was passed as int n
      //  But we took the argument in long long int to avoid -2147483648 getting in for abs(n)
        if(x==1)
            return 1;
        if(n==0)
            return 1;
        if(n<0)
            return 1/myPow(x,abs(n));
        double y = myPow(x,n/2);
        if(n%2){
            return x * y * y;
        }
        else{  
            return y*y;
        }
        
    }
};


// This thing can be done without converting int n to long long int n , by using static_cast<type2>(expression)
// Static cast is performed and checked at compile time , so no run time errors are created, it is typically safer than (type2)(expression) i.e. C- style type conversion
class Solution {
public:
    double myPow(double x, long int n) {
        if(x==1)
            return 1;
        if(n==0)
            return 1;
        if(n<0){
            unsigned int num = static_cast<unsigned int>(abs(n));
            return 1/myPow(x,num);
        }
        double y = myPow(x,n/2);
        if(n%2){
            return x * y * y;
        }
        else{  
            return y*y;
        }
        
    }
};



