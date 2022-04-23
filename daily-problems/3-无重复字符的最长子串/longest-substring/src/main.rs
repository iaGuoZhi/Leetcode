use std::collections::HashMap;

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut map = HashMap::new();
        let mut ans = 0;
        let mut prior_idx = 0;

        for idx in 0..s.len() {
            if let Some(prior_idx) = map.get(&(s.chars().nth(idx).unwrap())) {
                if idx - prior_idx > ans {
                    ans = idx - prior_idx;
                    map.insert(&(s.chars().nth(idx).unwrap()), idx);
                }
            }
        }

        if s.len() - prior_idx > ans {
            ans = s.len() - prior_idx;
        }
        ans as i32
    }
}
