// https://www.learning.algozenith.com/problems/Array-Queries-543

/*

Description

Given an array A of size N and Q queries of the following two types:

1 X Y: Update the array element at index X with Y.
2 K: Print the position of the first array element greater than or equal to K. If there is no such index, then print -1

Input Format

The first line contains two space-separated integers N, Q (1 ≤ N, Q ≤ 10^6).

The next line contains N space-separated integers, (1 ≤ A[i] ≤ 10^6).

The next Q lines contain either of the following queries:

1 X Y (1 ≤ X ≤ N, 1 ≤ Y ≤ 10^6)
2 K (1 ≤ k ≤ 10^6).
 


Output Format

For each query of type 2 print the answer.


Sample Input 1

5 5
1 2 3 4 5
2 4
2 6
1 3 6
2 6
2 8

Sample Output 1

4
-1
3
-1


*/



#include<bits/stdc++.h>
using namespace std;
#define int long long

int arr[1000100],t[4000400];

void build(int idx, int l,int r){
    if(l==r){
        t[idx]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*idx,l,mid);
    build(2*idx+1,mid+1,r);
    t[idx]=max(t[2*idx],t[2*idx+1]);
}

void update(int idx,int l,int r, int pos,int val){
    if(pos<l || pos>r) return;
    if(l==r){
        arr[l]=val;
        t[idx]=val;
        return;
    }
    int mid=(l+r)/2;
    update(2*idx, l, mid, pos ,val);
    update(2*idx+1, mid+1,r , pos ,val);
    t[idx]=max(t[2*idx],t[2*idx+1]);
}

int query(int idx, int l,int r,int k){
    if(l==r) return l;
    if(t[idx]>=k){
        int mid=(l+r)/2;
        if(t[2*idx]>=k) return query(2*idx,l,mid,k);
        else if(t[2*idx+1]>=k) return query(2*idx+1,mid+1,r,k);
        else return -2;
    }
    else return -2;
}

void solve(){
    int n,q; cin>>n>>q;
    for(int i=0;i<n;i++) cin>>arr[i];
    build(1,0,n-1);
    while(q--){
        int ch; cin>>ch;
        if(ch==1){
            int x,y; cin>>x>>y;
            update(1,0,n-1,x-1,y);
        }
        else{
            int k; cin>>k;
            cout<<query(1,0,n-1,k)+1<<endl;
        }
    }
}

signed main(){
    IOS
	solve();
    return 0;
}
