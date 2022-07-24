// https://www.learning.algozenith.com/problems/Tree-from-inorder-and-preorder-645

/*

Description

Construct Tree from given Inorder and Preorder traversals


Input Format

The first line contains an integer T, (1 ≤ T ≤ 10^5), the number of test cases.

The first line of each test case contains an integer N,  the length of the array representing the serialized representation of a tree.

The next line contains N-space-separated distinct integers representing the Inorder Traversal of the tree. 

The next line contains N-space-separated distinct integers representing the Preorder Traversal of the tree. 

Sum of N across all test cases ≤ 10^7.


Output Format

For each test case find the Binary Tree and return the Root Node of the binary tree. Complete this function - 

Node* getBinaryTree(vector<int>&inorder,vector<int>&preorder)
{

}

A function in the main converts the Binary Tree Root returned into serialized array structure and prints it.


Sample Input 1

3
4
8766 2202 6058 4965 
4965 6058 2202 8766 
2
3501 2847 
2847 3501 
10
9648 6223 3180 3901 7171 3849 8580 5539 6609 1578 
6609 8580 7171 3180 9648 6223 3901 3849 5539 1578 

Sample Output 1

4965 6058 2202 8766 -1 -1 -1 -1 -1 
2847 3501 -1 -1 -1 
6609 8580 7171 3180 9648 -1 6223 -1 -1 3901 -1 -1 3849 -1 -1 5539 -1 -1 1578 -1 -1 

*/


struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node *fun(int lin,int rin,int lpre,int rpre,vector<int>&inorder,vector<int>&preorder,map<int,int>&mp){

    if(lin>rin || lpre>rpre) return NULL;

    int rootval=preorder[lpre];
    Node *root = new Node(rootval);
    int brpoint=mp[rootval];
    int len=brpoint-lin;
    root->left=fun(lin,brpoint-1,lpre+1,lpre+len,inorder,preorder,mp);
    root->right=fun(brpoint+1,rin,lpre+len+1,rpre,inorder,preorder,mp);
    return root;
}

Node* getBinaryTree(vector<int>&inorder,vector<int>&preorder)
{
    map<int,int>mp;
    int n=inorder.size();
    for(int i=0;i<n;i++){
        mp[inorder[i]]=i;
    }
    return fun(0,n-1,0,n-1,inorder,preorder,mp);
}
