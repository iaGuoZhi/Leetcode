impl Solution {
    pub fn largest_palindrome(n: i32) -> i32 {
        if n == 1 {
            return 9;
        }
        let upper = 10_u64.pow(n as u32) - 1;
        for left in (0..=upper).rev() {
            let mut p = left;
            let mut i = left;
            while i > 0 {
                p = p * 10 + i % 10;
                i /= 10;
            }
            let mut x = upper;
            while x * x >= p {
                if p % x == 0 {
                    return (p % 1337) as i32;
                }
                x -= 1;
            }
        }
        -1
    }
}
