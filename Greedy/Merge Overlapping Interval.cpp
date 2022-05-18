// https://www.learning.algozenith.com/problems/Merge-Overlapping-Interval-541

/*

Description

Given a collection of intervals, merge all overlapping intervals. The start point and endpoint are inclusive as well.


Input Format

The first line contains an integer T, the number of test cases. (1 ≤ T ≤ 10000)

The first line of each test case contains an integer N, the number of overlapping intervals, 1≤N≤10^5.

The next N lines contain a, b denoting an interval [a,b], (1 ≤ a ≤ b ≤ 10^9).

The Sum of N overall test case does not exceed 10^6.
 


Output Format

For each test case print the merged interval in sorted order.


Sample Input 1

1
5
1 2
2 5
6 9
8 10
10 15

Sample Output 1

1 5
6 15

*/


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
int mod= 1000000007;
const int N=2000010;
#define endl "\n"
#define F first
#define S second
#define MP make_pair
#define ii pair<int,int>
#define all(a) a.begin(),a.end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define tracearray(arr,n)  cout<<#arr<<endl;for(int i=0;i<n;i++)cout<<arr[i]<<" ";cout<<endl;

int power(int a, int b,int m){
    int ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%m;
        }
        a=(a*a)%m;
        b>>=1;
    }
    return ans;     
}


void solve(){
    int n; cin>>n;
    vector<ii> ans;
    for(int i=0; i<n; i++){
        int a,b; cin>>a>>b;
        ans.push_back({a,b});
    }
    sort(all(ans));
    int l=-1,r=-1;
    for(int i=0; i<n; i++){
        if(l==-1){
            l=ans[i].F;
            r=ans[i].S;
        }
        if(r<ans[i].F){
            cout<<l<<" "<<r<<endl;
            l=ans[i].F;
            r=ans[i].S;
        }
        else{
            r=max(r,ans[i].S);
        }
        if(i==n-1){
            cout<<l<<" "<<r<<endl;
        }
    }
}

signed main(){
    IOS
    int t=1; cin>>t; while(t--) 
	solve();
    return 0;
}
