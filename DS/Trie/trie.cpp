#include<iostream>
#include<vector>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int childCount;

    TrieNode(char ch){
        data = ch;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie{
    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word){
        if(word.length()==0){
            root->isTerminal = true;
            return;
        }

        int index = word[0]-'A';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }
      
        insertUtil(child, word.substr(1));
       
    }

    void insertWord(string word){
       
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word){

        if(word.length()==0){
            return root->isTerminal;
        }

        int index = word[0]-'A';
        TrieNode* child;

        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else{
            return false;
        }

        return searchUtil(child, word.substr(1));


    }

    bool search(string word){
        
        return searchUtil(root, word);
    }

    void removeUtil(TrieNode* root, string word){
         if(word.length()==0){
             root->isTerminal = false;
        }

        int index = word[0]-'A';
        TrieNode* child;

        if(root->children[index]!=NULL){
            child = root->children[index];
        }
       else{
         root->childCount--;
       }

        removeUtil(child, word.substr(1));

    }
     
    void remove(string word){
        removeUtil(root, word);
    }

    void lcp(string, string&);

    void print(TrieNode* curr, vector<string> &temp, string prefix){
        if(curr->isTerminal){
            temp.push_back(prefix);
        }

        for(char ch = 'a'; ch<='z'; ch++){
            TrieNode* next = curr->children[ch-'a'];

            if(next!=NULL){
                prefix.push_back(ch);
                print(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestion(string query){
        TrieNode* prev = root;
        vector<vector<string>> output;
        string prefix = "";

        for(int i=0; i<query.size(); i++){
            char lastCh = query[i];
            prefix.push_back(lastCh);

            TrieNode* curr = prev->children[lastCh-'a'];

            if(curr==NULL){
                break;
            }
            
                vector<string> temp;
                print(curr, temp, prefix);
            
            output.push_back(temp);
            temp.clear();

            prev = curr;
        }
        return output;
    }
};

void Trie :: lcp(string str, string & ans){
    for(int i=0; i<str.length(); i++){
        char ch = str[i];

        if(root->childCount ==1){
            ans.push_back(ch);
            int index = ch-'a';
            root = root->children[index];
        }
        else{
            break;
        }
        if(root->isTerminal){
            break;
        }
    }

}



vector<vector<string>> phoneDirectory(vector<string> &contactList, string& querystr){
    Trie *t = new Trie();
    for(int i=0; i<contactList.size(); i++){
        t->insertWord(contactList[i]);
    }
    return t->getSuggestion(querystr);
}


int main(){

    Trie* t = new Trie();
    string a = "d";
    cout<<a.substr(1);
   
    t->insertWord("abcd");
 
    cout<<t->search("abcd");

    return 0;
}