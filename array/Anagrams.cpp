// https://www.learning.algozenith.com/problems/Anagrams-533

/*

Description

Given two strings S and T, check if string S is an anagram of string T. Strings contain lowercase characters only.

An anagram of a string is another string that contains the same characters, only the order of characters can be different.


Input Format

The first line contains an integer T', the number of test cases. (1 ≤ T' ≤ 100000)

The next two lines of each test case contain a string. 1 ≤ |S|,|T| ≤ 10^5.

Sum of |S|+|T| across all test cases ≤ 10^7.


Output Format

Print ‘Y’ if string S is an anagram of string T. Otherwise print ‘N’.


Sample Input 1

2
abcd
bcda
abcde
abcdf

Sample Output 1

Y
N

*/


#include <bits/stdc++.h>
using namespace std;

void solve(){
    string A,B; cin>>A>>B;
    	int a[26]={0},b[26]={0};
    	for(int i=0;i<A.size();i++){
            a[A[i]-'a']++;
            b[B[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(a[i]!=b[i]){
                cout<<"N"<<endl;
                return;
            }
        }
        cout<<"Y"<<endl;
}

int main(){
    int t; cin>>t;
    while(t--){
    	solve();
    }
    return 0;
}
