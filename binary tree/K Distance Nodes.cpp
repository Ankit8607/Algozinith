// https://www.learning.algozenith.com/problems/K-Distance-Nodes-1015

/*

Description

Given a binary tree, a target node with value 
t
a
r
 present in the binary tree, and an integer value 
k
, find all the nodes that are at distance 
k
 from the given 
t
a
r
 node.

Note-:
No parent pointers are available.
All Node values are unique.
t
a
r
 value node always exists in the given tree.
return the vector< int > in sorted order by node value.
If no such nodes are found, then return empty vector { }.
Try to solve this problem in 
O
(
N
∗
l
o
g
N
)
 time and 
O
(
H
)
 space, where 
H
 is the height of the binary tree.
Don't forget to clear any global variable in the template code, as input contains multiple test cases.

Input Format

Complete the function

 vector< int > KDistanceNodes(TreeNode* root, int k, int tar)

, that takes 
r
o
o
t
 pointer of the binary tree, 
k
 and 
t
a
r
 as input parameters and return the vector < int > having nodes that are at 
k
 distance from the 
t
a
r
 node in the sorted order by node values.

For local testing of the sample, the first line contains 
T
, the number of test cases. The first line of each test case contains 
n
- number of nodes, 
k
 and 
t
a
r
 . The second line of each test case contains the level order traversal of the tree, where '
x
' denotes the 'nullptr'.


Constraints

1
≤
n
≤
10
4
 - number of nodes.
0
≤
k
≤
20

1
≤
 Node Value 
≤
10
4

1
≤
t
a
r
≤
10
4

All Node values are unique.
t
a
r
 value node always exists in the given tree.
Don't forget to clear any global variable in the template code, as input contains multiple test cases.
Sum of 
n
 across all test cases is 
≤
10
5
.

Sample Input 1

1
10 2 5
1,5,3,2,4,10,6,7,x,9,8,x,x,x,x,x,x,x,x,x,x

Sample Output 1

3 7 8 9 

Note

For the given Binary Tree , 
n
=
10
 , 
k
=
2
 , and 
t
a
r
=
5

Output will be 
[
3
,
7
,
8
,
9
]
.

*/



vector<int> ans;
int dfs(Node *v, int &tar, int k, int d) {
    if (v == nullptr || d > k)return 0; // pruning
    if (d == k) {
        ans.push_back(v->data);
        return 0;
    }
    if (v->data == tar) { // target node found.
        dfs(v->left, tar, k, 1); // search for kth distance node in target subtree.
        dfs(v->right, tar, k, 1);
        return 1;
    }
    int left, right;
    if (d == 0) { // searching for target node.
        left = dfs(v->left, tar, k, d);
        right = dfs(v->right, tar, k, d);
    }
    else { // searching for kth distance nodes.
        left = dfs(v->left, tar, k, d + 1);
        right = dfs(v->right, tar, k, d + 1);
    }
    if (left == k || right == k) {
        ans.push_back(v->data);
        return 0;
    }
    if (left > 0) {
        dfs(v->right, tar, k, left + 1);
        return left + 1;
    }
    if (right > 0) {
        dfs(v->left, tar, k, right + 1);
        return right + 1;
    }
    return 0;
}
