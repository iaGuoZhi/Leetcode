impl Solution {
    pub fn prefixes_div_by5(nums: Vec<i32>) -> Vec<bool> {
        nums.iter().scan(0, |num, &x| { *num = (*num * 2 + x) % 5; Some(*num == 0)}).collect()
    }
}
