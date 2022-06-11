// https://www.learning.algozenith.com/problems/KWALK-583

/*

Description

You are given an N×N chessboard and a knight with starting position (Sx, Sy). You are given a final position (Fx, Fy). You have to find the minimum number of moves required to reach the final position.

Complete the function

int KnightWalk(int N, int Sx, int Sy, int Fx, int Fy)

Input Format

The first line contains a single integer T - the number of test cases.
The first line of each test case contains five integers N Sx Sy Fx Fy - the size of the board, initial position and final position.


Output Format

For every test case print the minimum number of moves required. If it is not possible print -1.


Constraints

1 ≤ T ≤ 20
1 ≤ N ≤ 1000
1 ≤ Sx, Sy, Fx, Fy ≤ N


Sample Input 1

3
6 4 5 1 1
6 3 3 6 6
6 6 1 1 6


Sample Output 1

3
2
4


Note

The situation described in test case 1 is:


The minimum number of moves is 3.

*/


#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ii pair<int,int>

bool isvalid(int x,int y,int n,vector<vector<int>>&arr){
    if(x>0 and x<=n and y>0 and y<=n and arr[x][y]==0) return 1;
    return 0;
}

int KnightWalk(int n, int sx, int sy, int fx, int fy)
{
	vector<vector<int>>arr(n+1,vector<int>(n+1,0));
    arr[sx][sy]=1;
    queue<ii>q;
    int dx[]={1,1,-1,-1,2,2,-2,-2};
    int dy[]={2,-2,2,-2,1,-1,1,-1};
    q.push({sx,sy});
    while(!q.empty()){
        int x=q.front().F,y=q.front().S;
        q.pop();
        for(int i=0;i<8;i++){
            if(isvalid(x+dx[i],y+dy[i],n,arr)) arr[x+dx[i]][y+dy[i]]=1+arr[x][y],q.push({x+dx[i],y+dy[i]});
        }
        if(arr[fx][fy]) break;
    }
    return arr[fx][fy]-1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	cin >> test_case;

	while (test_case--)
	{
		int N, Sx, Sy, Fx, Fy;
		cin >> N >> Sx >> Sy >> Fx >> Fy;

		cout << KnightWalk(N, Sx, Sy, Fx, Fy) << "\n";
	}
}
