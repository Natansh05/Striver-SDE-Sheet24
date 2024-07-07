#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums,int s,int e){
    int mid = s+ (e-s)/2;
    int len1 = mid-s+1;

    int k = s;
    int i = s,j=mid+1;
    vector<int> temp = nums;
    while(i<=mid && j<=e){
        if(temp[i] <= temp[j]){
            nums[k] = temp[i];
            ++i;
        }
        else{
            nums[k]  = temp[j];
            ++j;
        }
        ++k;
    }

    while(k<=e && j<=e){
        nums[k] = temp[j];
        ++k;
        ++j;
    }

    while(k<=e && i<=mid){
        nums[k] = temp[i];
        ++i;
        ++k;
    }

    return;
}


void merge_sort(vector<int> &nums,int s,int e){
    if(s>=e)
        return;
    int mid = s + (e-s)/2;
    merge_sort(nums,s,mid);
    merge_sort(nums,mid+1,e);
    merge(nums,s,e);
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    // T.C - O(NlogN)
    // S.C - O(N)
    merge_sort(v,0,n-1);
    for(int i=0;i<n;++i){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
