class MyHashSet {
public:
    map<int, bool> hash;
    MyHashSet() {
        
    }
    
    void add(int key) {
        hash.insert(make_pair(key, true));
    }
    
    void remove(int key) {
        hash.erase(key);
    }
    
    bool contains(int key) {
        if(hash.find(key)->second)
            return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */