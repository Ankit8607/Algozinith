// https://www.mock.algozenith.com/test/MICROSOFT/live?attempt_id=1991


/*

Description

It is lunchtime in school. N students labelled from 1 to N are sitting in a row and having their lunch. Each student has a different item in his lunch box. In order to share food fast enough among each other, the ith student can exchange his food with (i / 2)th student.

In how many minimum exchanges can the Ath student exchange food with the Bth student? (In the process, other students are also allowed to exchange food).

Here ‘/’ denotes integer division.


Input Format

The first line of input contains T - the number of test cases.
Each of the next T lines contains three space-separated integers - N, A, and B.


Output Format

For each test case, print the anser on a new line.


Constraints

1 ≤ T ≤ 105
1 ≤ N ≤ 106
1 ≤ A, B ≤ N


Sample Input 1

1
3 2 3

Sample Output 1

3

Note

Initial: 1,2,3 Required: 1,3,2

2 / 2=1, So 2 exchanges with 1 . Hence, we get 2,1,3 .
3 / 2=1, So 3 exchanges with 1 . Hence, we get 2,3,1 .
2 / 2=1, So 2 exchanges with 1 . Hence, we get 1,3,2 .

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
