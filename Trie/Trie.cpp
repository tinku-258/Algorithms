/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

class Node{
   public:
      vector<Node*> links;
      bool isEndOfWord;
      Node(){
          links.resize(26,NULL);//initially all links are set to NULL
          isEndOfWord=false;
      }
};
class Trie {
public:
    Node* root;
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* node=root;
         for(char& ch:word){
             if(node->links[ch-'a']==NULL){
                 node->links[ch-'a']=new Node();
             }
             node=node->links[ch-'a'];
         }
         node->isEndOfWord=true;
    }
    
    bool search(string word) {
        Node* node=root;
        for(char& ch:word){
            if(node->links[ch-'a']==NULL) return false;
            node=node->links[ch-'a'];
        }
        // return if this is the end of word
        return node->isEndOfWord==true;
    }
    
    bool startsWith(string prefix) {
        Node* node=root;
        for(char& ch:prefix){
            if(node->links[ch-'a']==NULL) return false;
            node=node->links[ch-'a'];
        }
        return true;
    }
};
