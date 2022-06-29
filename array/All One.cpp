// https://www.learning.algozenith.com/problems/All-One-547

/*

Description

Design the following data structure.

Implement the AllOne class:

AllOne() Initializes the object of the data structure.
inc(String key) Increments the count of the string key by 1. If the key does not exist in the data structure, insert it with count 1.
dec(String key) Decrements the count of the string key by 1. If the count of the key is 0 after the decrement, remove it from the data structure. It is guaranteed that a key exists in the data structure before the decrement.
getMaxKey() Returns the key with the maximal count. If there are multiple keys with the maximal count, then return the lexicographically largest key. If no element exists, return an empty string "".
getMinKey() Returns the key with the minimal count. If there are multiple keys with minimal count, then return the lexicographically largest key. If no element exists, return an empty string "".

Input Format

The first line contains Q - the number of queries.
Each of the next Q lines contains the query of one of the types mentioned in the problem statement.


Constraints

1 ≤ Q ≤ 105
1 ≤ |key| ≤ 20


Sample Input 1

7
inc hello
inc hello
getMaxKey
getMinKey
inc bye
getMaxKey
getMinKey

Sample Output 1

hello
hello
hello
bye

*/

class AllOne
{
public:
	unordered_map<string,int>mp;
    map<int,multiset<string>>ms;
	AllOne() {
	}

	void inc(string key) {
		if(mp.find(key)==mp.end()){
            mp[key]=1;
            ms[1].insert(key);
        }
        else{
            int fre=mp[key]++;
            ms[fre].erase(key);
            if(ms[fre].empty()) ms.erase(fre);
            ms[fre+1].insert(key);
        }
	}

	void dec(string key) {
        int fre=mp[key]--;
        ms[fre].erase(key);
        if(ms[fre].empty()) ms.erase(fre);
        if(fre>1)
            ms[fre-1].insert(key);
        else mp.erase(key);
	}

	string getMaxKey() {
        if(mp.size()==0) return "";
        auto it=--ms.end();
        return *(--(it->second).end());
	}

	string getMinKey() {
		if(mp.size()==0) return "";
        auto it=ms.begin();
        return *((it->second).rbegin());
	} 
	
};
