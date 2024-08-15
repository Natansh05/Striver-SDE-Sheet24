// Description of Insertion Sort :
// 1. Insert the element at the correct position in the sorted array
// 2. Repeat the above steps for the remaining array

// Time Complexity: O(n^2)
// Space Complexity: O(1)

#include<vector>
#include<iostream>

using namespace std;

void insertion_sort(vector<int> &v){
    int n = v.size();
    for(int i=1;i<n;++i){
        int didswap = 0;
        int j = i;
        while(j>0 && v[j]<v[j-1]){
            swap(v[j],v[j-1]);
            didswap = 1;
            --j;
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
    insertion_sort(v);
    for(int i=0;i<n;++i){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
