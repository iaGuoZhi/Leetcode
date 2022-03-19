class Solution {
public:
    int halveArray(vector<int>& nums) {
        int ans = 0;
        double sum = 0, halved_sum = 0;
        priority_queue<double> q;

        for(auto num: nums){
            q.push(double(num));
            sum += (double) num;
        }
        halved_sum = sum;

        while(halved_sum > sum / 2){
            double num = q.top();
            q.pop();
            num /= 2;
            q.push(num);
            halved_sum -= num;
            ans += 1;
        }
        return ans;
    }
};
