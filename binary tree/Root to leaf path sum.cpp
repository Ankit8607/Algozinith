// https://www.learning.algozenith.com/problems/Root-to-leaf-path-sum-651

/*

Description

Given a binary tree and a number S, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals the given number. Return false if no such path can be found. 


Input Format

The first line contains an integer T, (1 ≤ T ≤ 10^5), the number of test cases.

The first line of each test case contains an integer N, S  the length of the array representing the serialized representation of a tree, the number.

The next line contains N-space-separated integers. 

The input is given as a serialized representation of a tree.

The following function parses the input:

Node* getBinaryTree(vector<int> &num, int*ind)

Sum of N across all test cases ≤ 10^7.


Output Format

Return true/false.


Sample Input 1

4
5 10
1 9 -1 -1 -1 
5 61
8 -1 10 -1 -1 
3 2
2 -1 -1 
13 13
3 5 3 8 9 -1 -1 -1 -1 -1 1 -1 -1 

Sample Output 1

yes
no
yes
no

*/


struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};
bool hasPathSum(Node* root, int sum)
{
    if(root==NULL) return 0;
    if(sum==root->val and root->left==NULL and root->right==NULL) return 1;
    return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
}
