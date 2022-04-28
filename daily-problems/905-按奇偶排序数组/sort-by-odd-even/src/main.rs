impl Solution {
    pub fn sort_array_by_parity(nums: Vec<i32>) -> Vec<i32> {
        nums.iter().filter(|& x| x % 2 == 0)
            .chain(nums.iter().filter(|& x| x % 2 == 1))
            .map(|x| *x)
            .collect::<Vec<i32>>()
    }
}
