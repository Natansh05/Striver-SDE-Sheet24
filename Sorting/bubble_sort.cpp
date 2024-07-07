// Description of Bubble Sort :
// 1. Compare the adjacent elements
// 2. Swap the elements if they are not in the correct order
// 3. Repeat the above steps for the remaining array

// Time Complexity: O(n^2)
// Space Complexity: O(1)

#include<vector>
#include<iostream>

using namespace std;


void bubble_sort(vector<int> &v){
    int n = v.size();
    int didswap = 0;
    for(int i=0;i<n-1;++i){
        didswap = 0;
        for(int j=0;j<n-i-1;++j){
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
                didswap = 1;
            }
        }
        if(didswap == 0)
            break;
    }
}




int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    bubble_sort(v);
    for(int i=0;i<n;++i){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
