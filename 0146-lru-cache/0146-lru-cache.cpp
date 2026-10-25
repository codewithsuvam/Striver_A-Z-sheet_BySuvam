// Algo covers in 4 steps and concept of this question is Hash Map + Doubly Linked List.
// 1. Store each key's node in a hash map for O(1) average lookup.
// 2. Keep most recently used nodes at the front and least recently used nodes at the back.
// 3. On get, return -1 if absent; otherwise move the node to the front.
// 4. On put, update or insert at the front; if capacity is exceeded, remove the back node.
// Time Complexity: O(1) average for both get and put.
// Space Complexity: O(capacity), because the cache stores at most capacity entries.
class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        auto it = mp[key];
        cache.splice(cache.begin(), cache, it);

        return mp[key]->second;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            auto it = mp[key];
            it->second = value;
            cache.splice(cache.begin(), cache, it);
            return;
        }

        if (cache.size() == capacity) {
            int lruKey = cache.back().first;
            mp.erase(lruKey);
            cache.pop_back();
        }

        cache.push_front({key, value});
        mp[key] = cache.begin();
    }
};