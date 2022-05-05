impl Solution {
    pub fn num_subarray_product_less_than_k(nums: Vec<i32>, k: i32) -> i32 {
        if k <= 1 {
            return 0;
        }
        let mut prod = 1;
        let mut ans = 0;
        let mut left = 0;
        for (r, &n) in nums.iter().enumerate() {
            prod *= n;
            while prod >= k {
                prod /= nums[left];
                left += 1;
            }
            ans += r - left + 1;
        }
        ans as i32
    }
}
