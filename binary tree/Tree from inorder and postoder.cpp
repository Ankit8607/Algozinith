// https://www.learning.algozenith.com/problems/Tree-from-inorder-and-postoder-646

/*

Description

Construct Tree from given Inorder and Postorder traversals


Input Format

The first line contains an integer T, (1 ≤ T ≤ 10^5), the number of test cases.

The first line of each test case contains an integer N,  the length of the array representing the serialized representation of a tree.

The next line contains N-space-separated distinct integers representing the Inorder Traversal of the tree. 

The next line contains N-space-separated distinct integers representing the Postorder Traversal of the tree. 

Sum of N across all test cases ≤ 10^7.


Output Format

For each test case find the Binary Tree and return the Root Node of the binary tree. Complete this function - 

Node* getBinaryTree(vector<int>&inorder,vector<int>&preorder)
{

}

A function in the main converts the Binary Tree Root returned into serialized array structure and prints it.


Sample Input 1

7
4
5096 3880 9002 8750 
8750 9002 3880 5096 
8
213 1746 332 4793 7083 1732 384 7576 
1746 213 4793 332 1732 7083 7576 384 
4
5400 3001 339 7702 
5400 339 7702 3001 
2
7466 5992 
5992 7466 
4
5156 7626 2362 2601 
5156 7626 2362 2601 
10
6402 3772 1983 7765 4414 2719 8960 1670 2682 3815 
6402 1983 7765 2719 4414 1670 3815 2682 8960 3772 
1
7859 
7859 

Sample Output 1

5096 -1 3880 -1 9002 -1 8750 -1 -1 

384 7083 332 213 -1 1746 -1 -1 4793 -1 -1 1732 -1 -1 7576 -1 -1 

3001 5400 -1 -1 7702 339 -1 -1 -1 

7466 -1 5992 -1 -1 

2601 2362 7626 5156 -1 -1 -1 -1 -1 

3772 6402 -1 -1 8960 4414 7765 1983 -1 -1 -1 2719 -1 -1 2682 1670 -1 -1 3815 -1 -1 

7859 -1 -1 

*/


Node *fun(int lin,int rin,int lpo,int rpo,vector<int>&inorder,vector<int>&postorder,map<int,int>&mp){

    if(lin>rin || lpo>rpo) return NULL;

    Node *root = new Node(postorder[rpo]);
    int brpoint=mp[postorder[rpo]];
    int len=brpoint-lin-1;
    root->left=fun(lin,brpoint-1,lpo,lpo+len,inorder,postorder,mp);
    root->right=fun(brpoint+1,rin,lpo+len+1,rpo-1,inorder,postorder,mp);
    return root;
}

Node* getBinaryTree(vector<int>&inorder,vector<int>&postorder)
{
    map<int,int>mp;
    int n=inorder.size();
    for(int i=0;i<n;i++){
        mp[inorder[i]]=i;
    }
    return fun(0,n-1,0,n-1,inorder,postorder,mp);
}
