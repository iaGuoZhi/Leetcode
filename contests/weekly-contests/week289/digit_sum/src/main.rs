impl Solution {
    pub fn digit_sum(s: String, k: i32) -> String {
        const RADIX: i32 = 10;
        let begin : i32 = 0;
        let res = String::new();
        let num : i32 = 0;
        for c in s.chars() {
            if begin < k {
                num += i32::from(c.to_digit(RADIX).unwrap());
                begin += 1;
            } else {
                begin = 0;
                res.push_str(num.to_str());
                num = 0;
            }
        }

        if res.len() >= k as usize {
            return digit_sum(res, k);
        } else {
            return res;
        }
    }
}
