// Description of approach
// 1. Find the minimum element in the array
// 2. Swap the minimum element with the first element
// 3. Repeat the above steps for the remaining array

// Time Complexity: O(n^2)
// Space Complexity: O(1)

#include<vector>
#include<iostream>

using namespace std;

void selection_sort(vector<int> &v){
    int mini = INT_MAX;
    int n = v.size();
    for(int i=0;i<n-1;++i){
        int ind = -1;
        mini = INT_MAX;
        for(int j=i;j<n;++j){
            if(v[j]<mini){
                ind = j;
                mini = v[j];
            }
        }
        swap(v[i],v[ind]);
    }
    return;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    selection_sort(v);
    for(int i=0;i<n;++i){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
