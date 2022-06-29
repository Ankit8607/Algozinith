// https://www.learning.algozenith.com/problems/Snapshot-Array-642

/*

Description

Implement a SnapshotArray that supports the following interface:

SnapshotArray(int length) initializes an array-like data structure with the given length. Initially, each element equals 0.
void set(index, val) sets the element at the given index to be equal to val.
int snap() takes a snapshot of the array and returns the snap_id: the total number of times we called snap() minus 1.
int get(index, snap_id) returns the value at the given index, at the time we took the snapshot with the given snap_id.

Input Format

The first line of input contains Q, L - the number of queries and the length of the array.
Next, Q lines contain queries of the types mentioned in the problem statement.


Constraints

1 ≤ Q ≤ 105
1 ≤ L ≤ 109
0 ≤ val ≤ 109
0 ≤ snap_id < (the total number of times we call snap())
0 ≤ index < L


Sample Input 1

4 3
set 0 5
snap
set 0 6
get 0 0

Sample Output 1

0
5

*/


class SnapshotArray
{
public:
    unordered_map<int, vector<pair<int, int>>> v;
    int snapId;

    SnapshotArray(int length)
    {
        snapId = 0;
    }

    void set(int index, int val)
    {
        if (v.find(index) != v.end())
        {
            if (v[index].back().second == snapId)
                v[index].back().first = val;
            else
                v[index].push_back({val, snapId});
        }
        else
            v[index].push_back({val, snapId});
    }

    int snap()
    {
        snapId++;
        return snapId - 1;
    }

    int get(int index, int snap_id)
    {
        if (v.find(index) == v.end())
            return 0;

        vector<pair<int, int>> &temp = v[index];

        int L = 0, R = (int)temp.size() - 1;
        int ans = 0;

        while (L <= R)
        {
            int mid = (L + R) / 2;
            if (temp[mid].second <= snap_id)
            {
                ans = temp[mid].first;
                L = mid + 1;
            }
            else
                R = mid - 1;
        }

        return ans;
    }
};
