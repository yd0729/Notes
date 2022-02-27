class LRUCache {
 private:
  unordered_map<int, list<node>::iterator> map;
  list<node> cache;
  int capacity;

  // 将某个 key 提升为最近使用
  void make_recent(int key) {
    auto x = map[key];
    node new_x = *x;
    // 从链表中删除
    cache.erase(x);
    // 重新插到队头
    cache.push_front(new_x);
    map[key] = cache.begin();  // ! 这里要重新映射
  }

  // 添加最近使用的元素
  void add_recent(int key, int val) {
    // 链表头部就是最近使用的元素
    cache.emplace_front(key, val);
    // 在 map 中添加映射
    map[key] = cache.begin();
  }

  // 删除 key
  void delete_key(int key) {
    auto x = map[key];
    cache.erase(x);
    map.erase(key);
  }

  // 删除最近最久未使用的元素
  void remove_least_recently_used() {
    // 链表尾部的第一个元素就是最近最久未使用的
    node deleted = cache.back();
    cache.pop_back();
    // 从 map 中删除
    map.erase(deleted.key);
  }

 public:
  LRUCache(int capacity) : capacity(capacity), map(), cache() {}

  int get(int key) {
    if (!map.count(key)) return -1;
    // 将该数据提升为最近使用的
    make_recent(key);
    return map[key]->val;
  }

  void put(int key, int value) {
    if (map.count(key)) {
      // 删除旧的数据
      delete_key(key);
      // 新插入的数据为最近使用的数据
      add_recent(key, value);
      return;
    }

    if (capacity == cache.size()) {
      remove_least_recently_used();
    }

    add_recent(key, value);
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */