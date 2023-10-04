class MyHashMap {
public:
int d[1000001];
    MyHashMap() {
        fill(d,d+1000000,-1);
    }
    
    void put(int key, int val) {
        d[key]=val;
    }
    
    int get(int key) {
        return d[key];
    }
    
    void remove(int key) {
        d[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */