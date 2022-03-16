class AllOne {
    map<string, int> hash_table;
    vector<pair<string, int>> sorted_array;
public:
    AllOne() {
        return;
    }
    
    void inc(string key) {
        int idx;

        if(hash_table.find(key) == hash_table.end()){
            sorted_array.push_back(make_pair(key, 1));
            hash_table[key] = sorted_array.size() - 1;
        }else{
            idx = hash_table[key];
            sorted_array[idx].second += 1;
            while(idx > 0 && sorted_array[idx - 1].second < sorted_array[idx].second){
                hash_table[sorted_array[idx].first] = idx - 1;
                hash_table[sorted_array[idx - 1].first] = idx;
                iter_swap(sorted_array.begin() + idx - 1, sorted_array.begin() + idx);
                idx -= 1;
            }
        }
    }
    
    void dec(string key) {
        int idx;

        if(hash_table.find(key) == hash_table.end()){
            //should not reach here
            return;
        }else{
            idx = hash_table[key];
            sorted_array[idx].second -= 1;
            while(idx < sorted_array.size() - 1  && sorted_array[idx + 1].second > sorted_array[idx].second){
                hash_table[sorted_array[idx].first] = idx + 1;
                hash_table[sorted_array[idx + 1].first] = idx;
                iter_swap(sorted_array.begin() + idx + 1, sorted_array.begin() + idx);
                idx += 1;
            }
            if(sorted_array[idx].second == 0){
                sorted_array.erase(sorted_array.begin() + idx);
                hash_table.erase(key);
            }
        }
    }
    
    string getMaxKey() {
        if(sorted_array.size() == 0)
            // should not reach here
            return "";

        return sorted_array[0].first;
    }
    
    string getMinKey() {
        if(sorted_array.size() == 0)
            // should not reach here
            return "";

        return sorted_array[sorted_array.size() - 1].first;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
