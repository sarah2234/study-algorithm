class SmallestInfiniteSet {
    vector<int> deletedSet;
public:
    SmallestInfiniteSet() {
        deletedSet.assign(1001, 0);
    }
    
    int popSmallest() {
        for (int i = 1; i <= 1000; i++)
        {
            if (deletedSet[i] == 0)
            {
                deletedSet[i] = 1;
                return i;
            }
        }
        
        return 0;
    }
    
    void addBack(int num) {
        if (deletedSet[num] == 1)
            deletedSet[num] = 0;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */