// https://www.learning.algozenith.com/problems/Mirror-Tree-647

/*

Description

Convert a Binary Tree into its Mirror Tree.

Mirror of a Tree: Mirror of a Binary Tree T is another Binary Tree M(T) with left and right children of all non-leaf nodes interchanged. 


Input Format

The first line contains an integer T, (1 ≤ T ≤ 10^5), the number of test cases.

The first line of each test case contains an integer N,  the length of the array representing the serialized representation of a tree.

The next line contains N-space-separated integers. 

The input is given as a serialized representation of a tree.

The following function parses the input:

Node* getBinaryTree(vector<int> &num, int*ind)

Sum of N across all test cases ≤ 10^7.


Output Format

Return the mirror tree.


Sample Input 1

3
3
2067 -1 -1 
13
8365 1448 5240 -1 9909 -1 -1 5843 -1 -1 5682 -1 -1 
15
7841 883 -1 -1 4929 6791 -1 -1 9159 2122 -1 -1 4179 -1 -1 

Sample Output 1

2067 -1 -1 
8365 5682 -1 -1 1448 5843 -1 -1 5240 9909 -1 -1 -1 
7841 4929 9159 4179 -1 -1 2122 -1 -1 6791 -1 -1 883 -1 -1 

*/


struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node* getMirrorTree(Node* root) {
    if(root==NULL) return root;
    getMirrorTree(root->right);
    getMirrorTree(root->left);
    swap(root->left,root->right);
    return root;
}
