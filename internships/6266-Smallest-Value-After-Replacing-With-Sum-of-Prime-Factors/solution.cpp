class Solution {
	bool is_prime(int n)
	{
		for (int i = 2; i <= sqrt(n); i++)
		{
			if (n % i == 0)
			{
				return false;
			}
		}
		return true;
	}
public:
    int smallestValue(int n) {
		if (n <= 5)
			return n;
		while (!is_prime(n))
		{
			vector<int> factors;
			int i = 2;
			while (i <= sqrt(n))
			{
			    if (is_prime(i) && n % i == 0)
			    {
			    	n = n / i;
					factors.push_back(i);
			    } else {
					i++;
				}
			}
			factors.push_back(n);
			n = accumulate(factors.begin(), factors.end(), 0);
		}
		return n;
    }
};
