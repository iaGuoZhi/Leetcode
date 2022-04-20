impl Solution {
    pub fn length_longest_path(input: String) -> i32 {
        let mut prev = vec![];
        let mut prev_sum = 0;
        input.split('\n').fold(0, |mut ans, s| {
            let depth = s.chars().filter(|c| *c == '\t').count();
            let len = s.len() - depth;
            while prev.len() > depth {
                prev_sum -= prev.pop().unwrap_or(0);
            }
            if s.contains('.') {
                ans = ans.max(prev_sum + len);
            } else {
                prev.push(len + 1);
                prev_sum = prev_sum + len + 1;
            }
            ans
        }) as i32
    }
}
