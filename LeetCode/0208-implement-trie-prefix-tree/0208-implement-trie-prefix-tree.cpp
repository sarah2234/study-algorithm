class Trie {
public:
    map<string, bool> words;
    Trie() {
        
    }
    
    void insert(string word) {
        words.insert(make_pair(word, true));
    }
    
    bool search(string word) {
        map<string, bool>::iterator result;
        result = words.find(word);
        if (result == words.end())
            return false;
        else
            return result->second;
    }
    
    bool startsWith(string prefix) {
        int length = prefix.length();
        for (auto it = words.begin(); it != words.end(); it++)
        {
            if (it->first.substr(0, length) == prefix)
                return true;
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */