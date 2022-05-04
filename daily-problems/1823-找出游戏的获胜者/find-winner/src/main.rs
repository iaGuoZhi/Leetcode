impl Solution {
    pub fn find_the_winner(n: i32, k: i32) -> i32 {
        let mut table = vec![1; n as usize];
        let mut idx = 0;
        let mut cnt = 0;
        let mut evict = 0;

        while evict != n - 1 {
            if(table[idx] == 1) {
                cnt += 1;
            }
            if(cnt == k) {
                table[idx] = 0;
                evict += 1;
                cnt = 0;
            }
            idx = (idx + 1) % n as usize;
        }

        (0..n).rfold(0, |mut res, x| {
            if table[x as usize] == 1 {
                res = x + 1;
            }
            res
        })
    }
}
