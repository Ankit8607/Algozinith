// Link: https://www.learning.algozenith.com/problems/Binary-Sum-532

/*

Description

Given two binary numbers as strings, return their binary sum as a string.


Input Format

Two lines contain a binary string, |S| ≤ 10^6.


Output Format

Print the binary sum of two binary strings.


Sample Input 1

111
1

Sample Output 1

1000

*/


#include <bits/stdc++.h>
using namespace std;

int main(){
    string a,b; cin>>a>>b;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    string ans="";
    int carry=0;
    for(int i=0;i<max(a.size(),b.size());i++){
        if(i<a.size()) carry+=a[i]-'0';
        if(i<b.size()) carry+=b[i]-'0';
        if(carry==1){
            ans+='1';
            carry=0;
        }
        else if(carry==2){
            ans+='0';
            carry=1;
        }
        else if(carry==3){
            ans+='1';
            carry=1;
        }
        else ans+='0';
    }
    if(carry==1)ans+='1';
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}
