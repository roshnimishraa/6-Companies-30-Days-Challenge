Naive Approach

class LRUCache {
public:
vector<pair<int,int>> cache;
int n;
    LRUCache(int capacity) {
      n = capacity;  
    }
    
    int get(int key) {
    for(int i=0;i<cache.size();i++)
    {
        if(cache[i].first==key)
        {
            int val = cache[i].second;
    pair<int,int> temp = cache[i];
    cache.erase(cache.begin()+i);
    cache.push_back(temp);
    return val;
        }
    }
    return -1;
    }
    
    void put(int key, int value) {
        for(int i=0;i<cache.size();i++)
        {
        if(cache[i].first == key)
        {
            cache.erase(cache.begin()+i);
        cache.push_back({key,value});
        return;
        }
        }
    if(cache.size() == n)
    {
cache.erase(cache.begin());
cache.push_back({key,value});
    }
    else{
      cache.push_back({key,value});  
    }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

Efficient Approach : Doubly Linked List 

class LRUCache {
public:
list<int> dll;
int n;
unordered_map<int,pair<list<int> :: iterator,int>> ht;
    LRUCache(int capacity) {
        n = capacity;
    }
    
void moveToFirst(int key)
{
    dll.erase(ht[key].first);
    dll.push_front(key);
    ht[key].first=dll.begin();
}
    int get(int key) {
        if(ht.find(key) == ht.end()) return -1;
    moveToFirst(key);
    return ht[key].second;
    }
    
    void put(int key, int value) {
    if(ht.find(key) != ht.end())
    {
        ht[key].second = value;
    moveToFirst(key);
    }
    else{
        dll.push_front(key);
    ht[key]={dll.begin(),value};
    n--;
    }
    if(n<0)
    {
        ht.erase(dll.back());
        dll.pop_back();
        n++;
    }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
