// https://www.learning.algozenith.com/problems/Skyline-954

/*

Description

A city’s skyline is made up from the outer contour of the city’s silhouette. This silhouette can be seen when a city is viewed from a distance.

 


Given the locations and heights of all the buildings, return the skyline formed by these buildings collectively.

The geometric information of each building is given in the array buildings where 
b
u
i
l
d
i
n
g
s
[
i
]
=
[
l
i
,
r
i
,
h
i
]
:

l
i
 is the x coordinate of the left edge of the 
i
t
h
 building.
r
i
 is the x coordinate of the right edge of the 
i
t
h
 building.
h
i
 is the height of the 
i
t
h
 building.
You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 
0
.

The skyline should be represented as a list of "key points" sorted by their x-coordinate in the form 
[
[
x
1
,
y
1
]
,
[
x
2
,
y
2
]
,
.
.
.
]
. Each key point is the left endpoint of some horizontal segment in the skyline except the last point in the list, which always has a y-coordinate 
0
 and is used to mark the skyline's termination where the rightmost building ends. Any ground between the leftmost and rightmost buildings should be part of the skyline's contour.

Note:
There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [..., [2 3] , [4 5] , [7 5] , [11 5] , [12 7] ,... ] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [..., [2 3] , [4 5] , [12 7] , ...].


Input Format

The first line contains 
T
- the number of test cases.
First line of each test case contains 
n
 - the number of buildings.
Next 
n
 lines of each test case will contains 
l
i
, 
r
i
, 
h
i
 of the 
b
u
i
l
d
i
n
g
i

Output Format

For each test case, output the 
[
x
i
,
y
i
]
 coordinates of the skyline formed by these buildings collectively with increasing 
x
i
 coordinate in a newline.
After each test case, output a newline.


Constraints

1
≤
T
≤
10

1
≤
n
≤
10
4

0
≤
l
i
<
r
i
≤
10
9

1
≤
h
i
≤
10
6
Buildings in the input are sorted by 
l
i
 in non-decreasing order for each test case.

Sample Input 1

3
5
2 9 10
3 7 15
6 12 12
13 16 10
15 17 5
2
0 2 3
2 5 3
5
4 9 10
4 9 15
4 9 12
10 12 10
10 12 8

Sample Output 1

2 10
3 15
7 12
12 0
13 10
16 5
17 0

0 3
5 0

4 15
9 0
10 10
12 0

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

bool comp(pair<ii,int> &a,pair<ii,int> &b){
    if(a.F==b.F) return a.S>b.S;
    return a.F.F<b.F.F;
}

void solve(){
    int n; cin>>n;
    vector<pair<ii,int>>arr(2*n);
    for(int i=0;i<2*n;i+=2){
        cin>>arr[i].F.F>>arr[i+1].F.F>>arr[i].S;
        arr[i].F.S=0; arr[i+1].F.S=1;
        arr[i+1].S=arr[i].S;
    }
    vector<ii>ans;
    multiset<int,greater<int>>heights;
    sort(arr.begin(),arr.end());
    ans.push_back({arr[0].F.F,arr[0].S});
    for(auto i: arr){
        if(i.F.S==0){
            heights.insert(i.S);
            int ht=*heights.begin();
            if(ans.back().S<ht){ 
                if(ans.back().F==i.F.F) ans.back().S=max(i.S,ans.back().S);
                else
                ans.push_back({i.F.F,ht});
            }
        }
        else{
            heights.erase(heights.find(i.S));
            if(heights.size()==0) ans.push_back({i.F.F,0});
            else{ 
                int ht=*heights.begin();
                if(ans.back().S!=ht) ans.push_back({i.F.F,ht});
            }
        }
    }
    for(auto i :ans) cout<<i.F<<" "<<i.S<<endl; cout<<endl;
}

signed main(){
    IOS
    int t=1; cin>>t; while(t--) 
    solve();
    return 0;
}
