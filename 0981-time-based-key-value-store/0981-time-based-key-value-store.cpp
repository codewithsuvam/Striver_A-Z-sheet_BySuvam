 /*
        Problem: Time Based Key-Value Store
        Concept Used:
        Hash Map + Binary Search.
        Store each key's values with timestamps in sorted order.
        Use Binary Search to find the latest timestamp
        that is less than or equal to the query timestamp.
        Algorithm:
        1. set(key, value, timestamp):
           - Append (timestamp, value) to the key's history.
        2. get(key, timestamp):
           - If key does not exist, return "".
           - Binary Search for the first timestamp greater
             than the query timestamp.
           - If it is the first entry, return "".
           - Otherwise, return the value at the previous entry.
        Time Complexity:
        set: O(1) amortized
        get: O(log n), where n is the number of entries for the key.
        Space Complexity: O(N), where N is the total number
        of stored key-value-timestamp entries.
        */
class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> mp;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) {
            return "";
        }

        auto& history = mp[key];

        int left = 0;
        int right = history.size() - 1;
        string ans = "";

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (history[mid].first <= timestamp) {
                ans = history[mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};