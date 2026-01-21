// stores_ manages all items in lists with different frequencies. Each time the
// item is got/set, the item should be deleted from the old list and moved to
// the list with proper frequency.
//
// index_ maps the key to the iterator of the store.
//
// min_frequency_ is updated when the list with min_frequency_ is deleted.
//
// For LRU, see ./lru-cache-146.cc
struct Item {
  int key;
  int value;
  int frequency;
};

class LFUCache {
  unordered_map<int, list<Item>> store_;
  unordered_map<int, list<Item>::iterator> index_;
  int capacity_;
  int size_;
  int min_frequency_;

public:
  LFUCache(int capacity) {
    capacity_ = capacity;
    size_ = 0;
    min_frequency_ = std::numeric_limits<int>::max();
  }

  int get(int key) {
    auto iter = index_.find(key);
    if (iter == index_.end()) { // insert
      return -1;
    }
    auto [_, value, freq] = *iter->second;
    store_[freq].erase(iter->second);
    if (store_[freq].empty() && freq == min_frequency_) {
        min_frequency_++;
    }
    freq++;
    min_frequency_ = min(min_frequency_, freq);
    store_[freq].insert(store_[freq].begin(), Item{key, value, freq});
    index_[key] = store_[freq].begin();
    return value;
  }

  void put(int key, int value) {
    auto iter = index_.find(key);
    if (iter == index_.end()) { // insert
      if (capacity_ == size_) { // evict
        auto &min_freq_items = store_[min_frequency_];
        assert(!min_freq_items.empty());
        const auto [key, value, freq] = min_freq_items.back();
        if (store_[freq].empty() && freq == min_frequency_) {
          min_frequency_++;
        }
        min_freq_items.pop_back();
        index_.erase(key);
        size_--;
      }
      int freq = 1;
      auto &freq_items = store_[freq];
      freq_items.insert(freq_items.begin(), Item{key, value, freq});
      index_[key] = freq_items.begin();
      min_frequency_ = min(min_frequency_, freq);
      size_++;
    } else { // update
      auto [key, _, freq] = *iter->second;
      store_[freq].erase(iter->second);
      if (store_[freq].empty() && freq == min_frequency_) {
        min_frequency_++;
      }
      freq++;
      store_[freq].insert(store_[freq].begin(), Item{key, value, freq});
      index_[key] = store_[freq].begin();
    }
  }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

