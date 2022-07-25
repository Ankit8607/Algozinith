// https://www.learning.algozenith.com/problems/Shortest-Range-in-a-BST-1048

/*

Description

Given a BST (Binary Search Tree), find the shortest range 
[
x
,
y
]
, such that, at least one node of every level of the BST lies in the range.
If there are multiple ranges with the same gap (i.e. 
(
y
−
x
)
) return the range with the smallest 
x
.
We define the range 
[
a
,
b
]
 is smaller than range 
[
c
,
d
]
 if 
b
−
a
<
d
−
c
 or 
a
<
c
 if 
b
−
a
==
d
−
c
.


Input Format

You don't need to read input or print anything. Complete the function pair<int,int> shortestRangeBST(TreeNode *root) which takes the root of the binary search tree as an input parameter and returns the pair having the shortest range.

For local testing of the sample, the first line contains 
T
, the number of test cases. The first line of each test case contains 
n
- number of nodes. The second line of each test case contains the level order traversal of the tree, where '
x
' denotes the 'nullptr'.


Output Format

Returns the pair having the shortest range, such that, at least one node of every level of the BST lies in the range.
If there are multiple ranges with the same gap (i.e. 
(
y
−
x
)
) return the range with the smallest 
x
.


Constraints

1
≤
T
≤
10
4
 - the number of test cases.
1
≤
n
≤
10
5
 - number of nodes in binary search tree.
−
10
6
≤
v
a
l
u
e
≤
10
6
 - value of nodes in binary search tree.

All node values are unique.
Sum of 
n
 over all test cases is 
≤
10
6
.

Sample Input 1

2
11
8,3,10,2,6,x,14,x,x,4,7,12,x,x,x,x,x,11,13,x,x,x,x
5
12,x,13,x,14,x,15,x,16,x,x

Sample Output 1

6 11
12 16

Note

For test case 1

            8
          /   \
         3     10
       /  \      \
      2   |6|     14
          / \     /
         4   7   12
                /  \
             |11|   13
Level order traversal of the tree is 
[
8
]
,
[
3
,
10
]
,
[
2
,
6
,
14
]
,
[
4
,
7
,
12
]
,
[
11
,
13
]
.
The shortest range which satisfies the above-mentioned condition is 
[
6
,
11
]
.

*/


struct TreeNode {
    int data;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int x) {
        this->data = x;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Solution {
public:
    pair<int, int> shortestRangeBST(TreeNode *root) {
        unordered_map<int, vector<int>> nums;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            auto x = q.front(); q.pop();
            nums[x.second].push_back(x.first->data);
            if (x.first->left)q.push({x.first->left, x.second + 1});
            if (x.first->right)q.push({x.first->right, x.second + 1});
        }
        int k = nums.size(), ans = 1e9;
        pair<int, int> range = { -1e9, 1e9};
        vector<int> ptr(k, 1);
        multiset<array<int, 2>> s;
        for (int i = 0; i < k; i++)s.insert({nums[i][0], i});
        while (1) {
            auto x = *s.begin(), y = *s.rbegin();
            if (ans > y[0] - x[0])ans = y[0] - x[0], range = {x[0], y[0]};
            else if (ans == y[0] - x[0])range = min(range, {x[0], y[0]});
            if (ptr[x[1]] == nums[x[1]].size())break;
            s.erase(s.find(x));
            s.insert({nums[x[1]][ptr[x[1]]], x[1]});
            ptr[x[1]]++;
        }
        return {range.first, range.second};
    }

};
