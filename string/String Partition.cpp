// https://www.learning.algozenith.com/problems/String-Partition-550

/*

Description

Given a string S of lowercase letters. Partition it into as many parts as possible such that each letter occurs only in one partition. Print the size of the partitions.


Input Format

The first line contains an integer T, the number of test cases. (1 ≤ T ≤ 10000)

The first line of each test case contains a string S, 1 ≤ |S| ≤ 10^5.

Sum of |S| across all test cases ≤ 10^6.


Output Format

For each test case print the size of the partitions.


Sample Input 1

5
abcadefe
fkdjbfgjkbdasnjkfg
algozenith
youareawesome
kdfgnksdjngkl

Sample Output 1

4 1 3 
18 
1 1 1 1 1 1 1 1 1 1 
1 12 
12 1 

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
    map<char,int>mp;
    for(auto i:s) mp[i]++;
    int cnt=0,sz=0;
    vector<int>present(26,0);
    for(int i=0;i<s.size();i++){
        sz++;
        if(present[s[i]-'a']==0)
            present[s[i]-'a']=1,
            cnt++;
        mp[s[i]]--;
        if(mp[s[i]]==0) cnt--;
        if(cnt==0){
            cout<<sz<<" ";
            sz=0;
        }
    }
    cout<<endl;
}

signed main(){
    IOS
    int t=1; cin>>t; while(t--) 
	solve();
    return 0;
}
