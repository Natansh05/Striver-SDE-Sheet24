// link - https://www.geeksforgeeks.org/problems/get-minimum-element-from-stack/1
// Time Complexity - O(1)
// Space Complexity - O(1)

class Solution{
    int minEle;
    stack<int> s;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           if(s.empty()){
               return -1;
           }
           return minEle;
       }
       
       /*returns poped element from stack*/
       int pop(){
           //Write your code here
           int temp;
           if(s.empty()){
               return -1;
           }else{
               if(s.top() >= minEle){
                   int temp = s.top();
                   s.pop();
                   return temp;
               }else if(s.top() < minEle){
                   temp = minEle;
                   minEle = 2*minEle - s.top();
                   s.pop();
                   return temp;
               }
           }
       }
       
       /*push element x into the stack*/
       void push(int x){
           if(s.empty() == true){
               s.push(x);
               minEle = x;
           }else{
               if(x >= minEle){
                   s.push(x);
               }else if(x < minEle){
                   s.push(2*x - minEle);
                   minEle = x;
               }
           }
       }
};
