// https://www.learning.algozenith.com/problems/GRAPHADJ-582

/*

Description

Given a directed graph, you have to find its transitive closure, i.e, the reachability of any vertex from any other vertex.


Input Format

The first line of each test case contains N - the number of vertices in the graph.
N lines follow containing N integers, where the jth integer of the ith line is 1 if there is a directed edge from vertex i to vertex j, otherwise it is 0.


Output Format

For each test case print N lines with N integers each, where the jth integer of the ith line is 1 if there is a path from vertex i to vertex j, otherwise it is 0.


Constraints

1 ≤ N ≤ 100


Sample Input 1

3
0 1 1
0 0 0
1 0 0


Sample Output 1

1 1 1
0 1 0
1 1 1


Sample Input 2

6
0 0 0 0 1 1
0 0 0 1 0 1
1 1 0 0 0 0
0 0 0 0 0 0
0 0 0 1 0 0
1 0 1 0 1 0


Sample Output 2

1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
0 0 0 1 0 0
0 0 0 1 1 0
1 1 1 1 1 1


Note

The graph for test case 1:


The graph for test case 2:



*/


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> TransitiveClosureGraph(vector<vector<int>> adj)
{
	int n=adj.size();
    for(int i=0; i<n; i++) adj[i][i]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                adj[j][k]|=(adj[j][i]&adj[i][k]);
            }
        }
    }
    return adj;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> adj(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> adj[i][j];
			if (i == j)
			{
				adj[i][j] = 1;
			}
		}
	}

	vector<vector<int>> T = TransitiveClosureGraph(adj);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << T[i][j] << ' ';
		}
		cout << '\n';
	}
}
