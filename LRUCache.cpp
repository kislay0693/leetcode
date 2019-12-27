 int capacity;
    list<int> values;
    map<int, int> cache_map;
    map<int, list<int>::iterator> pos_map;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    void cachify(int key){
        if(pos_map.count(key))
            values.erase(pos_map[key]);
        if(values.size() >= capacity){
            int temp = values.back();
            values.pop_back();
            pos_map.erase(temp);
            cache_map.erase(temp);
        }
        values.push_front(key);
        pos_map[key] = values.begin();
    }
    int get(int key) {
        int val;
        if(cache_map.count(key)){
            val = cache_map[key];
            cachify(key);
        }else val = -1;
        return val;
    }
    
    void put(int key, int value) {
        cachify(key);
        cache_map[key] = value;
    }
};
