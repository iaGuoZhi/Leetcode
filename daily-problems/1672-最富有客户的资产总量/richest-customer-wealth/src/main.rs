impl Solution {
    pub fn maximum_wealth(mut accounts: Vec<Vec<i32>>) -> i32 {
        let mut max_wealth : i32 = 0;
        for man in accounts {
            let mut money = 0;
            for m_bank in man {
                money += m_bank;
            }
            if money > max_wealth {
                max_wealth = money;
            }
        }


        return max_wealth;
    }
}
