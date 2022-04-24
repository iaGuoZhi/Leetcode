impl Solution {
    pub fn binary_gap(n: i32) -> i32 {
        let mut gap = -200;
        format!("{:b}", n).char_indices().fold(0, |mut ans, (i, v)| {
            if v == '0' {
                gap += 1;
            } else {
                ans = ans.max(gap + 1);
                gap = 0;
            }
            ans
        }) as i32

    }
}
