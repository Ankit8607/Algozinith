// https://www.learning.algozenith.com/problems/Snakes-and-Ladders-915

/*

Description

Abhishek loves Snakes and Ladders game, he can always roll the die to whatever number he want between 
1
 to 
6
. Help him to find the least number of dice rolls to reach the destination i.e the 
100
t
h
 cell from the 
1
s
t
 cell.

Rules :-

The game is played with a cubic die of 
6
 faces numbered 
1
 to 
6
.

Starting from square 
1
, land on square 
100
 with the exact roll of the die. If moving the number rolled would place the player beyond square 
100
, no move is made.

If a player lands at the base of a ladder, the player must climb the ladder. Ladders go up only.

If a player lands at the mouth of a snake, the player must go down the snake and come out through the tail. Snakes go down only.


Input Format

The first line contains the number of tests, 
t
.

For each test case:

The first line contains 
n
, the number of ladders.
Each of the next 
n
 lines contains two space-separated integers, the start, and end of a ladder.
The next line contains the integer 
m
, the number of snakes.
Each of the next 
m
 lines contains two space-separated integers, the start, and end of a snake.

Output Format

For each of the 
t
 test cases, print the least number of rolls to move from start to finish on a separate line. If there is no solution, print 
−
1
.


Constraints

1
≤
t
≤
10

1
≤
n
,
m
≤
15
The board is always 
10
×
10
 with squares numbered 
1
 to 
100
 .
Neither square 
1
 nor square 
100
 will be the starting point of a ladder or snake.
A square will have at most one endpoint from either a snake or a ladder.


Sample Input 1

2
3
32 62
42 68
12 98
7
95 13
97 25
93 37
79 27
75 19
49 47
67 17
4
8 52
6 80
26 42
2 72
9
51 19
39 11
37 29
81 3
59 5
79 23
53 7
43 33
77 21 

Sample Output 1

3
5

Note

For the first test:
The player can roll a 5 and a 6 to land at square 12. There is a ladder to square 98. A roll of 2 ends the traverse in 3 rolls.

For the second test:
The player first rolls 5 and climbs the ladder to square 80. 'Three' rolls of 6 get to square 98. A final roll of 2 lands on the target square in 5 total rolls.

*/


#include<bits/stdc++.h>
using namespace std;

int n, m;
queue<int> q;
int go_immediately_to[110], dist[110];
bool vis[110];
bool isValid(int node)
{
    if(node < 1 || node > 100 || vis[node])
        return false;
    else
        return true;
}
int BFS(int source)
{
    memset(vis, 0, sizeof(vis));
    while(!q.empty())
        q.pop();

    vis[source] = 1;
    q.push(source);
    dist[source] = 0;
    while(!q.empty())
    {
        int current_node = q.front();
        q.pop();
        for(int i = 1; i<=6; i++)
        {
            int next_node = go_immediately_to[current_node+i];
            if(isValid(next_node))
            {
                q.push(next_node);
                vis[next_node] = 1;
                dist[next_node] = dist[current_node]+1;
            }
        }
    }
    if(!vis[100])
        return -1;
    else
        return dist[100];
}
int main()
{
    int i, j, cs, t, u, v;
    cin >> t;
    for(cs = 1; cs<=t; cs++)
    {
        cin >> n;

        for(i = 1; i<=100; i++)
            go_immediately_to[i] = i;

        for(i = 1; i<=n; i++)
        {
            cin >> u >> v;
            go_immediately_to[u] = v;
        }

        cin >> m;

        for(i = 1; i<=m; i++)
        {
            cin >> u >> v;
            go_immediately_to[u] = v;
        }

        cout << BFS(1) << endl;
    }

}
