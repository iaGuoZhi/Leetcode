class Node {
public:
	int id;
	int score;

	Node (int _id, int _score): id(_id), score(_score) {};

	bool operator <(const Node& a) {
		return this->score > a.score || this->score == a.score && this->id < a.id;
	}
};

class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
		map<string, int> mp;
		vector<Node> nodes;
		vector<int> ans;
		for (auto s : positive_feedback)
			mp[s] = 3;
		for (auto s : negative_feedback)
			mp[s] = -1;
		for (int i = 0; i < student_id.size(); ++i)
		{
            stringstream ss(report[i]);
			int score = 0;
            string s;
            while(getline(ss, s, ' ')){
				if (mp.find(s) != mp.end())
					score += mp[s];
			}
			nodes.push_back(Node(student_id[i], score));
		}
		sort(nodes.begin(), nodes.end());
		for (int i = 0; i < k; ++i)
			ans.push_back(nodes[i].id);
		return ans;
    }
};

