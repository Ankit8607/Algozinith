// https://www.learning.algozenith.com/problems/Generate-Balanced-Parenthesis---easy-version-464

/*

Description

You have given a positive even integer n. Your task is to print all balanced parenthesis of length n in lexicographic order (https://en.wikipedia.org/wiki/Lexicographic_order). 

Balanced parentheses mean that each opening symbol has a corresponding closing symbol and the pairs of parentheses are properly nested.


Input Format

The only line of input contains a number n.


Output Format

Print all balanced parenthesis of length n in lexicographic order.


Constraints

2 ≤ n ≤ 24
It is guaranteed that n is even.


Sample Input 1

2

Sample Output 1

()

Sample Input 2

4

Sample Output 2

(())
()()

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

void rec(int level,int dep,int &n,string &s){
    if(level==n){
        if(dep==0) cout<<s<<endl;
        return;
    }

    s+='(';
    rec(level+1,dep+1,n,s);
    s.pop_back();
    if(dep){
        s+=')';
        rec(level+1,dep-1,n,s);
        s.pop_back();
    }
}

void solve(){
    int n; cin>>n;
    string s;
    rec(0,0,n,s);
}

signed main(){
    IOS
    // int t=1; cin>>t; while(t--) 
    solve();
    return 0;
}
