class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
		int x1 = points[1][0] - points[0][0];
		int x2 = points[2][0] - points[0][0];
		int y1 = points[1][1] - points[0][1];
		int y2 = points[2][1] - points[0][1];

		if (x1 == 0 && y1 == 0 || x2 == 0 && y2 == 0 || x1 == x2 && y1 == y2)
			return false;
		return !(y2 * x1 == x2 * y1);
    }
};
