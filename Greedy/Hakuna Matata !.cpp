// https://www.learning.algozenith.com/problems/Hakuna-Matata-!-718

/*

Description

Pumbaa stores some secret information about a farm with n∗m apples represent a rectangle. Each apple has its own number. The order of apples on the farm is changing. That's why Pumbaa receives the following instructions:

The instruction to swap two rows of the farm;
The instruction to swap two columns of the farm;
The instruction to obtain the number of the apple that exists in some cell.
As poor Pumbaa is not clever, he asked clever Timon to execute these instructions.


Input Format

The first line contains three space-separated integers n, m, and k - the number of farm rows and columns and the number of instructions, correspondingly.

Next n lines contain m space-separated numbers each — the initial state of the farm. Each number p in the table is an integer and satisfies the inequality.

Next k lines contain instructions in the format "si xi yi ", where si is one of the characters "с", "r" or "g", and xi, yi are two integers.

-If si = "c", then the current instruction is to swap columns with indexes xi and yi 

-If si = "r", then the current instruction is to swap rows with indexes xi and yi

-If si = "g", then the current instruction is to obtain the number located in the xth row and in the yth column.

The farm rows are considered to be indexed from top to bottom from 1 to n, and the farm columns — from left to right from 1 to m.


Output Format

For each instruction to obtain a number (si="g") print the required number. Print the answers to the instructions in the order of the instruction in the input.


Constraints

1 ≤ n , m ≤ 1000
1 ≤ k ≤106
0 ≤ p ≤ 99
1 ≤ x , y ≤ m, n 

Sample Input 1

3 3 5
1 2 3
4 5 6
7 8 9
g 3 2
r 3 2
c 2 3
g 2 2
g 3 2

Sample Output 1

8
9
6

Sample Input 2

2 3 3
1 2 4
3 1 5
c 2 1
r 1 2
g 1 3

Sample Output 2

5

Note

Let's see how the farm changes in the second test case.

After the first instruction is fulfilled, the table looks like that:

2 1 4

1 3 5

After the second instruction is fulfilled, the table looks like that:

1 3 5

2 1 4

So the answer to the third instruction (the number located in the first row and in the third column) will be 5.

*/



#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    int n,m,k;
    cin>>n>>m>>k;
    int arr[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    int rows[n],cols[m];
    for(int i=0; i<n; i++) rows[i] =i;

    for(int i=0;i<m;i++) cols[i] =i;
    while(k--){
        char c; cin>>c;
        int a,b; cin>>a>>b;
        a--; b--; 
        if(c=='c') swap(cols[a],cols[b]);
        else if(c=='r') swap(rows[a],rows[b]);
        else cout<<arr[rows[a]][cols[b]]<<endl;
    }
    return 0;
}
