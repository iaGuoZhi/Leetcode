class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
		string ans;
		int columns = encodedText.size() / rows;
		vector<vector<char>> ss(rows, vector<char>(columns, ' '));

		for (int i = 0; i < encodedText.size(); ++i)
			ss[i / columns][i % columns] = encodedText[i];

		for (int j = 0; j < columns; ++j)
		{
			for (int i = 0; i < rows && i + j < columns; ++i)
				ans.push_back(ss[i][i + j]);
		}
		int n = ans.size() - 1;
		while(n >= 0 && ans[n] == ' ')
			ans.erase((n--), 1);
        
		return ans;
    }
};

