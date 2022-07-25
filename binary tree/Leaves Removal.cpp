// https://www.learning.algozenith.com/problems/Leaves-Removal-1034

/*

Description

You are given a binary tree with 
n
 nodes. Each node has an integer value associated with it. Your task is to print the leaf nodes and then remove these leaf nodes. Now, return the new leaf nodes and repeat the process until the tree becomes empty.

Note:
You don’t require to remove the leaf nodes. Just print the values in the required order.
The leaf nodes must be stored in a left to right order.

Input Format

Complete the function vector<vector<int>> findLeaves(TreeNode* root) that takes root of the binary tree as input.

For local testing of the sample, the first line contains 
T
, the number of test cases. The first line of each test case contains the level order traversal of the tree, where '
x
' denotes the 'nullptr'.


Output Format

Return the nodes as a vector<vector<int>> where each series of removal will be stored in vector<int>.
The leaf nodes must be stored in a left to right order for each series of removal.


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
 - number of nodes in binary tree.
1
≤
v
a
l
u
e
≤
10
5
 - value of nodes in binary tree.
Sum of 
n
 over all test cases is 
≤
10
6
.


Sample Input 1

2
1,2,3,4,5,x,x,x,x,x,x
1,2,3,4,x,x,x,x,x

Sample Output 1

4 5 3 
2 
1 

4 3 
2 
1 

Note

for test case 1,

    1
   / \
  2   3
 / \     
4   5   
Output

[[4,5,3],[2].[1]]
for test case 2,

    1
   / \
  2   3
 /
4 
Output

[[4,3],[2],[1]]

*/


class Solution {
public:
    vector<vector<int>>ans;
    int fun(TreeNode * root) {
        if(root==NULL) return -1;
        int dep=1+max(fun(root->right),fun(root->left));
        // int dep=fun(root->left);
        // dep=max(dep,fun(root->right));
        // dep++;
        if(ans.size()<=dep) ans.resize(dep+1);
        ans[dep].push_back(root->data);
        return dep;
    }
	vector<vector<int>> findLeaves(TreeNode * root) {
        if(root==NULL) return {{}};
        fun(root);
		return ans;
	}

};
