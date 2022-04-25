use std::collections::HashMap;
use std::time::{SystemTime, UNIX_EPOCH};

struct Solution {
    map: HashMap<i32, Vec<i32>>,
}


/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Solution {

    fn new(nums: Vec<i32>) -> Self {
        let mut map = HashMap::<i32, Vec<i32>>::new();
        for (key, val) in nums.iter().enumerate() {
            let count = map.entry(*val).or_insert(vec![]);
            (*count).push(key as i32);
        }
        Self {
            map,
        }
    }
    
    fn pick(&self, target: i32) -> i32 {
        let vec = self.map.get(&target).unwrap();
        let rand = SystemTime::now().duration_since(UNIX_EPOCH).unwrap().subsec_micros();
        vec[rand as usize % vec.len()]
    }
}

