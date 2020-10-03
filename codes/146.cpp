/*
 * Approach: map + list(double linked list) + iterator
 * Time complexity: O(1)   || 13.39% (408 ms)
 * Space complexity: O(n)  || 6.10% (42.1 MB)
 */
class LRUCache {
private:
    int _capacity;
    list<int> lru;
    // cache[key] = { value, lru::iterator }
    unordered_map<int, pair<int, list<int>::iterator>> cache;

    void updateLRU(int key) {
        if (cache.count(key)) lru.erase(cache[key].second);
        lru.push_front(key);
        cache[key].second = lru.begin();
    }

    void evictLRU() {
        cache.erase(lru.back());
        lru.pop_back();
    }
public:
    LRUCache(int capacity) : _capacity(capacity) {}
    
    int get(int key) {
        if (cache.count(key) == 0) return -1;
        updateLRU(key);
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if (cache.size() == _capacity && cache.count(key) == 0) evictLRU();
        updateLRU(key);
        cache[key].first = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// Not abstract and not decoupling, but do it specialized
/*
 * Approach: map + list(double linked list) + iterator
 * Time complexity: O(1)   || 19.10% (292 ms)
 * Space complexity: O(n)  || 6.10% (42.2 MB)
 */
class LRUCache {
private:
    int _capacity;
    list<int> lru;
    // cache[key] = { value, lru::iterator }
    unordered_map<int, pair<int, list<int>::iterator>> cache;
public:
    LRUCache(int capacity) : _capacity(capacity) {}
    
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;
        lru.erase(it->second.second);
        lru.push_front(it->first);
        it->second.second = lru.begin();
        return it->second.first;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            lru.erase(it->second.second);
            lru.push_front(it->first);
        } else {
            if (cache.size() == _capacity) {
                cache.erase(lru.back());
                lru.pop_back();
            }
            lru.push_front(key);
        }
        cache[key] = { value, lru.begin() };
    }
};