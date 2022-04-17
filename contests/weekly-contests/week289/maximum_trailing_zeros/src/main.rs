impl Solution {
    pub fn max_trailing_zeros(grid: Vec<Vec<i32>>) -> i32 {
        let height = grid.len();
        if height <= 0 {
            return 0
        }
        let width = grid[0].len();

        let mut table = vec![vec![vec![0; width]; height]; 4];

        // left to right
        for i in 0..height {
            for j in 0..width {
                let mut num = grid[i][j];
                let mut count = 0;
                while num > 0 && num % 10 == 0 {
                    num /= 10;
                    count += 1;
                }
                if j > 0 {
                  table[0][i][j] = table[0][i][j-1] + count;
                }
            }
        }
                

    }
}
