// https://www.learning.algozenith.com/problems/Sudoku-Solver-847

/*

Description

Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9's 3x3 sub-boxes of the grid.
The “.” character indicates empty cells.


Input Format

Given 9x9 sudoku board, filled with digits 1-9 or having “.” as empty cells.


Output Format

Print the unique valid filled 9x9 Sudoku.


Constraints

9x9 sudoku board, filled with digits 1-9 or having “.” as empty cells.
It is guaranteed that the input board has only one solution.

Sample Input 1

9....3...
..4..6.23
.28..519.
....52...
..3...4..
.5....3..
.4.1.9..5
....642..
.69......

Sample Output 1

976213548
514986723
328745196
481352967
293678451
657491382
842139675
735864219
169527834


*/




#include "bits/stdc++.h"
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 9;

bool isValid(vector<vector<char> > &A, int row, int col)
{
    char elem = A[row][col];
    
    //check range
    if (elem - '0' < 1 || elem - '0' > 9)
        return false;
        
    //check row and column for duplicates
    for (auto p = 0; p<N; ++p)
    {
        if (A[p][col] == elem && p != row)
            return false;
        if (A[row][p] == elem && p != col)
            return false;
    }
    
    //check 3x3 subgrid for duplicates
    int subRow = (row/3)*3; //Ex: row = 2 belongs to first subgrid, so to bring back row to index 0
    int subCol = (col/3)*3; //so as to start iterating first subgrid, we do 2/3 = 0 then 0*3 = 0.
    
    for (auto i = subRow; i<subRow+3; ++i)
    {
        for (auto j = subCol; j<subCol+3; ++j)
        {
            if (A[i][j] == elem && (i != row || j != col))
                return false;
        }
    }
    
    return true;
}

bool sudoku(vector<vector<char> > &A, int row, int col)
{
    if (row == 9)
        return true;
        
    int nextRow, nextCol;
    if (col == 8)
    {
        nextRow = row + 1;
        nextCol = 0;
    }
    else
    {
        nextRow = row;
        nextCol = col + 1;
    }
    
    if (A[row][col] != '.')
    {
        // if (!isValid(A, row, col))
        //     return false;
        return sudoku(A, nextRow, nextCol);
    }
    
    for (auto i = 1; i<=N; ++i)
    {
        A[row][col] = i + '0';
        if (isValid(A, row, col) && sudoku(A, nextRow, nextCol))
            return true;
    }
    
    A[row][col] = '.';
    return false;
}

int main(){
    IOS

    vector<vector<char>>A(9,vector<char>(9));
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++) cin>>A[i][j];

    sudoku(A, 0, 0);

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++) cout<<A[i][j];
        cout<<endl;
    }
    return 0;
}
