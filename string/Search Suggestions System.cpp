// https://www.learning.algozenith.com/problems/Search-Suggestions-System-648

/*

Description

Given an array of string products and a string searchWord. We want to design a system that suggests at most three product names from products after searchWord is typed. Suggested products should have a common prefix with the searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.

Return a list of lists of the suggested products after searchWord is typed. 


Input Format

The first line of input contains N - the number of products.
The second line contains product names separated by space.
The third line of input contains Q - the number of queries.
The next Q lines queries contain searchWord.


Constraints

1 ≤ N ≤ 103
1 ≤ Q ≤ 103
1 ≤ |product_name|, |searchWord| ≤ 103
It's guaranteed that all product names are unique.


Sample Input 1

6
mobile mouse moneypot monitor mousepad mango
3
m
mous
mo

Sample Output 1

mango mobile moneypot
mouse mousepad
mobile moneypot monitor

*/


vector<string>res;
class SearchSuggestionSystem
{
public:
    struct node{
        node *child[26];
        int prefix;
        string wend;
        node(){
            prefix=0;
            wend="";
            for(int i=0;i<26;i++) child[i]=NULL;
        }
    };
    node *root;

    void insert(int level,string &s,node *cur){
        if(level==s.size()){
            cur->prefix=1;
            cur->wend=s;
            return;
        }
        int x=s[level]-'a';
        if(cur->child[x]==NULL) cur->child[x]=new node();
        insert(level+1,s,cur->child[x]);
    }
    // void insert(string &s){
    //     node *cur=root;
    //     for(int i=0;i<s.length();i++){
    //         int x=s[i]-'a';
    //         if(cur->child[x]==NULL) cur->child[x]=new node();
    //         cur=cur->child[x];
    //     }
    //     cur->prefix=1;
    //     cur->wend=s;
    // }

    void get(int level,string &s,node *cur){
        if(res.size()>2) return;
        if(cur==nullptr) return;
        if(level>=s.size()){
            if(cur->prefix) res.push_back(cur->wend); 
            for(int i=0;i<26;i++){
                if(cur->child[i]!=NULL){
                    get(level,s,cur->child[i]);
                    if(res.size()>2) break;
                }
            }
        }
        else {
            int x=s[level]-'a';
            if(cur->child[x]!=NULL)
                get(level+1,s,cur->child[x]);
            else return ;
        }
    }

    SearchSuggestionSystem(vector<string> products)
    {
        root=new node;
        for(string i:products) insert(0,i,root);
    }

    vector<string> suggestProducts(string searchWord)
    {
        res.clear();
        get(0,searchWord,root);
        return res;
    }
};
