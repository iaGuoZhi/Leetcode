class Solution {
public:
    int minBuildTime(vector<int>& blocks, int split) {
		priority_queue<int, vector<int>, greater<int>> pq;

		for (auto block: blocks)
		{
			pq.push(block);
		}

		while(pq.size() > 1)
		{
			pq.pop();
			int second_smallest = pq.top();
			pq.pop();
			pq.push(second_smallest + split);
		}
		return pq.top();
    }
};
