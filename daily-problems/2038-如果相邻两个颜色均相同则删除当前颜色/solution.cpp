class Solution {
public:
    bool winnerOfGame(string colors) {
        int size = colors.size();
        int n_a = 0, n_b = 0;

        for(int i = 1; i < size - 1; ++i)
        {
            if(colors[i] == 'A' && colors[i-1] == 'A' && colors[i+1] == 'A'){
                n_a += 1;
            }
            if(colors[i] == 'B' && colors[i-1] == 'B' && colors[i+1] == 'B'){
                n_b += 1;
            }
        }
        return n_a > n_b;
    }
};
