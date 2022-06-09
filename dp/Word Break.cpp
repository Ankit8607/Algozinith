// https://www.learning.algozenith.com/problems/Word-Break-979

/*

Description

Given a string 
s
 and a dictionary of strings 
w
o
r
d
s
, output "Yes" if 
s
 can be segmented into a space-separated sequence of one or more dictionary 
w
o
r
d
s
, else output "No".

Note that the same word in the dictionary may be reused multiple times in the segmentation.


Input Format

First-line contains 
T
 - the number of test cases.
The first line of each test case contains 
n
 - the size of the dictionary 
w
o
r
d
s
.
The second line of each test case contains string 
s
.
The next 
n
 lines of each test case contain 
n
 words of the dictionary 
w
o
r
d
s
.


Output Format

For each test case, output "Yes" if 
s
 can be segmented into a space-separated sequence of one or more dictionary 
w
o
r
d
s
, else output "No".


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

1
≤
|
s
|
≤
300

1
≤
w
o
r
d
s
[
i
]
.
l
e
n
g
t
h
(
)
≤
20

Sum of 
|
s
|
 over all test cases is 
≤
 
3
×
10
4
.


Sample Input 1

3
6
ilikealgozenith
algozenith
love
like
i
you
algo
2
applepenapple
apple
pen
3
mississippi
miss
ippi
sis

Sample Output 1

Yes
Yes
No

Note

for test 1, ilikealgozenith -> i + like + algozenith .

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

map<string,bool>mp;
string s;
int dp[310][310];

int rec(int level,int last){
    if(level==s.size()-1){
        if(mp.find(s.substr(last))!=mp.end()) return 1;
        return 0;
    }

    if(dp[level][last]!=-1) return dp[level][last];

    int ans=0;
    if(rec(level+1,last)) return dp[level][last]=1;
    if(mp.find(s.substr(last,level+1-last))!=mp.end()){
        if(rec(level+1,level+1)) return dp[level][last]=1;
    }

    return dp[level][last]=ans;
}

void solve(){
    mp.clear();
    memset(dp,-1,sizeof(dp));
    int n; cin>>n>>s;
    for(int i=0;i<n;i++){
        string tmp; cin>>tmp;
        mp[tmp]=1;
    }
    if(rec(0,0)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

signed main(){
    IOS
    int t=1; cin>>t; while(t--) 
    solve();
    return 0;
}
