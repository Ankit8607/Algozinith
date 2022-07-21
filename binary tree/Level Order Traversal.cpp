// https://www.learning.algozenith.com/problems/Level-Order-Traversal-557

/*

Description

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Complete the function:

vector<vector<int>> getLevelorderTraversal(Node* root) 


Input Format

The first line contains an integer T, (1 ≤ T ≤ 10^5), the number of test cases.

The first line of each test case contains an integer N,  the length of the array representing the serialized representation of a tree.

The next line contains N-space-separated integers. 

The input is given as a serialized representation of a tree.

The following function parses the input:

Node* getBinaryTree(vector<int> &num, int*ind)

Sum of N across all test cases ≤ 10^7.


Output Format

Return the level order traversal of the tree.


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

5222 
3819 
6801 

8901 
7891 
5407 1720 

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



void fun(Node *root, vector<vector<int>>&ans,int dep){
    if(root==NULL) return;
    if(ans.size()<=dep) ans.resize(dep+1);
    ans[dep].push_back(root->val);
    fun(root->left,ans,dep+1);
    fun(root->right,ans,dep+1);
}

vector<vector<int>> getLevelorderTraversal(Node* root) {
    vector<vector<int>> ans;
    fun(root,ans,0);
    return ans;
}
