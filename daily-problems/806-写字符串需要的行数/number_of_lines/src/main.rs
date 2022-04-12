impl Solution {
    pub fn number_of_lines(widths: Vec<i32>, s: String) -> Vec<i32> {
        let mut number_line : i32 = 1;
        let mut cur_width : i32 = 0;

        for c in s.as_bytes() {
            let idx : i32 = c - 97;
            if cur_width + widths[idx as usize] <= 100 {
                cur_width += widths[idx as usize];
            } else {
                cur_width = widths[idx as usize];
                number_line += 1;
            }
        }

        vec![number_line, cur_width]
    }
}
