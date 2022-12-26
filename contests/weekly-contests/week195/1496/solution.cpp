class Solution {
public:
    bool isPathCrossing(string path) {
		map<vector<int>, int> mp;

		int x = 0, y = 0;

		for (auto c: path)
		{
			vector<int> p {x, y};
			mp[p] = 1;

			switch(c)
			{
				case 'N': y++; break;
				case 'S': y--; break;
				case 'E': x++; break;
				case 'W': x--; break;
				default: break;
			}

			p[0] = x;
			p[1] = y;
			cout << x << y;
			if (mp.find(p) != mp.end())
				return true;
		}
		return true;
    }
};
