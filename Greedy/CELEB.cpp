// https://www.learning.algozenith.com/problems/CELEB-571

/*

Description

You are hosting a party and have invited N guests. The guests may or may not know each other. You are expecting a famous celebrity to show up. A celebrity is a person who doesn’t know anyone else but everyone else knows him. Find the celebrity if present.

Try to solve it in O(N) time with constant extra space.


Input Format

The first line of each test case contains N - the number of guests attending the party.
The next N lines contain N integers. The jth integer of the ith line is 1 if the ith person knows the jth person, otherwise its 0. (ith integer of the ith line is always 0)


Output Format

Print index of the person who is a celebrity if present, else print -1.


Constraints

2 ≤ N ≤ 1000


Sample Input 1

3
0 1 0
0 0 0
0 1 0
 


Sample Output 1

2


Sample Input 2

2
0 1
1 0


Sample Output 2

-1


Note

In the first test case the 2nd person does not know anyone, but everyone knows him.
In the second test case both of the guests know each other and so there is no guest.

*/



int FindCeleb(vector<vector<int>> &a)
{
    int n = (int)a.size();

    int celeb = 0;

    for (int i = 1; i < n; i++)
    {
        if (a[celeb][i])
            celeb = i;
    }

    for (int i = 0; i < n; i++)
    {
        if (i == celeb)
            continue;

        if (a[celeb][i] || !a[i][celeb])
        {
            celeb = -1;
            break;
        }
    }

    if (celeb != -1)
        celeb++;

    return celeb;
}
