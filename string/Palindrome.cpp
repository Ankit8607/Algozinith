// https://www.learning.algozenith.com/problems/Palindrome-552

/*

Description

Given a string s, determine if it can be made a palindrome by deleting at most one of its characters. (If s[i] is deleted, the resulting string is the concatenation of s[0 : i - 1] and s[i + 1 : n - 1], where n is the size of s). If yes, print ‘Y’ else print ‘N’.


Input Format

The first line contains an integer T, the number of test cases. (1 ≤ T ≤ 10000)

The first line of each test case contains a string S, 1 ≤ |S| ≤ 10^5.

Sum of |S| across all test cases ≤ 10^6.


Output Format

Print ‘Y/’N' for each test case in a new line.


Sample Input 1

2
abcfdcba
nitix

Sample Output 1

Y
N

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
    string s; cin>>s;
    int n=s.size();
    int l=0,r=n-1;
    int cnt=0;
    while(l<r){
        if(s[l]==s[r]){ l++; r--;}
        else{
            cnt++;
            if(cnt>1) break;
            l++;
        }
    }
    if(cnt<=1){
        cout<<"Y"<<endl;
        return;
    }
    cnt=0;
    l=0; r=n-1;
    while(l<r){
        if(s[l]==s[r])
            l++, r--;
        else{
            cnt++;
            if(cnt>1) break;
            r--;
        }
    }
    if(cnt<=1) cout<<"Y"<<endl;
    else cout<<"N"<<endl;
}

signed main(){
    IOS
    int t=1; cin>>t; while(t--) 
	solve();
    return 0;
}
