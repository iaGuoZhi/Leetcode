class Solution {
public:
    /**
     * In this algorithm, we use a table to record points.
     * for each num, there exists a continuous region where all num will get one point
     * if it is set as rotation index. This region can be diagramed as follow:
     * <----------------------**********---------------->
     * Therefore we can add region begin a point, and substract the index after 
     * this region one point. This is showed below
     * <----------------------**********---------------->
     * <00000000000000000000001000000000-100000000000000>
     * Then we can get the result score of index i by summing point from index 0 to index i.
     *
     * We implemented this algorithm based on the following findings:
     * 1. all pointed region of any num[i] starts at (i + 1) % nums.length, because nums[i] < nums.length.
     * 2. score at point 0 has no influence on final result. This simplify end to head problems.
     */
    int bestRotation(vector<int>& nums) {
        int size = nums.size();
        int max_point = INT_MIN;
        int res = 0;
        vector<int> points(size, 0);
        for(int i = 0; i < size; ++i) {
            points[(i + 1) % size] += 1;
            points[(i + size - nums[i] + 1) % size] -= 1;
        }
        for(int i = 0; i < size; ++i) {
            points[i] += i > 0 ? points[i - 1] : 0;
            if(points[i] > max_point) {
                max_point = points[i];
                res = i;
            }
        }

        return res;
    }
};
