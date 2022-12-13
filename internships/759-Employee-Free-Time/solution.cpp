/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Node {
public:
	int pos;
	int type;

	Node(int _pos, int _type): pos(_pos), type(_type) {};

	bool operator < (const Node &a) const {
		return this->pos < a.pos;
	}
};


class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
		vector<Node> grids;
		int free_start, free_end;
		vector<Interval> ans;
		int cur = 0;
		for (int i = 0; i < schedule.size(); i++)
		{
			for (int j = 0; j < schedule[i].size(); ++j)
			{
				grids.push_back(Node(schedule[i][j].start, 0));
				grids.push_back(Node(schedule[i][j].end, 1));
			}
		}
		sort(grids.begin(), grids.end());

		for (int i = 0; i < grids.size(); ++i)
		{
			if (i != 0 && cur == 0 && grids[i].pos != free_start)
			{
				free_end = grids[i].pos;
				ans.push_back(Interval(free_start, free_end));
			}
			if (grids[i].type == 0)
			{
				cur++;
			} else {
				cur--;
			}

			if (cur == 0)
			{
				free_start = grids[i].pos;
			}
		}
		return ans;
    }
};
