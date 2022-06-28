// https://www.learning.algozenith.com/problems/ADDMUL-626

/*

Description

Implement a data structure that supports appending a value to an integer sequence, adding or multiplying a given value to all elements present in the sequence and displaying the value present at any index of the sequence.


Input Format

Implement the AddMul class:

AddMul() : Initializes the object with an empty sequence.
void append(val) : Appends an integer val to the end of the sequence.
void add(inc) : Increments all existing values in the sequence by an integer inc.
void mult(mul) : Multiplies all existing values in the sequence by an integer mul.
int get(idx) : Gets the current value at index idx (0-indexed) of the sequence modulo 109 + 7. If the index is greater or equal than the length of the sequence, return -1.

Output Format

For every time the get function is called return the value present at the given index.


Constraints

1 ≤ val, inc, m ≤ 100

0 ≤ idx ≤ 105

At most 105 calls are made in total to append, add, mult and get.


Sample Input 1

11
append 2
add 3
append 7
mult 2
get 0
add 3
append 10
mult 2
get 0
get 1
get 2

Sample Output 1

10
26
34
20

Note

The sequence after the operations:

[2]
[2+3] -> [5]
[5, 7]
[5*2, 7*2] -> [10, 14]
A[0] = 10
[10+3, 14+3] -> [13, 17]
[13, 17, 10]
[13*2, 17*2, 10*2] -> [26, 34, 20]
A[0] = 26
A[1] = 34
A[2] = 20

*/


class AddMul
{
public:
    long long i, m, MOD;
    vector<long long> v;

    AddMul()
    {
        i = 0, m = 1, MOD = 1e9 + 7;
    }

    long long power(long long a, long long b)
    {
        long long res = 1;
        a = a % MOD;
        while (b > 0)
        {
            if (b & 1)
            {
                res = (res * a) % MOD;
                b--;
            }
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    long long inverse(long long x)
    {
        return power(x, MOD - 2);
    }

    void append(long long val)
    {
        (val += MOD - i) %= MOD;
        (val *= inverse(m)) %= MOD;
        v.push_back(val);
    }

    void add(long long inc)
    {
        (i += inc) %= MOD;
    }

    void mult(long long mul)
    {
        (m *= mul) %= MOD;
        (i *= mul) %= MOD;
    }

    int get(int idx)
    {
        if (idx >= v.size())
            return -1;
        return (v[idx] * m % MOD + i) % MOD;
    }
};
