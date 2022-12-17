class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        int left = INT_MAX;
        int right = INT_MIN;
        for (auto& point : points) {
            left = min(point[0], left);
            right = max(point[0], right);
        }
        int M = left + right; // 中线位置的两倍
        set<vector<int> > s(points.begin(), points.end());
        for (auto& point : points) {
            if (s.find({M - point[0], point[1]}) == s.end()) {
                return false;
            }
        }
        return true;
    }
};
