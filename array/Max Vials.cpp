// https://www.learning.algozenith.com/problems/Max-Vials-585

/*

Description

You are assigned the task of filling a delivery truck with boxes of vaccines. You are given the description of N boxes -  the number of each type of box and the vials of vaccine it contains. Find the maximum number of vials you can load onto the truck given that each box takes unit space and the truck has a maximum capacity of M.

Complete the function

int MaxVials(vector<pair<int,int>> &a, int m)

Input Format

The first line contains two integers N and M - the number of boxes and the truck’s capacity.
The ith of the next N lines contains two integers xi and yi - the number of boxes of type i and the number of vials that type of box contains.


Output Format

Print the maximum number of vials that can be loaded onto the truck.


Constraints

1 ≤ N, M ≤ 106

1≤ xi, yi ≤ 1000


Sample Input 1

3 4
1 3
2 2
3 1

Sample Output 1

8

Sample Input 2

4 10
5 10
2 5
4 7
3 9

Sample Output 2

91

Note

There are:
- 1 box of the first type that contains 3 vials each.
- 2 boxes of the second type that contain 2 vials each.
- 3 boxes of the third type that contain 1 vial each.
You can take all the boxes of the first and second types, and one box of the third type.
The total number of vials will be = (1 * 3) + (2 * 2) + (1 * 1) = 8.

*/


#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
bool comp(ii &a,ii &b){
    if(a.second==b.second) return a.first>b.first; 
    return a.second>b.second;
}

int MaxVials(vector<pair<int,int>> &a, int m)
{
    sort(a.begin(), a.end(),comp);
    int ans=0;
    for(int i=0;i<a.size() and m>0;i++){
        ans+=a[i].second*min(m,a[i].first);
        m-=a[i].first;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> a(n);
    
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    
    cout << MaxVials(a, m) << '\n';
    return 0;
}
