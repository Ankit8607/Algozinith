// https://www.learning.algozenith.com/problems/K-Lists-Range-953

/*

Description

You are given 
k
 lists containing integers. Each list is sorted in non-decreasing order. You need to find the smallest range that includes at least one number from each of the 
k
 lists.

Note:- We define the range 
[
a
,
b
]
 is smaller than range 
[
c
,
d
]
 if 
b
−
a
<
d
−
c
 or 
a
<
c
 if 
b
−
a
==
d
−
c
.


Input Format

The first line contains 
T
- the number of test cases.
The First line of each test case contains the integer 
k
 - number of lists.
The next 
k
 lines of each test case will contain information regarding the 
k
 lists, where for each line, the first integer 
n
 will denote the size of the list followed by 
n
 integers belonging to that list.


Output Format

For each test case, Output the smallest range that includes at least one number from each of the 
k
 lists on a newline.


Constraints

1
≤
T
≤
100
.
1
≤
k
≤
1000
.
1
≤
n
≤
50
.
−
10
5
≤
l
i
s
t
[
i
]
[
j
]
≤
10
5
.

In each list, all integers are unique and are in non-decreasing order.


Sample Input 1

4
3
5 -2 7 9 12 15
5 0 8 10 14 20
6 -1 6 12 16 30 50
3
2 4 7
2 1 2
2 20 40
3
5 4 10 15 24 26
4 0 9 12 20
4 5 18 22 30
3
3 1 2 3
3 1 2 3
3 1 2 3

Sample Output 1

-2 0
2 20
20 24
1 1

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

void solve(){
	int n; cin>>n;
	vector<ii>arr;
	for(int i=0;i<n;i++){
		int k; cin>>k;
		for(int j=0;j<k;j++){
			int a; cin>>a;
			arr.push_back({a,i});
		}
	}
	sort(all(arr));
	int cnt=0;
	int l=0,r=0;
	int lans=0,rans=1e9;
	int present[n]={0};
	int size=arr.size();
	while(r<size){
		while(r<size and cnt<n){
			if(present[arr[r].S]==0) cnt++;
			present[arr[r].S]++;
			r++;
		}
		
		while(l<r and cnt==n){
			if(arr[r-1].F-arr[l].F<rans-lans){
				lans=arr[l].F;
				rans=arr[r-1].F;
			}
			present[arr[l].S]--;
			if(present[arr[l].S] == 0) cnt--;
			l++;
		}
	}
	cout<<lans<<" "<<rans<<endl;
}

signed main(){
	IOS
	int t=1; cin>>t; while(t--) 
	solve();
	return 0;
}
