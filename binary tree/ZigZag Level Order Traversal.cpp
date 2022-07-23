// https://www.learning.algozenith.com/problems/ZigZag-Level-Order-Traversal-558

/*

Description

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

Complete the function:

vector<vector<int>> getZigzagLevelorderTraversal(Node* root)


Input Format

The first line contains an integer T, (1 ≤ T ≤ 10^5), the number of test cases.

The first line of each test case contains an integer N,  the length of the array representing the serialized representation of a tree.

The next line contains N-space-separated integers. 

The input is given as a serialized representation of a tree.

The following function parses the input:

Node* getBinaryTree(vector<int> &num, int*ind)

Sum of N across all test cases ≤ 10^7.


Output Format

Return the zigzag level order traversal of the tree.


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



struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

void fun(Node *root, vector<vector<int>>&ans,int dep){
    if(root==NULL) return;
    if(ans.size()<=dep) ans.resize(dep+1);
    ans[dep].push_back(root->val);
    fun(root->left,ans,dep+1);
    fun(root->right,ans,dep+1);
}

vector<vector<int>> getZigzagLevelorderTraversal(Node* root) {
    vector<vector<int>> ans;
    fun(root,ans,0);
    for(int i=1;i<ans.size();i+=2) reverse(ans[i].begin(),ans[i].end());
    return ans;
}
