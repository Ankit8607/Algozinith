// https://www.learning.algozenith.com/problems/Josephus-Problem-564

/*

Description

There are n people standing in a circle waiting to be executed. The counting out begins at the person standing at the 1st position and proceeds around the circle in increasing order (after n we get 1). In each step, k-1 people are skipped and the kth person is executed. The elimination proceeds around the circle (which is becoming smaller and smaller as the executed people are removed), until only the last person remains, who is given freedom. Given the total number of person n and a number k which indicates that k-1 persons are skipped and kth person is killed in the circle. The task is to choose the place in the initial circle so that you are the last one remaining and so survive.


Input Format

The only line of input contains two integers n and k.


Output Format

Output a single integer x (1 <= x <= n) which is the position at which you can survive.


Constraints

1 <= n <= 105
1 <= k <= n


Sample Input 1

6 3

Sample Output 1

1

Note

Let's represent the circle as an array.

Starting point for the next turn is in bold.

[1, 2, 3, 4, 5, 6]

1) First 3 is eliminated. [1, 2, 4, 5, 6]

2) 6 is eliminated. [1, 2, 4, 5]

3) 4 is eliminated. [1, 2, 5]

4) 2 is eliminated. [1, 5]

5) 5 is eliminated so 

1 is the safe position.

*/


#include <bits/stdc++.h>
using namespace std;

int josephus(int n, int k) {
    if (n == 1)
        return 0;
    return ((josephus(n - 1, k) + k ) % n );
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    cout << josephus(n, k)+1;
}
