// https://www.learning.algozenith.com/problems/Minimum-Length-String-551

/*

Description

Given a string s and another string t consisting of lowercase characters, print the minimum length substring in s that has all the characters from t (there can be more characters in the substring, but it must have each character from t)

If there are many such maximal substrings, return the left-most one.

It is guaranteed that the answer exists.


Input Format

The first line contains an integer T, the number of test cases. (1 ≤ T ≤ 10000)

The first line of each test case contains a string s, 1 ≤ |s| ≤ 10^5.

The second line of each test case contains a string t, 1 ≤ |t| ≤ 10^5.

Sum of |s| + |t| across all test cases ≤ 2*10^6.


Output Format

For each test case print the required answer in a new line.


Sample Input 1

2
algozenith
azit
nitish
nsh

Sample Output 1

algozenit
nitish

Sample Input 2

2
uksqqd
qqd
xczztaegzi
zztezi

Sample Output 2

qqd
zztaegzi

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
    string s,t; cin>>s>>t;
    int tcnt[26]={0};
    int cnt=0;
    for(auto i:t){
        tcnt[i-'a']++;
        if(tcnt[i-'a']==1) cnt++;
    }

    int scnt[26]={0};
    int j=0;
    int start=0,end=1e7;
    for(int i=0;i<s.size();i++){
        scnt[s[i]-'a']++;
        if(scnt[s[i]-'a']==tcnt[s[i]-'a']) cnt--;

        while(cnt==0){
            if(end-start>i-j){
                start=j;
                end=i;
            }
            scnt[s[j]-'a']--;
            if(scnt[s[j]-'a']<tcnt[s[j]-'a']) cnt++;
            j++;
        }
    }
    for(int i=start; i<=end; i++) cout<<s[i];
    cout<<endl;
}

signed main(){
    IOS
    int t=1; cin>>t; while(t--) 
	solve();
    return 0;
}
