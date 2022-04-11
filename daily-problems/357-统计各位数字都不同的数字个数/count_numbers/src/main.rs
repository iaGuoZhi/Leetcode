impl Solution {
    pub fn count_numbers_with_unique_digits(n: i32) -> i32 {
        let base: i32 = 9;
        if n == 0 {
            return 1;
        } else if n == 1 {
            return 10;
        } else {
           return base.pow(n as u32) + 10;
        }
    }
}
