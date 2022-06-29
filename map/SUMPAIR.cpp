// https://www.learning.algozenith.com/problems/SUMPAIR-622

/*

Description

Given two integer arrays A and B, you have to implement a data structure that supports queries of two types:

Add a positive integer to an element of a given index in the array B.
Count the number of pairs (i, j) such that A[i] + B[j] equals a given value total

Input Format

Implement the FindPairswithSum class:

FindPairswithSum(vector<int> &A, vector<int> &B) : Initializes the FindPairswithSum object with two integer arrays A and B.
void add(int index, int val) : Adds val to B[index] (0-indexing).
int count(int total) : Returns the number of pairs (i, j) such that A[i] + B[j] == total.

Output Format

For every call to the count function the number of pairs are printed.


Constraints

1 ≤ A.length ≤ 1000

1 ≤ B.length ≤ 105

1 ≤ A[i],B[i] ≤ 105

0 ≤ index < B.length

1 ≤ val ≤ 105

1 ≤ total ≤ 2×109

At most 1000 calls are made to add and count each.


Sample Input 1

3 3 3
4 5 6
1 2 3
count 7
add 0 2
count 9

Sample Output 1

3
2

Note

A = {4, 5, 6}

B = {1, 2, 3}

The first query returns 3 as (0,2), (1,1) and (2,0) are the valid pairs with sum equal to 7.

After the second query the arrays are [4,5,6] and [3,2,3].

The third query returns 2 as (2,0) and (2,2) are the valid pairs with sum equal to 9.

*/


class FindPairswithSum
{
public:
    vector<int>a,b;
    unordered_map<int,int>mp;
    FindPairswithSum(vector<int> &A, vector<int> &B)
    {
        a=A; b=B;
        for(int i=0;i<b.size();i++) mp[B[i]]++;     
    }

    void add(int index, int val)
    {
        mp[b[index]]--;
        b[index]+=val;
        mp[b[index]]++;
    }

    int count(int total)
    {
        int ans=0;
        for(auto i:a) ans+=mp[total-i];
        return ans;
    }
};
