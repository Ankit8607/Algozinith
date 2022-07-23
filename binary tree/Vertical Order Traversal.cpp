// https://www.learning.algozenith.com/problems/Vertical-Order-Traversal-1033

/*

Description

Given the 
r
o
o
t
 of a binary tree, Find the vertical order traversal of the binary tree.

For each node at position 
(
r
,
c
)
, its left and right children will be at positions 
(
r
+
1
,
c
−
1
)
 and 
(
r
+
1
,
c
+
1
)
 respectively. The root of the tree is at 
(
0
,
0
)
.

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.


Input Format

Complete the function vector<vector<int>> verticalTraversal(TreeNode* root) that takes the root of the binary tree as input and returns vertical order traversal of the binary tree.

For local testing of the sample, the first line contains 
T
, the number of test cases. The first line of each test case contains the level order traversal of the tree, where '
x
' denotes the 'nullptr'.


Output Format

Return vertical order traversal of the binary tree as vector<vector<int>>.
In such a case, sort these nodes by their values.


Constraints

1
≤
T
≤
10
4
 - the number of test cases.
1
≤
n
≤
10
5
 - number of nodes in binary tree.
1
≤
v
a
l
u
e
≤
10
5
 - value of nodes in binary tree.
Sum of 
n
 over all test cases is 
≤
10
6
.


Sample Input 1

2
1,2,3,4,6,5,7,x,x,x,x,x,8,x,9,x,x,x,x
3,1,4,7,2,2,x,x,x,x,x,x,x

Sample Output 1

4 
2 
1 5 6 
3 8 
7 
9 

7 
1 
3 2 2 
4 

Note

For test case 1,

           1
         /   \
       2       3
     /   \   /   \
   4      6  5     7
              \     \
               8     9 
Output

[[4],[2],[1,5,6],[3,8],[7],[9]]
Since nodes 5 and 6 are in the same location and should be ordered by their values.

For test case 2,

           3
         /   \
       1       4
     /   \   /   
   7      2  2   
Output

[[7],[1],[3,2,2],[4]]

*/


struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) {
        this->data = x;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Solution {
map<int,vector<pair<int,int>>>mp;

void vertical(TreeNode* root, int hd, int level){
    if(!root) return;
    mp[hd].push_back({level,root->data});
    vertical(root->left,hd-1,level+1);
    vertical(root->right,hd+1,level+1);
}
public:

    vector<vector<int>> verticalTraversal(TreeNode *root) {
         vector<vector<int>>ans;
        if(!root) return ans;
        vertical(root,0,0);
        for(auto x: mp){
            auto cur=x.second;
            sort(cur.begin(),cur.end());
            vector<int>temp;
            for(auto v:cur){
                temp.push_back(v.second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
