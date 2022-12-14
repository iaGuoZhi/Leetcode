class Node {
public:
	char c;
	int freq;
	Node(char _c, int _freq): c(_c), freq(_freq) {};
	bool operator < (const Node &a) const {
		return this->freq < a.freq || (this->freq == a.freq && this->c > a.c);
	}
};

class Solution {
public:
    string rearrangeString(string s, int k) {
		priority_queue<Node> q;
		int arrays[26] = {0};
		string ans;

        if (k == 0)
            return s;
        
		for (char c: s)
		{
			arrays[c - 'a']++;
		}
		for (int i = 0; i < 26; ++i)
		{
            if (arrays[i] > 0)
			    q.push(Node('a' + i, arrays[i]));
		}

		while(q.size())
		{
			int dis = min(int(s.size() - ans.size()), k);
			vector<Node> tmp;
			for (int i = 0; i < dis; ++i)
			{
				if (q.empty())
					return "";
				Node cur = q.top();
				q.pop();
				ans.push_back(cur.c);
				cur.freq--;
                if (cur.freq > 0)
				    tmp.push_back(cur);
			}
			for (auto node : tmp)
			{
				q.push(node);
			}
		}

		return ans;
    }
};
