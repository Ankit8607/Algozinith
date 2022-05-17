// https://www.learning.algozenith.com/problems/Repeating-Character-538

/*

Description

Given a string S, you are allowed to swap any two characters from S, such that the length of the longest substring with repeated characters is maximum. The string consists of lowercase characters only.


Input Format

The first line contains an integer T, the number of test cases. (1 ≤ T ≤ 10000)

The first line of each test case contains a String S, 1 ≤ |S| ≤ 10^5.

 


Output Format

For each test case print the answer in a new line.


Sample Input 1

2
dfgsdefv
ababababba

Sample Output 1

2
4

Note

Test case 1 - 
You can swap characters ‘f’ and ‘d’ to convert the string to "ddgsfefv", so the maximum substring with the same character is “dd”.

Test case 2 - 

You can swap characters ‘a’ and ‘b' to convert the string to “abaaabbbba”, so the maximum substring with the same character is “bbbb”.

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
    int n=s.length();
    int fr[26]={0},ans=1;
    for(int i=0;i<n;i++) fr[s[i]-'a']++;
    int left[n],right[n];
    left[0]=1;
    for(int i=1;i<n;i++){
        left[i]=1;
        if(s[i]==s[i-1]) left[i]+=left[i-1],ans=max(ans,left[i]);
    }
    right[n-1]=1;
    for(int i=n-2;i>=0;i--) {
        right[i]=1;
        if(s[i]==s[i+1])
        right[i]+=right[i+1];
    }
    
    for(int i=1;i<n-1;i++){
        if(fr[s[i-1]-'a']>left[i-1]) ans=max(ans,left[i-1]+1);

        if(fr[s[i+1]-'a']>right[i+1]) ans=max(ans,right[i+1]+1);

        if(s[i-1]==s[i+1]){
            if(fr[s[i-1]-'a']>left[i-1]+right[i+1]) ans=max(ans,left[i-1]+right[i+1]+1);
            else ans=max(ans,left[i-1]+right[i+1]);
        }
    }
    cout<<ans<<endl;
}

signed main(){
    IOS
    int t=1; cin>>t; while(t--) 
	solve();
    return 0;
}
