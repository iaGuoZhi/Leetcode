class Solution
{
public:
    int calculate(string s)
    {
        s += '@';
        stack<char> stkc;
        stack<int> stki;
        unordered_map<char, int> mp = {{'@', 0}, {')', 1}, {'+', 2}, {'-', 2}, {'*', 4}, {'/', 4}, {'(', 6}};
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (isdigit(s[i]))
            {
                int j = i;
                while (j < n && isdigit(s[j]))
                    j++;
                auto t = stoi(s.substr(i, j - i));
                stki.emplace(t);
                i = j - 1;
            }
            else
            {
                while (!stkc.empty() && stkc.top() != '(' && mp[s[i]] <= mp[stkc.top()])
                {
                    auto a = stki.top();
                    stki.pop();
                    if (stkc.top() == '+')
                        stki.top() += a;
                    else if (stkc.top() == '-')
                        stki.top() -= a;
                    else if (stkc.top() == '*')
                        stki.top() *= a;
                    else if (stkc.top() == '/')
                        stki.top() /= a;
                    stkc.pop();
                }
                if (s[i] == ')')
                    stkc.pop();
                else
                    stkc.emplace(s[i]);
            }
        }
        return stki.top();
    }
};
