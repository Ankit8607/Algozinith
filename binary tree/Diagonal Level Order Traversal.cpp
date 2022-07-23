// https://www.learning.algozenith.com/problems/Diagonal-Level-Order-Traversal-563

/*

Description

Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to the same line.


 

Diagonal Level order traversal - 

4 7

2 5 8

1 3 6

Complete the function:

vector<vector<int>> getDiagonalLevelorderTraversal(Node* root)


Input Format

The first line contains an integer T, (1 ≤ T ≤ 10^5), the number of test cases.

The first line of each test case contains an integer N,  the length of the array representing the serialized representation of a tree.

The next line contains N-space-separated integers. 

The input is given as a serialized representation of a tree.

The following function parses the input:

Node* getBinaryTree(vector<int> &num, int*ind)

Sum of N across all test cases ≤ 10^7.


Output Format

Return the diagonal level order traversal of the tree.


Sample Input 1

11
9
5 1 7 6 -1 -1 -1 -1 -1
13
4 10 9 -1 6 -1 -1 5 -1 -1 2 -1 -1
13
3 6 -1 -1 8 5 -1 -1 1 10 -1 -1 -1
9
9 -1 2 -1 7 -1 1 -1 -1
17
3 7 3 0 2 4 3 10 -1 -1 -1 -1 -1 -1 -1 -1 -1
13
7 1 0 -1 4 -1 -1 -1 7 -1 5 -1 -1
7
4 8 -1 -1 9 -1 -1
7
10 2 -1 -1 6 -1 -1
21
5 -1 3 -1 6 -1 5 -1 9 -1 9 -1 3 -1 7 -1 9 -1 7 -1 -1
21
0 9 3 6 8 1 9 4 8 3 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
3
4 -1 -1 

Sample Output 1

6 
7 
1 
5 

9 6 
10 5 
4 2 

6 5 10 
3 8 1 

9 2 7 1 

10 
3 
4 
2 
0 
3 
7 
3 

0 4 
1 
7 7 5 

8 
4 9 

2 
10 6 

5 3 6 5 9 9 3 7 9 7 

3 
8 
4 
9 
1 
8 
6 
3 
9 
0 

4 

Note

Test case 1

      5
     /
    1
    /
   7
   /
 6
Last diagonal contains 6, then diagonal above it contains 7 and so on…

     4
     /.  \
   10.  2
   /.  \
  9.   5
    \
    6

Last diagonal contains 9,6, then diagonal aboive it contains 10, 5 and diagonal above it 4 2    

*/



struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

void fun(Node *root,int dep,map<int,vector<int>>&mp){
    if(root==NULL) return;
    fun(root->left,dep-1,mp);
    mp[dep].push_back(root->val);
    fun(root->right,dep,mp);
}

vector<vector<int>> getDiagonalLevelorderTraversal(Node* root) {
    vector<vector<int>>ans;
    map<int,vector<int>>mp;
    fun(root,0,mp);
    for(auto i:mp){
        ans.push_back(i.second);
    }
    return ans;
}
