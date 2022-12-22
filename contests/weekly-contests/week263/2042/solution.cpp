class Solution {
public:
    bool areNumbersAscending(string s) {
		int num = 0;
		int last = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] >= '0' && s[i] <= '9')
				num = num * 10 + s[i] - '0';
			if (s[i] == ' ') {
				if (num && num < last)
					return false;
				if (num)
				    last = num;
				num = 0;
			}
        
    }
};
