impl Solution {
    pub fn count_prime_set_bits(left: i32, right: i32) -> i32 {
        let a = vec![0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1];
        let mut res = 0;
        for i in left..=right {
            res += a[i.count_ones() as usize];
        }

        res as i32
    }
}
