use std::collections::HashMap;

impl Solution {
    pub fn two_sum(mut nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map = HashMap::new();

        for i in 0..nums.len() {
            if let Some(val) = map.get(&(target - nums[i])) {
                if i != *val {
                    return vec![i as i32, *val as i32];
                }
            }
            map.insert(nums[i], i);
        }
        Vec::new()
    }
}
