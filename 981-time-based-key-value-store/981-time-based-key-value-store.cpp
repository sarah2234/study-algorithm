class TimeMap {
public:
    // map: key를 기준으로 오름차순으로 자동 정렬
    // unordered_map: 정렬하지 않음
    map<string, map<int, string>> keyMap;
    
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        keyMap[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(keyMap.find(key) == keyMap.end()) 
            return "";
        
        // upper_bound: n보다 큰 최초의 원소의 iterator를 반환
        // lower_bound: n보다 작지 않은 최초의 원소의 iterator를 반환
        auto it = keyMap[key].upper_bound(timestamp);
        if(it == keyMap[key].begin()) 
            return "";
        
        // prev(): 첫 번째 인수로 받은 반복자를 두 번째 인수(default: 1)로 지정한 숫자만큼 감소시킨 반복자를 반환
        return prev(it)->second;
    }
    
    
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
