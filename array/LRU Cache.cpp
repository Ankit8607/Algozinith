// https://www.learning.algozenith.com/problems/LRU-Cache-629

/*

Description

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.


Input Format

Implement the LRUCache class:

LRUCache(int capacity) : Initialize the LRU cache with positive size capacity.
int get(int key) : Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) : Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.

Output Format

For every call to the get function print the value of the key if it exists else print -1.


Constraints

1 ≤ capacity ≤ 105

1 ≤ key, value ≤ 105

At most 105 calls will be made to functions get and put.


Sample Input 1

9 2
put 1 1
put 2 2
get 1
put 3 3
get 2
put 4 4
get 1
get 3
get 4

Sample Output 1

1
-1
-1
3
4

Note

The cache after every operation is:

[{1,1}]
[{1,1},{2,2}]
[{2,2},{1,1}]
[{1,1},{3,3}]
[{1,1},{3,3}]
[{3,3},{4,4}]
[{3,3},{4,4}]
[{4,4},{3,3}]
[{3,3},{4,4}]

*/


class LRUCache
{
public:
    int size;
    unordered_map<int,pair<int,list<int>::iterator>>mp;
    list<int>lst;
    LRUCache(int capacity)
    {
        size=capacity;
    }

    void update(int key){
        auto it=mp[key].second;
        lst.erase(it);
        lst.push_front(key);
        mp[key].second=lst.begin();
    }

    int get(int key)
    {
        if(mp.find(key)==mp.end()) return -1;
        update(key);
        return mp[key].first;
    }

    void put(int key, int value)
    {
        if(mp.find(key)==mp.end()){
            if(mp.size()>=size){
                mp.erase(lst.back());
                lst.pop_back();
            }
            lst.push_front(key);
            // update
        }
        else update(key);
        mp[key]={value,lst.begin()};
    }
};
