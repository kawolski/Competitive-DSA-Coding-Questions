//  Make a TrieNode to keep track of each node of Trie
class TrieNode{
    public :
        //  Char value at current node
        char ch;
        //  Connected nodes
        map<char,TrieNode*> hashmap;
        
        TrieNode(char init_ch) {
            ch = init_ch;
            hashmap.clear();
        }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        //  Mark the starting of the Trie DS with a special symbol
        root = new TrieNode('*');
    }
    
    //      Time Complexity  : O(N)
    //      Space Complexity : O(N)
    //          where N = len(word)
    void insert(string word) {
        //  Follow the linked nodes path
        TrieNode* temp = root;
        for(auto ele : word){
            //  If char present at position
                //  Follow the chain
            if((temp->hashmap).find(ele) != (temp->hashmap).end()){
                temp = (temp->hashmap)[ele];
            }
            //  If char not present at position
                //  Create new chain
            else{
                (temp->hashmap)[ele] = new TrieNode(ele);
                temp = temp->hashmap[ele];
            }
        }
        //  Mark the ending of the chain with '#' for validity check of the word
        (temp->hashmap)['#'] = nullptr;
    }
    
    
    //      Time Complexity  : O(N)
    //          where N = len(word)
    bool search(string word) {
        //  Follow the linked nodes path
        TrieNode* temp = root;
        for(char ele : word){
            //  If ele found at current position in Trie
                //  Jump to next node
            if((temp->hashmap).find(ele) != (temp->hashmap).end())
                temp = (temp->hashmap)[ele];
            //  If ele not found at current position
                //  Word not present    :   return false
            else
                return false;
        }
        //  Check for validity of string
        if((temp->hashmap).find('#') != (temp->hashmap).end())
            return true;
        //  Else no such string inserted
        else
            return false;
    }
    
    
    //      Time Complexity  : O(N)
    //          where N = len(prefix)
    bool startsWith(string prefix) {
        //  Follow the linked nodes path
        TrieNode* temp = root;
        for(char ele : prefix){
            //  If ele found at current position in Trie
                //  Jump to next node
            if((temp->hashmap).find(ele) != (temp->hashmap).end())
                temp = (temp->hashmap)[ele],cout<<ele<<endl;
            //  If ele not found at current position
                //  Word not present    :   return false
            else
                return false;
        }
        //  No validity check, since it is a prefix not the complete string
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */