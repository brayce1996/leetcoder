class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map<string, vector<pair<int, string>>> kvStore; // key : {timestamp, value}
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        kvStore[key].push_back(make_pair(timestamp, value));
    }

    string get(string key, int timestamp) {
        if (kvStore.find(key) == kvStore.end() || kvStore[key][0].first > timestamp) {
            return "";
        }

        int low = 0;
        int high = kvStore[key].size() - 1;

        while (low < high) {
            int mid = (low + high + 1) / 2;
            if (kvStore[key][mid].first == timestamp) {
                return kvStore[key][mid].second;
            } else if (kvStore[key][mid].first > timestamp) {
                high = mid - 1;
            } else {
                low = mid;
            }
        }
        return kvStore[key][low].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
