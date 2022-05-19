// https://www.learning.algozenith.com/problems/Tower-of-Hanoi-562

/*

Description

The tower of Hanoi is a famous puzzle where we have three rods and N disks. The objective of the puzzle is to move the entire stack to another rod. You are given the number of discs N. Initially, these discs are in the rod 1. You need to print all the steps of discs movement so that all the discs reach the 3rd rod. Also, you need to find the total moves.
Note: The discs are arranged such that the top disc is numbered 1 and the bottom-most disc is numbered N. Also, all the discs have different sizes and a bigger disc cannot be put on the top of a smaller disc. Refer the provided link to get a better clarity about the puzzle.


Input Format

The first line contains an integer T, the number of test cases (1 ≤ T ≤ 10).

The first line of each test case contains an integer N, (1 ≤ N ≤ 16).


Output Format

For each test case print the steps.


Sample Input 1

2
2
3
 


Sample Output 1

Move disk 1 from rod A to rod B
Move disk 2 from rod A to rod C
Move disk 1 from rod B to rod C
3
Move disk 1 from rod A to rod C
Move disk 2 from rod A to rod B
Move disk 1 from rod C to rod B
Move disk 3 from rod A to rod C
Move disk 1 from rod B to rod A
Move disk 2 from rod B to rod C
Move disk 1 from rod A to rod C
7

*/


#include <bits/stdc++.h>
using namespace std;
void towerOfHanoi(int n, char from_rod,
                   char to_rod, char aux_rod)
{
   if (n == 1)
   {
       cout << "Move disk 1 from rod " << from_rod <<
                           " to rod " << to_rod<<"\n";
       return;
   }
   towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
   cout << "Move disk " << n << " from rod " << from_rod <<
                               " to rod " << to_rod << "\n";
   towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}
signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   int testcases;
   cin>>testcases;
   while(testcases--){
       int n;
       cin>>n;
       towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
       cout<<(1<<n)-1<<"\n";
   }
}
