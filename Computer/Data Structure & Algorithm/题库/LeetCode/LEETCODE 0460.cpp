class LFUCache {
 private:
  int capacity;
  int min_freq;
  // key -> value / freq 存储实际的值
  unordered_map<int, node> cache;
  // 在确定的频次下是 LRU
  // freq -> keys
  unordered_map<int, list<int>> freq2keys;
  // key -> 在 list 中的位置
  unordered_map<int, list<int>::iterator> key2iter;

  // 给 key 的频次 + 1
  void increase_freq(int key) {
    int freq = cache[key].freq++;
    auto iter = key2iter[key];
    // 从原来的频次中删掉
    freq2keys[freq].erase(iter);
    // 添加到新的频次中
    freq2keys[freq + 1].push_front(key);
    key2iter[key] = freq2keys[freq + 1].begin();  // 重新映射
    // 更新 min_freq
    if (freq2keys[freq].empty()) {
      freq2keys.erase(freq);
      if (freq == min_freq) ++min_freq;
    }
  }

  void remove_least_frequently_used() {
    int key = freq2keys[min_freq].back();
    freq2keys[min_freq].pop_back();
    key2iter.erase(key);
    cache.erase(key);
    if (freq2keys[min_freq].empty())
      freq2keys.erase(
          min_freq);  // 这里的 min_freq 不正确，但没关系，在 add 中会被置 1
  }

  void add(int key, int val) {
    cache[key] = {val, 1};
    freq2keys[1].push_front(key);
    key2iter[key] = freq2keys[1].begin();
    min_freq = 1;
  }

 public:
  LFUCache(int capacity) : capacity(capacity), min_freq(0) {}

  int get(int key) {
    if (!cache.count(key)) return -1;
    increase_freq(key);
    return cache[key].value;
  }

  void put(int key, int value) {
    if (capacity == 0) return;  // ! 注意容量为 0 的情况
    if (!cache.count(key)) {
      if (cache.size() == capacity) {
        remove_least_frequently_used();
      }
      add(key, value);
    } else {
      cache[key].value = value;  // 更新 value
      increase_freq(key);
    }
  }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */