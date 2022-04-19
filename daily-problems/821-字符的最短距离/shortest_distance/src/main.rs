impl Solution {
    pub fn shortest_to_char(s: String, c: char) -> Vec<i32> {
        let n = s.len();
        let mut ans = vec![n as i32; n];
        let mut last_c_idx : i32 = -1;
        for i in 0..n {
            if s.as_bytes()[i] as char == c {
                last_c_idx = i as i32;
            }
            if last_c_idx != -1 && (i as i32 - last_c_idx < ans[i]) {
                ans[i] = i as i32 - last_c_idx;
            }
        }

        last_c_idx = -1;
        for i in (0..n).rev() {
            if s.as_bytes()[i] as char == c {
                last_c_idx = i as i32;
            }
            if last_c_idx != -1 && ((last_c_idx - i as i32) < ans[i]) {
                ans[i] = last_c_idx - i as i32;
            }
        }

        return ans;
    }
}
