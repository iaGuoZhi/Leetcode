impl Solution {
    pub fn max_consecutive(mut bottom: i32, mut top: i32, mut special: Vec<i32>) -> i32 {
        bottom -= 1;
        top += 1;
        special.push(bottom);
        special.push(top);
        let width = (top - bottom + 1) / (special.len() as i32);
        let buckets = (top - bottom) / width + 1;
        let mut table = vec![vec![-1; 2]; buckets as usize];

        for floor in special.iter() {
            let buckets_idx = ((*floor - bottom) / width) as usize;
            if table[buckets_idx][0] == -1 || table[buckets_idx][0] > *floor {
                table[buckets_idx][0] = *floor;
            }
            if table[buckets_idx][1] == -1 || table[buckets_idx][1] < *floor {
                table[buckets_idx][1] = *floor;
            }
        }

        let mut ans = 0;
        let mut prior_floor = bottom;

        for x in table.iter() {
            if (*x)[0] != -1 {
                ans = ans.max((*x)[0] - prior_floor - 1);
                prior_floor = (*x)[1];
            }
        }

        ans
    }
}
