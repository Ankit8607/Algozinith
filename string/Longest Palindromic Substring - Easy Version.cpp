// https://www.learning.algozenith.com/problems/Longest-Palindromic-Substring---Easy-Version-952

/*

Description

Given a string of length 
n
, your task is to determine the longest palindromic substring of the string. For example, the longest palindrome in "algoazzaa" is "azza".
If there are multiple longest palindromic substrings, Output the one which comes first in the string.


Input Format

The first line contains 
T
 - the number of test cases.
The first line of each test case contains a string of length 
n
. Each character is one of a–z.


Output Format

For each test case, Output the Longest Palindromic Substring.
If there are multiple longest palindromic substrings, Output the one which comes first in the string.


Constraints

1
≤
T
≤
1000

1
≤
n
≤
1000

Sum of 
n
 across all test cases is 
≤
 
10
4
.


Sample Input 1

9
algoazzaa
aaaaaaaaaa
ababababab
ihpohpzoffel
flexflexvpqxierullgcfckjqflexflex
obsession
abcxcbaxcba
zzabc
aaccaabbaaccaaccaabbaaccaa

Sample Output 1

azza
aaaaaaaaaa
ababababa
ff
cfc
ses
abcxcba
zz
aaccaabbaaccaaccaabbaaccaa

*/


#include<bits/stdc++.h>
using namespace std;
const int mod= 10000007;
#define endl "\n"
#define F first
#define S second
#define vi vector<int>
#define ii pair<int,int>
#define all(a) a.begin(),a.end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define tracearray(arr,n)  cout<<#arr<<endl;for(int i=0;i<n;i++)cout<<arr[i]<<" ";cout<<endl;

void solve(){
    string s; cin>>s;
    string t="@#";
    for(auto i:s) t+=i,t+='#';
    t+="$";
    int c=0,r=0,n=t.size();
    int p[n]={0};
    int ans=0;
    for(int i=1;i<n-1;i++){
        int mirr=2*c-i;

        if(i<r) p[i]=min(r-i,p[mirr]);

        while(t[i+1+p[i]]==t[i-p[i]-1]) p[i]++;

        if(i+p[i]>r){
            r=i+p[i];
            c=i;
        }
        ans=max(ans,p[i]);
    }
    int idx;
    for(int i=0;i<n;i++){
        if(p[i]==ans){
            string tmp="";
            int idx=i-p[i];
            while(ans>tmp.size()){
                if(t[idx]!='#') tmp+=t[idx];
                idx++;
            }
            cout<<tmp<<endl;
            return;
        }
    }
}

signed main(){
    IOS
    int t=1; cin>>t; while(t--) 
    solve();
    return 0;
}
