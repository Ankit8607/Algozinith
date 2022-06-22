// https://www.mock.algozenith.com/test/MICROSOFT/live?attempt_id=1991&xcord=0&ycord=2

/*

Description

John is playing on a flight of stairs, and he has invented a game. He is currently at stair number P and wants to go to stair number F, and he can do so by using only two operations, either jump up U stairs or go down D stairs at a time. He can neither go beyond the topmost stair and nor can he go below the lowermost stair i.e. he will only play on the stairs. He defines these up and down goings as an operation.

You are given the number of stairs on the staircase as N along with the values of F, P, U, and D as input, you have to find the minimum number of operations he has to perform to reach the final stair F.

If John cannot reach the stair anyway, return -1.


Input Format

The only line of input contains five space-separated integers - N, P, F, U and D.


Output Format

1 ≤ N, U, D ≤ 105
1 ≤ P, F ≤ 105


Sample Input 1

8 1 6 2 1

Sample Output 1

4

Note

As he has to go to stair number 6 and there are a total of 8 stairs. One of the possible paths with the minimum number of operations is that he can first jump two stairs to go to stair number 3 then to 5 in the second jump, then he goes one stair down to number 4, and finally, in the last step, he goes to stair number 6 totalling to 4 operations.

*/


#include<bits/stdc++.h>
using namespace std;

#define ll long long

class node
{
public:
    ll val;
    ll level;

};

ll min_operations(ll N,ll p,ll f,ll u,ll d)
{
    // to keep track of visited array
    bool visited[N + 1];
    memset(visited, false, sizeof(visited));

    // for bfs
    queue<node> q;


    node n ;

    // at start position = p and level=0;
    n.val = p;
    n.level = 0;

    visited[p] = true;

    q.push(n);

    //Do BFS starting from p
    while(!q.empty())
    {
        // Remove an item from queue
        node t = q.front();
        q.pop();


        // Check if this is target or not
        if(t.val == f)
        {
            return t.level;
        }

        // if only one step is required
        // up
        if(t.val + u <=N && t.val + u == f)
        {
            return t.level + 1;
        }

        // Down
        if(t.val - d >=1 && t.val - d == f)
        {
            return t.level + 1;
        }

        // Insert children if already not visited
        // Up
        if(t.val + u <=N && !visited[t.val + u])
        {
            n.val = t.val + u;
            n.level = t.level + 1;
            q.push(n);
            visited[t.val + u] = true;
        }

        //Down
        if(t.val - d >=1 && !visited[t.val - d])
        {
            n.val = t.val - d;
            n.level = t.level + 1;
            q.push(n);
            visited[t.val - d] = true;
        }
    }

    // Answer not possible
    return -1;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // taking input
    int N,p,f,u,d;
    cin>> N >> p >> f >> u >> d;

    ll ans = min_operations(N,p,f,u,d);

    cout<<ans<<"\n";
}
