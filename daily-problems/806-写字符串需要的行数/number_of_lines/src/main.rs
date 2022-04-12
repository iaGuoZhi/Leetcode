impl Solution {
    pub fn number_of_lines(widths: Vec<i32>, s: String) -> Vec<i32> {
        let mut number_line : i32 = 0;
        let mut cur_width : i32 = 0;
        let mut remain_width : i32 = 0;
        let mut res : Vec<i32> = Vec::new();
        let base : i32 = stoi('a');

        for c in s.split_whitespace() {
            let idx = stoi(c) - base;
            if cur_width + widths[idx as usize] <= 100 {
                cur_width = cur_width + widths[idx as usize];
            } else {
                remain_width = cur_width;
                cur_width = 0;
                number_line = number_line + 1;
            }
        }

        res.push(number_line);
        res.push(remain_width);

        res
    }
}
