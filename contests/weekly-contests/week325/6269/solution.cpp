class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
		int n = words.size();
        if (words[startIndex] == target)
            return 0;

		int right = startIndex, left = startIndex;
		int ans = 0;
		do {
			ans++;
			right = (right + 1) % n;
			if (words[right] == target)
				return ans;
			if (right == left)
				return -1;
			left = (left + n - 1) % n;
			if (words[left] == target)
				return ans;
		} while(left != right);
        return -1;
    }
};

