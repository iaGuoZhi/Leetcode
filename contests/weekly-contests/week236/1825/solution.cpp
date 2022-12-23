class MKAverage {
	vector<int> nums;
	vector<int> sorted;
	int m, k;
	int cur = 0;
	int pos = 0;
	int mk_avg = 0;
public:
    MKAverage(int m, int k) {
		this->m = m;
		this->k = k;
		nums.resize(m);
		sorted.resize(m);
    }
    
    void addElement(int num) {
		if (cur >= m)
		{
		    for (int i = 0; i < m; ++i)
		    {
		    	if (sorted[i] == nums[pos])
		    	{
		    		sorted[i] = num;
		    		break;
				}
		    }
		}
		nums[pos] = num;
		pos = (pos + 1) % m;
		cur++;
    }
    
    int calculateMKAverage() {
		int sum = 0;
		if (cur < m)
			return -1;
		sort(sorted.begin(), sorted.end());
		for (int i = k; i < m - k; ++i)
		{
			sum += sorted[i];
		}
		return sum / (m - 2 * k);
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */
