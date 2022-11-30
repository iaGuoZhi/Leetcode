class Solution {
	pair<int, int> expandFromCenter(string s, int begin, int end)
	{
		while(begin >= 0 && end < s.size() && s[begin] == s[end])
		{
			begin--;
			end++;
		}

		return {begin+1, end-1}
	}


public:
    string longestPalindrome(string s) {
      int i = 0;
	  int start = 0, end = 0;

      for (i = 0; i < len; i++)
      {
        auto [left1, right1] = expandFromCenter(s, i, i);
        auto [left2, right2] = expandFromCenter(s, i, i + 1);
		if (right1 - left1 > end - start)
		{
			end = right1;
			start = left1;
		}
		if (right2 - left2 > end - start)
		{
			end = right2;
			start = left2;
		}
	  }
	  return s.substr(start, end + 1);
    }
};

