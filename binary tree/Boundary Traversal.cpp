// https://www.learning.algozenith.com/problems/Boundary-Traversal-652

/*

Description

Given a binary tree, print boundary nodes of the binary tree Anti-Clockwise starting from the root. The boundary includes left boundary, leaves, and right boundary in order without duplicate nodes. (The values of the nodes may still be duplicates.)

The left boundary is defined as the path from the root to the left-most node. The right boundary is defined as the path from the root to the right-most node. If the root doesn’t have left subtree or right subtree, then the root itself is left boundary or right boundary. Note this definition only applies to the input binary tree, and not apply to any subtrees.

The left-most node is defined as a leaf node you could reach when you always firstly travel to the left subtree if it exists. If not, travel to the right subtree. Repeat until you reach a leaf node.

The right-most node is also defined in the same way with left and right exchanged.


Input Format

The first line contains an integer 
T
, the number of test cases.
The first line of each test case contains an integer 
N
 - the length of the array representing the serialized representation of a tree.
The next line contains 
N
 space-separated integers.
The input is given as a serialized representation of a tree.

The following function parses the input:
Node* getBinaryTree(vector &num, int*ind)


Output Format

For each test case print the boundary traversal of the tree in a new line.


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

9
9
8249 -1 609 -1 5681 8332 -1 -1 -1 
11
223 4160 6557 -1 -1 4723 -1 -1 992 -1 -1 
7
8124 9834 -1 -1 4119 -1 -1 
11
7738 -1 5199 -1 7433 -1 1304 -1 3265 -1 -1 
7
581 9893 2846 -1 -1 -1 -1 
11
1496 2073 -1 5120 2761 -1 3452 -1 -1 -1 -1 
11
1754 2272 2699 -1 -1 3912 -1 -1 1114 -1 -1 
1
-1 
7
370 -1 1215 -1 7021 -1 -1 

Sample Output 1

8249 8332 5681 609 
223 4160 6557 4723 992 
8124 9834 4119 
7738 3265 1304 7433 5199 
581 9893 2846 
1496 2073 5120 2761 3452 
1754 2272 2699 3912 1114 
370 7021 1215 

*/


bool isLeaf(Node * root) {
  return !root -> left && !root -> right;
}

void addLeftBoundary(Node * root, vector < int > & res) {
  Node * cur = root -> left;
  while (cur) {
    if (!isLeaf(cur)) res.push_back(cur ->val);
    if (cur -> left) cur = cur -> left;
    else cur = cur -> right;
  }
}
void addRightBoundary(Node * root, vector < int > & res) {
  Node * cur = root -> right;
  vector < int > tmp;
  while (cur) {
    if (!isLeaf(cur)) tmp.push_back(cur ->val);
    if (cur -> right) cur = cur -> right;
    else cur = cur -> left;
  }
  for (int i = tmp.size() - 1; i >= 0; --i) {
    res.push_back(tmp[i]);
  }
}

void addLeaves(Node * root, vector < int > & res) {
  if (isLeaf(root)) {
    res.push_back(root -> val);
    return;
  }
  if (root -> left) addLeaves(root -> left, res);
  if (root -> right) addLeaves(root -> right, res);
}
void printBoundary(struct Node* root){
    vector < int > res;
    if (!root) return;
    if (!isLeaf(root)) res.push_back(root ->val);
    addLeftBoundary(root, res);
    // add leaf nodes
    addLeaves(root, res);
    addRightBoundary(root, res);
    for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
    cout<<endl;
}
