// Link: https://www.learning.algozenith.com/problems/Mobile-Phone-531


/*

Description

You will be given a string, number, of digits from 2 to 9, output an array containing all the strings of lower case alphabets that could be made using the string of digits on an alphanumeric keypad, like the one shown in the picture.

https://docs.google.com/document/d/1m22-fMZ7ABm4TICJAUa05_spB0f1hS1I3LmQq4WGBj0/edit

 

 


Input Format

The first line contains a string S consisting of digits 2-9, |S| ≤ 12.


Output Format

Output the possible combination of words possible. Print the answer in lexicographical order.


Sample Input 1

23

Sample Output 1

ad
ae
af
bd
be
bf
cd
ce
cf

Note

Characters present on the digit 2 are ‘a’,'b','c' and digit 3 are ‘d’,'e','f'. So using digit 2 you can get ‘a’,'b','c' and using digit 3 you can get ‘d’,'e','f'.

So the combination of words that are possible  - 

ad
ae
af
bd
be
bf
cd
ce
cf

*/


#include <bits/stdc++.h>
using namespace std;

string ch[8]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void rec(int level,const string &n,string s){
	if(level==n.size()){
		cout<<s<<endl;
		return;
	}
	for(auto x:ch[n[level]-'0'-2]){
		rec(level+1,n,s+string(1,x));
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string n; cin>>n;
	string s="";
	rec(0,n,s);
}
