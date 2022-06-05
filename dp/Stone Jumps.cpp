// https://www.learning.algozenith.com/problems/Stone-Jumps-594

/*

Description

There are n stones. Initially, you are at stone 1 and you want to reach stone n. You can jump from one stone to another. The maximum length of the jump that you can make from each stone is given in input as an array of n integers.
For example, if the maximum length of jump you can make from stone 1 is 2, you can jump to stone 2 and stone 3 from stone 1. You cannot jump to stone 4 from stone 1 because the length of this jump will be 3 which is greater than the maximum jump allowed from stone 1.
You need to determine if you will be able to reach the last stone n by any set of valid jumps.


Input Format

The first line contains a single integer n.
The second line contains n space-separated integers denoting the length of the maximum jump allowed for each stone.


Output Format

Print ‘Yes’ if you can reach the last stone and ‘No’ otherwise.


Constraints

1 <= n <= 100000
0 <= jump[i] <= 100000

Sample Input 1

6
2 1 3 1 1 1

Sample Output 1

Yes

Sample Input 2

6
3 1 1 0 1 1

Sample Output 2

No

Note

Jump from stone 1 to stone 3 and then to stone 6.
No matter what jumps you make, you will get stuck at stone 4 and never reach stone 6.

*/


// DP Approach

#include <bits/stdc++.h>
using namespace std;

bool isReach(vector<int> jump)
{
	int n=jump.size();
    vector<int> maxReach(n);
    for(int i=0; i<n; i++){
        maxReach[i]=i+jump[i];
        if(i>0){
            maxReach[i]=max(maxReach[i], maxReach[i-1]);
        }
    }

    int i=0;
    while(i<n){
        int reach=maxReach[i];
        if(reach==n-1){
            return true;
        }else if(reach==i){
            return false;
        }
        i=reach;
    }
    return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	vector<int> jump(n);
	for (auto &i : jump)
		cin >> i;

	if (isReach(jump))
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}


// Smart ways

#include <bits/stdc++.h>
using namespace std;

bool isReach(vector<int> jump)
{
	int n=jump.size();
    int last=0;
    for(int i=0; i<n-1; i++){
        last=max(last,i+jump[i]);
        if(last==i) return 0;
    }
    return 1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	vector<int> jump(n);
	for (auto &i : jump)
		cin >> i;

	if (isReach(jump))
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}
