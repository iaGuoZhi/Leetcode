class Bitset {
	int size;
	vector<bool> bits;
	int cnt = 0;
public:
    Bitset(int size) {
		this->size = size;
		bits.resize(size);
    }
    
    void fix(int idx) {
		if (bits[idx] == 0)
			cnt++;
		bits[idx] = 1;
    }
    
    void unfix(int idx) {
		if (bits[idx] == 1)
			cnt--;
		bits[idx] = 0;
    }
    
    void flip() {
		cnt = size - cnt;
		for (int i = 0; i < size; ++i)
			bits[idx] = bits[idx] ? 0 : 1;
    }
    
    bool all() {
		return cnt == size;
    }
    
    bool one() {
		return cnt > 0;
	}
    
    int count() {
		return cnt;
    }
    
    string toString() {
		string ans;
		for (int i = 0; i < size; ++i)
		{
			ans.push_back(bits[i] + '0');
		}
		return ans;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
