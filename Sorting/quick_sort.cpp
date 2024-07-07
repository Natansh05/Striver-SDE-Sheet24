#include<bits/stdc++.h>
using namespace std;


// link - https://leetcode.com/discuss/general-discussion/1083445/How-quick-sort-works-and-the-problems-that-can-be-solved-using-partition-logic.

int partition(vector<int> &nums,int low,int high){
    // int k = high;
    // int pivot = nums[low];
    // for(int i = high;i>low;--i){
    //     if(nums[i] > pivot){
    //         swap(nums[i],nums[k]);
    //         --k;
    //     }
    // }
    // swap(nums[low],nums[k]);
    // return k;
    int i = low,j = high;
    int pivot = nums[low];
    while(i<j){
        cout<<"loop working"<<endl;
        while(nums[i] <= pivot && i<=high-1)
            ++i;
        while(nums[j] >= pivot && j>=low + 1)
            --j;
        if(i<j)
            swap(nums[i],nums[j]);
    }
    swap(nums[low],nums[j]);
    return j;
}

void quick_sort(vector<int> &nums,int low,int high){
    if(low>=high)  
        return;
    int ind = partition(nums,low,high);
    quick_sort(nums,low,ind-1);
    quick_sort(nums,ind+1,high);
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    // T.C - O(NlogN)
    // S.C - O(1)
    quick_sort(v,0,n-1);
    for(int i=0;i<n;++i){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
