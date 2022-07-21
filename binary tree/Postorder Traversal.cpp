// https://www.learning.algozenith.com/problems/Postorder-Traversal-556

/*

Description

Given a binary tree, return the postorder traversal of its nodes’ values.

Complete the function:

vector<int> getPostorderTraversal(Node* root)


Input Format

The first line contains an integer T, (1 ≤ T ≤ 10^5), the number of test cases.

The first line of each test case contains an integer N,  the length of the array representing the serialized representation of a tree.

The next line contains N-space-separated integers. 

The input is given as a serialized representation of a tree.

The following function parses the input:

Node* getBinaryTree(vector<int> &num, int*ind)

Sum of N across all test cases ≤ 10^7.


Output Format

Return the postorder traversal of the tree.


Sample Input 1

3
3
6004 -1 -1 
7
5222 -1 3819 6801 -1 -1 -1 
9
8901 7891 5407 -1 -1 1720 -1 -1 -1 

Sample Output 1

6004 
6801 3819 5222 
5407 1720 7891 8901 

Note

Test case 2- 
 5222
    \
   3819
    /
  6801

Test case 3 - 
   8901
   /
  7891
   /   \
  5407 1720
  
  */


struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

void fun(Node *root,vector<int>&ans){
    if(root == NULL) return;
    fun(root->left,ans);
    fun(root->right,ans);
    ans.push_back(root->val);
}

vector<int> getPostorderTraversal(Node* root) {
    vector<int>ans;
    fun(root,ans);
    return ans;
}
