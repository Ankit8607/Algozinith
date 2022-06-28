// https://www.learning.algozenith.com/problems/LFU-Cache-628

/*

Description

You need to design and implement a data structure that is able to handle different types of queries. The data structure has a capacity n and at any moment it cannot store more than n keys. Implement the LFUCache class:

LFUCache(int n): Initializes the object with the capacity n of the data structure.
int get(int key): Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
void put(int key, int value): Update the value of the key if present, or insert the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.
When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented; either a get or put operation is called on it.
The least recently used key is the key with the smallest frequency which was called on the earliest among all the keys with the smallest frequency.


Input Format

Your LFUCache object will be instantiated and called as such:

LFUCache* obj = new LFUCache(n); 
int param_1 = obj->get(key);
obj->put(key,value);

Output Format

For each get query the value of the key is printed and if the key is not present, ‘-1’ is printed.


Constraints

1 <= n <= 10000
1 <= q <= 10000 (total number of function calls)
1 <= key <= 10000
0 <= value <= 10000

Sample Input 1

2 10
put 5 6
put 7 4
get 5
put 3 3
get 7
get 3
put 4 9
get 5
get 3
get 4

Sample Output 1

6
-1
3
-1
3
9

Note

1) Cache = [5] , cnt[5] = 1
2) Cache = [7 ,5], cnt[5] = 1 cnt[7] = 1
3) 6 is printed. Cache = [5 ,7], cnt[5] = 2 cnt[7] = 1
4) 7 is the least frequently used key so it is removed.
     Cache = [3 ,5] , cnt[5] = 2 cnt[3] =1
5) 7 is not present. So, -1 is printed.
6) 3 is printed. Cache = [3 ,5], cnt[5] = 2 cnt[3] =2
7) 3 and 5 both have the same frequency but 5 is the least recently used so it is removed.
    Cache = [4 ,3] , cnt[4] = 1 cnt[3] =2
8) 5 is not present. So, -1 is printed.
9) 3 is printed. Cache = [3 ,4], cnt[4] = 1 cnt[3] = 3
10) 9 is printed. Cache = [4 ,3], cnt[4] = 2 cnt[3] = 3.

*/


class LFUCache {
public:
    int n,lfu=0;
    unordered_map<int,list<int>::iterator>iter;
    unordered_map<int,list<int>> fre_list;
    unordered_map<int,pair<int,int>>key_value_fre;
	LFUCache(int n) {
		this->n=n;
	}

    void update(int key){
        int cnt=key_value_fre[key].second;
        key_value_fre[key].second++;
        fre_list[cnt].erase(iter[key]);
        fre_list[cnt+1].push_back(key);
        iter[key]=--fre_list[cnt+1].end();
        if(fre_list[lfu].empty()) lfu++;
    }

	int get(int key) {
		if(key_value_fre.find(key)==key_value_fre.end()) return -1;
        update(key);
        return key_value_fre[key].first;
	}

	void put(int key, int value) {
        if(!n) return;
        if(key_value_fre.find(key)!=key_value_fre.end()){
            key_value_fre[key].first=value;
            update(key);
        }
        else{
            if(key_value_fre.size()==n){
                int del=fre_list[lfu].front();
                key_value_fre.erase(del);
                iter.erase(del);
                fre_list[lfu].pop_front();
                iter.erase(del);
            }
            lfu=1;
            fre_list[1].push_back(key);
            key_value_fre[key]={value,1};
            iter[key]=--fre_list[1].end();
        }
	}

};
