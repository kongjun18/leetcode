#include <cstdio>
#include <iostream>
#include <list>
#include <map>
using namespace std;

// Implementation: hash + list
// 
// References:
// - [缓存淘汰算法--LRU算法](https://zhuanlan.zhihu.com/p/34989978)
// - [Least Recently Used (LRU) cache](https://en.wikipedia.org/wiki/Cache_replacement_policies#LRU) 
//
// NOTE:
// - Be carefull when use std::map's iterator.
// - std::list::splice() can be applied on the same list. 
class LRUCache {
public:
  LRUCache(int capacity) : capacity_(capacity) {}

  int get(int key) {
    const auto elem = indicator_.find(key);
    if (elem != indicator_.cend()) { // exist
      cache_.splice(cache_.begin(), cache_,
                    elem->second); // move key-value node into the front
      return elem->second->second;
    }
    return -1;
  }

  void put(int key, int value) {
    const auto elem = indicator_.find(key);
    if (elem != indicator_.cend()) { // exist
      elem->second->second = value;
      cache_.splice(cache_.begin(), cache_, elem->second);
      return;
    }
    if (cache_.size() >= capacity_) {
      const auto evict_key = cache_.back().first;
      indicator_.erase(evict_key);
      cache_.pop_back();
    }
    cache_.push_front({key, value});
    indicator_.insert({key, cache_.begin()});
  }

private:
  int capacity_;
  std::list<std::pair<int, int>> cache_;
  std::map<int, decltype(cache_.begin())> indicator_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
