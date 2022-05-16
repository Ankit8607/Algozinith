// https://www.learning.algozenith.com/problems/Decode-Alphabet-534

/*

Description

A string of uppercase alphabets can be encoded to a string of digits, by replacing each alphabet with their 1-based index. For example, "BC" can be coded to "23" and "CZ" can be coded to "326". Given a string of digits, encoded, output an array containing all the possible strings of alphabets that can be decoded from it.


Input Format

The first line contains an integer T, the number of test cases. (1 ≤ T ≤ 10)

The first line of each test case contains a string consisting of digits 1,2….9. |S| ≤ 30


Output Format

Print all the possible strings.


Sample Input 1

2
121212
987

Sample Output 1

ABABAB
ABABL
ABAUB
ABLAB
ABLL
AUBAB
AUBL
AUUB
LABAB
LABL
LAUB
LLAB
LLL
IHG

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

vector<string>ans;
string s,tmp=""; 

void rec(int level){
	if(level==s.size()){
		ans.push_back(tmp);
		return;
	}

	if(s[level]=='0') return;
	tmp+=s[level]-'1'+'A';
	rec(level+1);
	tmp.pop_back();
	if(level+1<s.size()){
		int t=s[level+1]-'0'+10*(s[level]-'0');
		if(t<=26){
			tmp+=t+'A'-1;
			rec(level+2);
			tmp.pop_back();
		}
	}
}

void solve(){
    cin>>s;
	tmp="";
	ans.clear();
	rec(0);
	for(auto i: ans) cout<<i<<"\n";
}

signed main(){
    IOS
    int t=1; cin>>t; while(t--) 
	solve();
    return 0;
}
