class Node
{
public:
	int id;
	string timestamp;

	Node(int _id, string _timestamp): id(_id), timestamp(_timestamp) {};

	bool operator < (const Node &a) const {
		return this->timestamp < a.timestamp;
	}
};


class LogSystem {
	vector<Node> arrays;
	map<string, int> mp {
		{"Year", 4},
		{"Month", 7},
		{"Day", 10},
		{"Hour", 13},
		{"Minute", 16},
		{"Second", 19}
	};

	bool smaller(string s1, string s2, int len)
	{
		return s1.substr(0, len) <= s2.substr(0, len);
	}
public:
    LogSystem() {

    }
    
    void put(int id, string timestamp) {
		arrays.push_back(Node(id, timestamp));
    }
    
    vector<int> retrieve(string start, string end, string granularity) {
	    int len = mp[granularity];
		vector<int> ans;
		for (auto node: arrays)
		{
		    if (smaller(start, node.timestamp, len) && smaller(node.timestamp, end, len))
			    ans.push_back(node.id);
		}

		return ans;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(start,end,granularity);
 */
