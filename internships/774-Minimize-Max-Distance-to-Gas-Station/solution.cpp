class Node {
public:
	double val;
	double cut;
	double res;

	Node (double _val, double _cut): val(_val), cut(_cut) {res = _val / (_cut + 1);};

	bool operator < (const Node &a) const {
		return res < a.res
		    || ((res == a.res) && cut < a.cut);
	}

    bool operator <= (const Node &a) const {
		return res < a.res
		    || ((res == a.res) && cut <= a.cut);
	}
};

class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int k) {
		priority_queue<Node> q;
		double sum = 0, base = 0;
		for (int i = 0; i < stations.size() - 1; ++i)
		{
			q.push(Node(stations[i + 1] - stations[i], 0));
			sum += (stations[i + 1] - stations[i]);
		}
		base = sum / (k + 1);


		while (k)
		{
			Node top = q.top();
			q.pop();
			while(q.size() && k > 0 && (q.top() <= top || top.res > base)) {
			    top.cut = top.cut + 1;
                top.res = top.val / (top.cut + 1);
			    k -= 1;
		    }
			q.push(top);
		}
		return q.top().res;
    }
};



