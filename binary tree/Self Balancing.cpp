// https://www.learning.algozenith.com/problems/Self-Balancing-1047

/*

Read the input from STDIN and print the output to STDOUT. Do not write arbitrary strings anywhere in the program, as these contribute to the standard output and test cases will fail.


Input Format

First-line contains 
T
 - the number of test cases.
The first line of each test case has integers which are the atomic weights of atoms that are being introduced into the solvent (in sequence). alternating with a 
f
l
a
g
 ( 
1
 or 
0
 ) which indicates the introduction of more atoms (
1
=
 next atom present, 
0
=
 next atom absent), each separated by a single white space.


Output Format

For each test case, in a new line, a single line of output has the final structure of the crystal as a sequence of integers, each separated by a single white space, where the integers are atomic weights of atoms in the final stabilized crystal. They are printed in the order: the center atom first, the left side atom next, and then the right side atom. If the left side atom has its own bonds, then they are printed (again left first and right next) before printing the right side atom. This goes on until all the atoms in the crystal are printed. ( Pre-order Traversal )


Constraints

1
≤
T
≤
10
4

1
≤
n
≤
10
5
 - Number of atoms.
1
≤
w
≤
10
6
 - Atomic Weight.

Atomic weights are unique.
Sum of 
n
 across all test cases is 
≤
10
6
.

Sample Input 1

1
12 1 25 1 26 1 32 1 28 1 11 1 10 0

Sample Output 1

25 11 10 12 28 26 32

Sample Input 2

1
31 1 6 1 82 1 5 1 4 1 41 1 53 0

Sample Output 2

31 5 4 6 53 41 82

Note

Explanation Sample 1:
The first atom introduced into the solvent has an atomic weight of 12 which becomes the center of the crystal. The next digit is 1 which suggests that another atom is being introduced into the solvent. The second atom has a weight of 25, and as it is heavier than the first atom, it is pushed in the right direction, and a bond is formed between the two atoms, shown as

12
  \
   25
The next atom has a weight of 26 and it tries to bond with the crystal center which is the atom with a weight of 12. Since it is heavier, it is pushed to the right side. However, there are already 25 on the right side, so 26 cannot form a bond with 12 and has to form a bond with 25. The crystal now has the structure

12
  \
   25
     \
      26
The crystal is now imbalanced as the difference between the right (2 atoms) and left (0 atoms) directions of 12 is more than 1. The rebalancing occurs by changing the center of the crystal to 25 such that it has one atom to the right ( 26 ) and one to the left (12).

   25
  /  \
12    26
After atoms with weights 32 and 28 are processed, the crystal structure will be as

   25
  /  \
12    26
        \
        32
       /
      28 
which will again need rebalancing as the longest imbalanced chain is on the right side (of the crystal center) with 3 atoms and only 1 atom on the left side, an absolute difference of more than 1. The rebalancing will be done to the sub-structure of 26-32-28 by making 28 the local center. The crystal structure now looks like

   25
  /  \
12    28
     /  \
   26    32
The next atoms 11 and 10 will make the structure as

         25
        /  \
      12    28
     /     /  \
   11    26    32
  /
10
making it imbalanced for atom 12 as it has 2 atoms to the left and none to the right. The rebalancing is achieved by making 11 the local center for the sub-structure with one element to the right (12) and one to the left (10). The structure is stable at the center level too as there is 1 bond each on the left and right sides of the center atom.

          25
        /     \
      11       28
     /  \     /  \
   10    12  26   32
The next input is 0 which means no more atoms are being introduced, and hence this is the final stable structure of the crystal. The final structure is printed with the Crystal center atom first i.e. 25 followed by its left bond atom 11, whose left and right atoms are 10 and 12, followed by 28 (right of the center), 26, and 32 (left and right of 28 ).

The Pre-order of the above binary search tree is 25 11 10 12 28 26 32.

*/


#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

class Node{
    public:
    int val,depth;
    Node *left;
    Node *right;
    Node(int val){
        this->val=val;
        this->depth=1;
        left=NULL;
        right=NULL;
    }
};

class AVLTree{
    public:
    // Depth of node
    int depth(Node *cur){
        if(cur==NULL) return 0;
        return cur->depth;
    }

    // Balance factor
    int getbalancefactor(Node *cur){
        if(cur==NULL) return 0;
        return depth(cur->left)-depth(cur->right);
    }

    // Right Rotate 
    Node *rightRotate(Node *cur){
        Node *newroot=cur->left;
        cur->left=newroot->right;
        newroot->right=cur;
        cur->depth=1+max(depth(cur->left),depth(cur->right));
        newroot->depth=1+max(depth(newroot->left),depth(newroot->right));
        return newroot;
    }

    // Left Rotate 
    Node *leftRotate(Node *cur){
        Node *newroot=cur->right;
        cur->right=newroot->left;
        newroot->left=cur;
        cur->depth=1+max(depth(cur->right),depth(cur->left));
        newroot->depth=1+max(depth(newroot->left),depth(newroot->right));
        return newroot;
    }

    // Insertion
    Node* insert(Node *cur,Node *new_node){
        if(cur==NULL){
            cur=new_node;
            return cur;
        }
        if(new_node->val<cur->val) cur->left=insert(cur->left,new_node);
        else if(new_node->val>cur->val) cur->right=insert(cur->right,new_node);
        else return cur;
        cur->depth=1+max(depth(cur->left),depth(cur->right));
        int bf=getbalancefactor(cur);
        if(bf>1 and new_node->val<cur->left->val) return rightRotate(cur);
        if(bf<-1 and new_node->val>cur->right->val) return leftRotate(cur);
        if(bf>1 and new_node->val>cur->left->val){
            cur->left=leftRotate(cur->left);
            return rightRotate(cur);
        }
        if(bf<-1 and new_node->val<cur->right->val){
            cur->right=rightRotate(cur->right);
            return leftRotate(cur);
        }
        return cur;
    }

    // Print Tree 
    void print(Node *cur) {
        if(cur==NULL) return;
        cout<<cur->val<<" ";
        print(cur->left);
        print(cur->right);
    }
};


void solve(){
    AVLTree ob;
    Node *root=NULL;
    int a=1;
    while(a){
        cin>>a;
        Node *cur=new Node(a);
        root=ob.insert(root,cur);
        cin>>a;
    }
    ob.print(root);
    cout<<endl;
}

signed main(){
    IOS
    int t=1; cin>>t; while(t--) 
    solve();
    return 0;
}
