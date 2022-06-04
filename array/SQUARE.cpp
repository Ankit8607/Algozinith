// Description

Given the x and y coordinates of 4 points on a 2D plane, determine whether it forms a valid square.

A valid square has four equal sides with positive length and four equal angles (90-degree angles).


Input Format

There are 4 lines in the input each containing 2 integers x and y - the coordinates of the points.


Output Format

Print 1 if it is a valid square, else print 0.


Constraints

1 ≤ x,y ≤ 106


Sample Input 1

0 0
1 0
0 1
1 1

Sample Output 1

1

Note

The given points form a valid square of unit area.
  
*/
  
  
  
#include <bits/stdc++.h>
using namespace std;

long long dis(vector<vector<long long>> &v,int i,int j){
    return 1LL*(v[i][1]-v[j][1]) * (v[i][1]-v[j][1]) + 1LL*(v[i][0]-v[j][0]) * (v[i][0]-v[j][0]);
}

bool isValidSquare(vector<vector<long long>> &v)
{
    long long l1=dis(v,0,1),l2=dis(v,0,2),l3=dis(v,0,3);

    if(l1==0 || l2==0 || l3==0) return 0;

    if(l1==l2 and 2*l2==l3 and dis(v,1,2)==2*dis(v,1,3)) return 1;

    if(l2==l3 and 2*l3==l1 and dis(v,2,3)==2*dis(v,2,0)) return 1;

    if(l3==l1 and 2*l1==l2 and dis(v,3,0)==2*dis(v,3,1)) return 1;

    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<vector<long long>> v(4, vector<long long>(2));
    for (int i = 0; i < 4; i++)
        cin >> v[i][0] >> v[i][1];
    cout << isValidSquare(v) << '\n';
    return 0;
}
