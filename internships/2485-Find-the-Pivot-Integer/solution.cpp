class Solution {
public:
    int pivotInteger(int n) {
		int m = n * (n + 1) / 2;
		int cur = 0;

		for (int i = 1; i <= n; ++i)
		{
			cur += i;
			if ((m + i) % 2 == 0 && cur == (m + i) / 2)
				return i;
		}
		return -1;
    }
};
