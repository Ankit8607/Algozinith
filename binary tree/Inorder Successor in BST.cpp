// https://www.learning.algozenith.com/problems/Inorder-Successor-in-BST-657

/*

Description

Find the Inorder Successor in BBST.

BBST - Balanced Binary Search Tree (height of BST is around 
O
(
l
o
g
N
)
)
, where 
N
 is the number of nodes in the tree.

In Binary Tree, the Inorder successor of a node is the next node in the Inorder traversal of the Binary Tree. Inorder Successor is NULL for the last node in Inorder traversal.

In Binary Search Tree, the Inorder Successor of an input node can also be defined as the node with the smallest key greater than the key of the input node. So, finding the next node in sorted order is sometimes important.


Input Format

The first line contains an integer 
T
, the number of test cases.
The first line of each test case contains an integer 
N
, 
Q
 - the length of the array representing the serialized representation of a tree, and the number of queries.
The next line contains 
N
-space-separated distinct integers.
The next line contains 
Q
-space-separated integers.

The input is given as a serialized representation of a tree.

The following function parses the input:
Node* getBinaryTree(vector &num, int*ind)


Output Format

For each query, print the inorder successor. If inorder successor does not exist, return 
−
1
.


Constraints

1
≤
T
≤
10
5

Sum of 
N
 across all test cases 
≤
10
7
.


Sample Input 1

1
15 7
333 218 71 -1 -1 323 -1 -1 657 545 -1 -1 715 -1 -1 
813 58 148 224 851 594 880

Sample Output 1

-1 71 218 323 -1 657 -1

*/


Node *old=NULL;
vector<int>inorder;

void fun(Node *root){
    if(root==NULL) return;
    fun(root->left);
    inorder.push_back(root->val);
    fun(root->right);
}

int getInorderSuccessor(Node *root, int k)
{
    if(root!=old){
        old=root;
        inorder.clear();
        fun(root);
    }
    auto it=upper_bound(inorder.begin(),inorder.end(),k);
    if(it==inorder.end()) return -1;
    return *it;
}
