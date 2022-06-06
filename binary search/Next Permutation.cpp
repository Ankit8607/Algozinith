// https://www.learning.algozenith.com/problems/Next-Permutation-570

/*

Description

You are given an array of n integers. You need to print the lexicographically next greater permutation of the numbers. If no greater permutation exists, print the lexicographically smallest permutation of the numbers.

The rearrangement of the numbers must be in place with constant extra memory. 
Do not use built-in functions.


Input Format

The first line of input contains a single integer n.
The next line contains n integers representing the input array.


Output Format

Print a single line containing the output array.


Constraints

1 <= n <= 100000
1 <= v[i] <= 100000

Sample Input 1

3
3 1 2

Sample Output 1

3 2 1

Sample Input 2

4
4 3 2 1

Sample Output 2

1 2 3 4

Note

The next permutation after 3 1 2 is 3 2 1.
Since 4 3 2 1 is the lexicographically greatest permutation, we print the array in ascending order(lexicographically smallest).

*/


#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &v)
{
	int n=v.size();
    int flag=0;
    for(int i=n-2; i>=0; i--){
        if(v[i]<v[i+1]){
            int fit=lower_bound(v.begin()+i+1,v.end(),v[i],greater<int>())-v.begin();
            fit--;
            swap(v[fit],v[i]);
            reverse(v.begin()+i+1,v.end());
            flag=1;
            break;
        }
    }
    if(flag==0) reverse(v.begin(),v.end());
}

int main() {
	int n;
	cin >> n;
	vector <int> v(n);
	for (auto &i : v)
		cin >> i;

	solve(v);

	for (auto i : v)
		cout << i << " ";
	cout << "\n";
}
