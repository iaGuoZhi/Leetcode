class MyCircularQueue {
	vector<int> nums;
	int head = 0, tail = 0;
	bool is_full = false;
public:
    MyCircularQueue(int k) {
		nums.resize(k);
    }
    
    bool enQueue(int value) {
        if (is_full)
            return false;
		nums[tail] = value;
		tail = (1 + tail) % nums.size();
		if (tail == head)
			is_full = true;
        return true;
    }
    
    bool deQueue() {
		if (head == tail && !is_full)
			return false;
		if (head == tail)
			is_full = false;
		head = (head + 1) % nums.size();
		return true;
    }
    
    int Front() {
        if (head == tail && !is_full)
            return -1;
		return nums[head];
    }
    
    int Rear() {
        if (head == tail && !is_full)
            return -1;
		return nums[(tail + nums.size() - 1) % nums.size()];
    }
    
    bool isEmpty() {
		return head == tail && !is_full;
    }
    
    bool isFull() {
		return head == tail && is_full;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
