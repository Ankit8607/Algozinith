// https://www.learning.algozenith.com/problems/Median-of-BST-653

/*

Description

Given a Binary Search Tree, find the median of it. 
If no. of nodes are even: then median = ((n/2th node + (n+1)/2th node) /2 [integer division]
If no. of nodes are odd : then median = (n+1)/2th node.


Input Format

The first line contains an integer T, (1 ≤ T ≤ 10^5), the number of test cases.

The first line of each test case contains an integer N the length of the array representing the serialized representation of a tree.

The next line contains N-space-separated distinct integers. 

The input is given as a serialized representation of a tree.

The following function parses the input:

Node* getBinaryTree(vector<int> &num, int*ind)

Sum of N across all test cases ≤ 10^7.


Output Format

Return the median.


Sample Input 1

6
11
7456 1022 -1 3404 -1 6680 -1 -1 9344 -1 -1 
11
6084 3515 686 -1 -1 4778 -1 -1 6961 -1 -1 
9
4945 3300 -1 -1 5636 5317 -1 -1 -1 
17
1466 -1 2180 -1 2512 -1 2640 -1 2922 -1 5769 -1 6554 -1 7479 -1 -1 
11
9999 8664 7374 7342 6284 -1 -1 -1 -1 -1 -1 
13
833 622 -1 -1 3935 -1 9318 3991 -1 5233 -1 -1 -1 

Sample Output 1

6680
4778
5131
2781
7374
3963

*/


vector<int> inorder;
void Inorder(Node* root){
   if(root==NULL)return;
   Inorder(root->left);
   inorder.push_back(root->val);
   Inorder(root->right);
}
int getMedian(Node* root){
	if(root==NULL)return 0;
	inorder.clear();
	Inorder(root);
    int n = (int)inorder.size();
    if(n&1) return inorder[n/2];
    return (inorder[n/2]+inorder[n/2-1])/2;
}
