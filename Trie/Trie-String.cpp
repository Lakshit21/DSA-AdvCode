// #include <bits/stdc++.h>
// using namespace std;


//Trie-String
// LowerCase or UpperCase only
struct TrieNode{
    TrieNode *links[26] = {NULL};
    bool EndFlag = 0;
    bool isNull(char ch){
        return links[ch-'a'] == NULL;
    }
    void place(char ch , TrieNode *node){
        links[ch-'a'] = node; // make this new connection
    }
    void setEndFlag() { EndFlag = 1; }
    TrieNode* getNext(char ch){ //send Next trieNode
        return links[ch-'a'];
    }
    bool isEnd(){ return EndFlag;}
};

struct Trie{
    TrieNode *root = NULL;
    Trie(){
        root = new TrieNode();
    }
    void add(string &word){
        long long i,ind;
        TrieNode *curPointer  = root;
        for(i=0;i<word.size();++i){
            if(curPointer->isNull(word[i])){
                //Empty location : We have to make new Referece and connection
                curPointer->place(word[i],new TrieNode()); //RE-place newNode with NULL
                curPointer = curPointer->getNext(word[i]); //Change the curPointer
            }else{
                //Move to that non-Empty Location
                curPointer = curPointer->getNext(word[i]);
            }
        }
        // set the flag to 1 at the end of the String
        curPointer->setEndFlag();
    }
    
    bool isString(string &word){
        long long i,ind;
        TrieNode *curPointer = root;
        for(i=0;i<word.size();++i){
            if(curPointer->isNull(word[i])) return 0;
            curPointer = curPointer->getNext(word[i]);
        }
        return curPointer->isEnd();
    }

    bool isPrefix(string &word){
        long long i,ind;
        TrieNode *curPointer = root;
        for(i=0;i<word.size();++i){
            if(curPointer->isNull(word[i])) return 0;
            curPointer = curPointer->getNext(word[i]);
        }
        return 1; // not check that it is String or not 
    }
};