class TimeMap {
    struct Item {
        string value;
        int timestamp;
    };

    unordered_map<string, vector<Item>> store_;
public:
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        auto &chain = store_[key];
        chain.push_back(Item{value, timestamp});
    }

    string get(string key, int timestamp) {
        const auto &chain = store_[key];
   auto it = std::upper_bound(
            chain.begin(), chain.end(), timestamp,
            [](int ts, const Item &item) { return ts < item.timestamp; }
        );
        if (it == chain.begin()) return ""; // all items have timestamp > query
        --it;
        return it->value;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
