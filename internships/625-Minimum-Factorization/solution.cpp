class Solution {
public:
    int smallestFactorization(int num) {
		if (num <= 9)
			return num;
		long long ans = 0, pos = 1;
        bool flag = true;

		while(num > 1)
		{
            flag = false;
			for (long long i = 9; i >= 2; --i)
			{
				if (num % i == 0)
				{
					ans += pos * i;
					pos *= 10;
					num /= i;
					if (ans > INT_MAX)
						return 0;
                    flag = true;
                    break;
				}
			}
            if (!flag)
                return 0;
		}
		return ans;
    }
};
