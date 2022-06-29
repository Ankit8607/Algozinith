// https://www.learning.algozenith.com/problems/Word-Dictionary-649

/*

Description

Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() - Initialises the object.
void addWord(word) - Adds word to the data structure, it can be matched later.
bool search(word) - Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.

Input Format

Your WordDictionary object will be instantiated and called as such:

WordDictionary* obj = new WordDictionary();
obj->addWord(word);
bool param_2 = obj->search(word);

Output Format

For search queries, if there is a string in the data structure that matches word, ‘Yes’ is printed.
Otherwise, ‘No’ is printed.


Constraints

1 <= |word| <= 100
1 <= q <= 1000 (total number of function calls made)
word in addWord consists of lower case English alphabets
word in search consists of lower case English alphabets and ‘.’ character

Sample Input 1

7
add dad
add bad
add mad
search pad
search mad
search .ad
search b..

Sample Output 1

No
Yes
Yes
Yes

Note

pad -> No matching string.
mad -> present in the data structure.
.ad -> Matched by bad, mad, dad.
b.. -> Matched by bad.

*/


class WordDictionary {
public:
    struct node{
        int t=0;
        node *child[26]={0};
    };
    node *root;
	WordDictionary() {
        root=new node;
	}

	void addWord(string s) {
		node *cur=root;
        for(int i=0;i<s.size();i++){
            int x=s[i]-'a';
            if(cur->child[x]==NULL) cur->child[x]=new node;
            cur=cur->child[x];
        }
        cur->t=1;
	}

    bool find(int level,string &s,node *cur){
        if(level==s.size()) return cur->t;

        int ans=0;
        if(s[level]=='.'){
            for(int i=0;i<26;i++){
                if(cur->child[i])
                    ans|=find(level+1,s,cur->child[i]);
            }
        }
        else{
            int x=s[level]-'a';
            if(cur->child[x]) ans|=find(level+1,s,cur->child[x]);
        }
        return ans;
    }

	bool search(string word) {
        return find(0,word,root);
	}

};
