// https://www.learning.algozenith.com/problems/Max-Score-Possible-545

/*

Description

Given an array of N integers. Suppose you chose two index i, j. Score(i,j) is min(A[i],A[j])*abs(i-j). Print the maximum possible score among all the pairs(i,j) (1 ≤ i, j ≤ N). For example, if A = [1,2,3,4,4,5], the maximum score is between the third and sixth index. Here score = min(3, 5) * 3 = 9 units.


Input Format

The first line contains an integer T, the number of test cases. (1 ≤ T ≤ 10000)

The first line of each test case contains an integer N, 1≤N≤10^5.

The next line contains N space-separated integers, 1 ≤ A[i] ≤ 10^6.

Sum of N across all test cases ≤ 10^6.


Output Format

For each test case print the max score possible in a new line.


Sample Input 1

2
4
531925 419013 483258 219954 
5
1 4 5 7 8

Sample Output 1

966516
12

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
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    int ans=0;
    int l=0,r=n-1;
    while(l<r){
        ans=max(ans,min(arr[l],arr[r])*(abs(l-r)));
        if(arr[l]<=arr[r])l++;
        else r--;
    }
    cout<<ans<<"\n";
}

signed main(){
    IOS
    int t=1; cin>>t; while(t--) 
	solve();
    return 0;
}
