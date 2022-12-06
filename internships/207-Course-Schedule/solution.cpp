class Solution {
	vector<vector<int>> edges;
	vector<int> visited;
	bool allowed = true;
public:
	void dfs(int course)
	{
		if (allowed == false)
			return;
		visited[course] = 1;

		for (int i = 0; i < edges[course].size(); i++)
		{
			int pre = edges[course][i];
			if (!visited[pre])
				dfs(pre);
			if (visited[pre] == 1)
			{
				allowed = false;
				return;
			}
		}
		visited[course] = 2;
	}

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		edges.resize(numCourses);
		visited.resize(numCourses);

		for (int i = 0; i < prerequisites.size(); ++i)
		{
			edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
		}

		for (int i = 0; i < numCourses; i++)
			dfs(i);
		
		return allowed;
    }
};
