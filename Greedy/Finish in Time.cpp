// https://www.learning.algozenith.com/problems/Finish-in-Time-589

/*

Description

You are given N assignments and each assignment has a specific start time and end time within which you have to finish the assignment. Find the maximum number of assignments that you can finish. If an assignment finishes at a time x, you cannot start another assignment at the same time x.


Input Format

The first line of each test case contains a single integer N - the number of assignments.
N lines follow each containing a pair of integers s and t - the start and end time of each assignment.


Output Format

Print the maximum number of assignments that you can finish.


Constraints

1 ≤ N ≤ 105

1 ≤ s ≤ t ≤ 108


Sample Input 1

6

1 2

3 4

0 6

5 7

8 9

5 9


Sample Output 1

4


Note

You can finish the assignments 1, 2, 4 and 5.

*/



#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
int mod= 998244353;
const int N=2000010;
#define endl "\n"
#define F first
#define S second
#define MP make_pair
#define ii pair<int,int>
#define all(a) a.begin(),a.end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define tracearray(arr,n)  cout<<#arr<<endl;for(int i=0;i<n;i++)cout<<arr[i]<<" ";cout<<endl;

bool comp(ii &a, ii &b){
    if(a.S==b.S) return a.F<b.F;
    return a.S<b.S;
}

void solve(){
    int n; cin>>n;
    vector<ii>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i].F>>arr[i].S;
    sort(arr.begin(),arr.end(),comp);
    int ans=0,last=-1;
    for(int i=0;i<n;i++){
        if(arr[i].F>last){
            ans++;
            last=arr[i].S;
        }
    }
    cout<<ans<<endl;
}

signed main(){
   IOS
   
//    int t;
//    cin>>t;
   
//    while(t--)
       solve();

   return 0;
}
