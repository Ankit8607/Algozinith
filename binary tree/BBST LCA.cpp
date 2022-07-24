// https://www.learning.algozenith.com/problems/BBST-LCA-658

/*

Description

Find the LCA of two nodes of a BBST. You may assume that both the values exist in the tree.
BBST - Balanced Binary Search Tree (height of BST is around O(logN)).

Let T be a rooted tree. The lowest common ancestor between two nodes n1 and n2 is defined as the lowest node in T that has both n1 and n2 as descendants (where we allow a node to be a descendant of itself).


Input Format

The first line contains an integer T, (1 ≤ T ≤ 10^5), the number of test cases.

The first line of each test case contains an integer N, Q the length of the array representing the serialized representation of a tree, the number of queries.

The next line contains N-space-separated distinct integers. 

The next Q lines contain 2-space-separated integers. 

The input is given as a serialized representation of a tree.

The following function parses the input:

Node* getBinaryTree(vector<int> &num, int*ind)

Sum of N across all test cases ≤ 10^7.


Output Format

For each query return the LCA node of two nodes.


Sample Input 1

1
19 9
677 260 180 -1 -1 386 -1 -1 848 680 -1 -1 897 890 -1 -1 913 -1 -1 
897 890
890 386
180 386
890 260
897 890
890 677
848 913
677 890
848 260

Sample Output 1

897 677 260 677 897 677 848 677 677

*/


struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};
Node *getLCANode(Node* root, int n1, int n2)
{
    if(n1<root->val and n2<root->val)return getLCANode(root->left,n1,n2);
    else if(n1>root->val and n2>root->val)return getLCANode(root->right,n1,n2);
    return root;

}
