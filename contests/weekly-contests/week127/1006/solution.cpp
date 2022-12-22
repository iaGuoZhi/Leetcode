class Solution {
public:
    int clumsy(int n) {
		int ans = 0;
		int op = 1;
		while(n >= 4)
		{
			int num = 0;
			num = (op * n) * (n - 1) / (n - 2) + n - 3;
			ans += num;
			if (op == 1)
				op = -1;
		}
		if (n == 3)
			ans += (op * 6);
		if (n == 2)
			ans += (op * 2);
		if (n == 1)
			ans += (op * 1);

		return ans;
	}
};

