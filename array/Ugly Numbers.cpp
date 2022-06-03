// https://www.learning.algozenith.com/problems/Ugly-Numbers-574

/*

Description

Numbers that have only 2, 3, and 5 as their prime factors are known as Ugly Numbers.
For example,

6 = 2*3 is an ugly number.
14 = 2*7 is not an ugly number as it also has 7 in its prime factorization.
You are given t test cases. In each case, you are given a single integer n and you need to print the nth ugly number.


Input Format

The first line contains a single integer t denoting the number of test cases. Then t lines follow. The ith line contains the value of n for the ith query.


Output Format

Print the nth ugly number for each test case.


Constraints

1 <= t <= 10000
1 <= n <= 1500

Sample Input 1

3
2
7
10

Sample Output 1

2
8
12

Note

The first 10 ugly numbers are [1, 2, 3, 4, 5, 6, 8, 9, 10, 12]

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

vector<int>v(1501);

void fun(){
    v[1]=1;
    int a,b,c;
    a=b=c=1;
    for(int i=2;i<=1500;i++){
        v[i]=min({v[a]*2,v[b]*3,v[c]*5});
        if(v[i]==v[a]*2) a++;
        if(v[i]==v[b]*3) b++;
        if(v[i]==v[c]*5) c++;
    }
}

void solve(){
    int n; cin>>n;
    cout<<v[n]<<endl;
}

signed main(){
    IOS
    fun();
    int t=1; cin>>t; while(t--)
    solve();
    return 0;
}
