// https://www.learning.algozenith.com/problems/Spiral-Order-549

/*

Description

Given a m * n matrix of integers, traverse it in spiral order. In spiral order, we start from top left corner and first move from left to right, then top to bottom, then right to left, then bottom to up, and this is repeated until we traverse whole matrix.


Input Format

The first line contains two space-separated integers M, N (1 ≤ N, M ≤ 1000).

The next M line contains N space-separated integers  1 ≤ A[i][j] ≤ 10^6.


Output Format

Print the matrix in spiral order.


Sample Input 1

3 3
1 2 3
4 5 6
7 8 9

Sample Output 1

1 2 3 6 9 8 7 4 5

*/


vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    int dir = 0;
    vector<int> B;
    int m = A.size();
    int n = A[0].size();
    int t=0, l=0, b = m-1, r=n-1;
    while(t<=b && l<=r){
        if(dir==0){
            for(int i=l; i<=r; i++){
                B.push_back(A[t][i]);
            }
            t++;
            dir=1;
        }
        else if(dir==1){
            for(int i=t; i<=b; i++){
                B.push_back(A[i][r]);
            }
            r--;
            dir=2;
        }
        else if(dir==2){
            for(int i=r; i>=l; i--){
                B.push_back(A[b][i]);
            }
            b--;
            dir=3;
        }
        else if(dir==3){
            for(int i=b; i>=t; i--){
                B.push_back(A[i][l]);
            }
            l++;
            dir=0;
        }
        else break;
    }
    return B;
}
