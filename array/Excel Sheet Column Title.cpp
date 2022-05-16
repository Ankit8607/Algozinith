// https://www.learning.algozenith.com/problems/Excel-Sheet-Column-Title-560

/*

Description

Given a positive integer A, find its corresponding column title as appear in an Excel sheet.

1 → A
2 → B
.
.
26 → Z
28 → AB

Input Format

The first line contains an integer T, the number of test cases (1 ≤ T ≤ 100000).

The first line of each test case contains an integer N, (1 ≤ N ≤ 10^18)


Output Format

For each test case print the column title in a new line.


Sample Input 1

4
3
71
45
1501

Sample Output 1

C
BS
AS
BES

Note

TEST CASE 1:  3

A → 1 ; B  → 2 ; C  → 3……

 

TEST CASE 2:  71

A→1 ; B→2 ……. AA→27 ; AB→28….. BA→53 ; BB→54 ….. BR→70 ; BS→71

 

TEST CASE 3:  45

 A→1 ; B→2 ……. AA→27 ; AB→28….. AR→44 ; AS→45
 

TEST CASE 4:  1501

 A→1 ; B→2 …..AA→27 ; AB→28…… AAA→703 ; AAB→704…… BAA→1379 ;…. BES→1501


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

int power(int a, int b){
    int ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;     
}

void solve(){
    int n; cin>>n;
	string ans="";
	while(n){
		int t=(n-1)%26;
		ans+=t+'A';
		n=(n-1)/26;
	}
	reverse(all(ans));
	cout<<ans<<endl;
}

signed main(){
    IOS
    int t=1; cin>>t; while(t--) 
	solve();
    return 0;
}
