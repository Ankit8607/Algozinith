// https://www.learning.algozenith.com/problems/Kth-element-of-BST-656

/*

Description

Find the Kth smallest element in a BBST.
BBST - Balanced Binary Search Tree (height of BST is around O(logN)).


Input Format

The first line contains an integer T, (1 ≤ T ≤ 10^5), the number of test cases.

The first line of each test case contains an integer N, Q the length of the array representing the serialized representation of a tree, the number of queries.

The next line contains N-space-separated distinct integers. 

The next line contains Q-space-separated integers. 

The input is given as a serialized representation of a tree.

The following function parses the input:

Node* getBinaryTree(vector<int> &num, int*ind)

Sum of N across all test cases ≤ 10^7.


Output Format

For each query print the Kth smallest element in a BST in a new line.


Sample Input 1

1
21 10
605 192 87 -1 -1 308 -1 -1 758 637 624 -1 -1 668 -1 -1 792 -1 954 -1 -1 
1 2 3 4 5 6 7 8 9 10 

Sample Output 1

87 192 308 605 624 637 668 758 792 954 

*/


struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};
Node *old=NULL;
vector<int>inorder;

void fun(Node *root){
    if(root==NULL) return;
    fun(root->left);
    inorder.push_back(root->val);
    fun(root->right);
}

int getKthElement(Node* root, int k)
{
    if(root!=old){
        old=root;
        inorder.clear();
        fun(root);
    }
    return inorder[k-1];
}
