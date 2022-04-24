use std::collections::HashMap;

impl Solution {
    pub fn intersection(nums: Vec<Vec<i32>>) -> Vec<i32> {
        let mut map = HashMap::new();
        let mut ans = Vec::new();

        for i in 0..nums.len() {
            for j in 0..nums[i].len() {
                *map.entry(nums[i][j]).or_insert(0) += 1;
            }
        }

        for (idx, val) in &map {
            if *val == nums.len() as i32 {
                ans.push(*idx);
            }
        }

        ans.sort();

        ans
    }
}
