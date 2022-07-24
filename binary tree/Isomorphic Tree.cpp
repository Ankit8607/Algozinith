// https://www.learning.algozenith.com/problems/Isomorphic-Tree-660

/*

Description

Write a function to detect if two trees are isomorphic. Two trees are called isomorphic if one of them can be obtained from other by a series of flips, i.e. by swapping left and right children of a number of nodes. Any number of nodes at any level can have their children swapped. Two empty trees are isomorphic.


Input Format

The first line contains an integer T, (1 ≤ T ≤ 10^5), the number of test cases.

The first line of each test case contains an integer N, the length of the array representing the serialized representation of a tree1.

The next line contains N-space-separated distinct integers. 

The next line contains an integer M, the length of the array representing the serialized representation of a tree2.

The next line contains M-space-separated distinct integers. 

The input is given as a serialized representation of a tree.

The following function parses the input:

Node* getBinaryTree(vector<int> &num, int*ind)

Sum of N across all test cases ≤ 10^7.


Output Format

Return true/false.


Sample Output 1

3
11
35111 -1 38067 -1 11935 -1 42935 -1 83239 -1 -1 
11
35111 38067 11935 -1 42935 -1 83239 -1 -1 -1 -1 
9
2139 98225 -1 -1 45038 -1 99680 -1 -1 
7
52567 13977 -1 -1 43379 -1 -1 
21
86370 -1 19958 -1 24504 -1 84868 -1 28556 -1 60837 -1 83207 -1 32194 -1 37682 -1 90797 -1 -1 
21
58627 76571 99757 61217 47021 8172 39465 16247 84989 20852 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 

Sample Input 2

yes
no
no

*/

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

bool isIsomorphic(Node * t1, Node * t2)
{
    if(t1==NULL && t2==NULL) return 1;
  	if(t1==NULL || t2==NULL) return 0;
    if(t1->val!=t2->val) return 0;
    if(isIsomorphic(t1->left,t2->left) && isIsomorphic(t1->right,t2->right)) return 1;
    if(isIsomorphic(t1->right,t2->left) && isIsomorphic(t1->left,t2->right)) return 1;
    return 0;
}
Node* getBinaryTree(vector<int> &num, int*ind) {
    if(num[*ind] == -1)
        return NULL;
    Node* node = new Node(num[*ind]);
    (*ind)++;
    node->left = getBinaryTree(num,ind);
    (*ind)++;
    node->right = getBinaryTree(num,ind);
    return node;
}
