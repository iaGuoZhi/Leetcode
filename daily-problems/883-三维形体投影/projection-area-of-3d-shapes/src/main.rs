impl Solution {
    pub fn projection_area(grid: Vec<Vec<i32>>) -> i32 {
        let mut ans = 0;

        if grid.len() <= 0 {
            return ans;
        }

        let mut xz_max = vec![0; grid.len()];
        let mut yz_max = vec![0; grid[0].len()];

        for (element_idx, element) in grid.iter().enumerate() {
            for (e_idx, e) in element.iter().enumerate() {
                if *e != 0 {
                    ans += 1;
                }
                yz_max[e_idx] = yz_max[e_idx].max(*e);
                xz_max[element_idx] = xz_max[element_idx].max(*e);
            }
        }

        ans += yz_max.iter().sum::<i32>();
        ans += xz_max.iter().sum::<i32>();
        ans
            

    }
}
