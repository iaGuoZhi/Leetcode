impl Solution {
    pub fn find_duplicates(mut nums: Vec<i32>) -> Vec<i32> {
        let len = nums.len() as i32;
        for i in 0..nums.len() {
            let dst = ((nums[i] - 1) % len) as usize;
            nums[dst] += len;
        }
        let mut ans = vec![];
        for i in 0..nums.len() {
            if nums[i] > 2 * len {
                ans.push(i as i32 + 1);
            }
        }
        ans
    }
}

