impl Solution {
    pub fn maximum_wealth(mut accounts: Vec<Vec<i32>>) -> i32 {
        accounts.iter().map({|x| x.iter().sum()).max().unwrap()
    }
}
