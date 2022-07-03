// https://www.learning.algozenith.com/problems/Word-Boggle-980

/*

Description

Given an 
n
×
m
 
b
o
a
r
d
 of characters and a list of strings 
w
o
r
d
s
, output all words in the list 
w
o
r
d
s
 that are present on the board in lexicographical order.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.


Input Format

First-line contains 
T
 - the number of test cases.
The first line of each test case contains two integers 
n
 and 
m
.
The next 
n
 lines of each test case contain 
n
×
m
 board of characters.
Next line contains 
l
 - size of the list of strings 
w
o
r
d
s
.
The next 
l
 lines contain strings of the list 
w
o
r
d
s
.


Output Format

For each test case, output all words in the list 
w
o
r
d
s
 that are present on the board in lexicographical order on a new line, and output a newline after every test case.


Constraints

1
≤
T
≤
10

1
≤
n
,
m
≤
12

1
≤
w
o
r
d
s
.
s
i
z
e
(
)
≤
10
4

1
≤
w
o
r
d
s
[
i
]
.
s
i
z
e
(
)
≤
10

b
o
a
r
d
[
i
]
[
j
]
 is a lowercase English letter.
w
o
r
d
s
[
i
]
 consists of lowercase English letters.
All the strings of words are unique.


Sample Input 1

2
5 5
a b c d e 
f g h i j
k l m n o 
p q r s t
u v w x y
6
abcdej
xyz
kpu
gmns
aaab
joty
4 4
o  a  a  n 
e  t  a  e 
i  h  k  r 
i  f  l  v 
4
oath
pea
eat  
rain  

Sample Output 1

abcdej
joty
kpu

eat
oath

*/


#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

struct trie {
    struct node {
        node* child[26];
        bool wend, taken;
        string word;
        node() {
            wend = false;
            taken = false;
            for (int i = 0; i < 26; i++)child[i] = nullptr;
        }
    };
    node *root ;
    trie() {
        root = new node();
    }
    void insert(string s) {
        node *cur = root;
        for (auto c : s) {
            int x = c - 'a';
            if (cur->child[x] == nullptr)cur->child[x] = new node();
            cur = cur->child[x];
        }
        cur->wend = true;
        cur->word = s;
    }
    vector<string> ans; // can also use set to prevent duplicates.
    int dx[4] = {0, 0, -1, +1};
    int dy[4] = { -1, +1, 0, 0};
    int n, m;
    void dfs(vector<vector<char>> &grid, int i, int j, node* cur) {
        if (cur == nullptr)return;
        if (cur->wend && !cur->taken)ans.push_back(cur->word), cur->taken = true;
        char v = grid[i][j];
        grid[i][j] = 'X';
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k], y = dy[k] + j;
            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != 'X') {
                char t = grid[x][y];
                dfs(grid, x, y, cur->child[t - 'a']);
            }
        }
        grid[i][j] = v; // backtracking visited.
    }
};
vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    trie tr;
    for (auto word : words)tr.insert(word);
    tr.n = board.size(), tr.m = board[0].size();
    for (int i = 0; i < tr.n; i++) {
        for (int j = 0; j < tr.m; j++) {
            tr.dfs(board, i, j, tr.root->child[board[i][j] - 'a']);
        }
    }
    return tr.ans;
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector < vector<char >> g(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    int l;
    cin >> l;
    vector<string> v;
    while (l--) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    auto x = findWords(g, v);
    sort(x.begin(), x.end());
    for (auto y : x)cout << y << endl;

    cout << endl;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}
