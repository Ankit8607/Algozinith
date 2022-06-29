// https://www.learning.algozenith.com/problems/Word-Ladder-643

/*

Description

Given two words beginWord and endWord and a dictionary of words. Find a minimum number of moves to transform beginWord into endWord. In one move, you can change one letter of the current word. New formed word should always be present in the given dictionary. Note that beginWord does not need to be in the dictionary.

Return minimum moves to transform from beginWord to endWord. If no such transformation exists, return 0.


Input Format

The first line of input contains N - the number of words in the dictionary.
Next N lines contain dictionary words separated by space.
The last line of input contains beginWord and endWord.


Constraints

1 ≤ |beginWord| ≤ 10
|endWord| == |beginWord|
1 ≤ Total words in dictionary ≤ 10000
Each word in a dictionary is the same in length as beginWord.
beginWord, endWord, and dictionary words consist of lowercase English letters.
beginWord != endWord
All the words in the dictionary are unique.


Sample Input 1

6
hot dot dog lot log cog
hit cog

Sample Output 1

5

Note

Explanation: hit → hot →dot → dog → cog

*/


class WordLadder
{
public:
	int getMinMoves(string beginword, string endword, vector<string> &dictionary)
	{
        int flag=0;
        unordered_set<string>mp;
        for(auto i:dictionary){
            mp.insert(i);
            if(i==endword) flag=1;
        }
        if(flag==0) return 0;
        queue<string>q;
        q.push(beginword);
        int depth=0;
        while(!q.empty()){
            depth++;
            int size=q.size();
            while(size--){
                string word=q.front(); q.pop();
                for(int i=0;i<word.length();i++){
                    string newword=word;
                    for(char c='a';c<='z';c++){
                        newword[i]=c;
                        if(newword[i]==word[i]) continue;
                        if(newword==endword) return depth+1;
                        if(mp.find(newword)!=mp.end()){
                            q.push(newword);
                            mp.erase(newword);
                        }
                    }
                }
            }
        }
        return 0;
	}
};
