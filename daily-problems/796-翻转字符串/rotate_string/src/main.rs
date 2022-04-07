impl Solution {
    pub fn rotate_string(s: String, goal: String) -> bool {
        let mut found = true;
        if s.len() != goal.len() {
            return false;
        }
        for i in 0..s.len() {
            found = true;
            for j in 0..s.len() {
                if s.as_bytes()[((i + j) % s.len())] != goal.as_bytes()[j] {
                    found = false;
                    break;
                }
            }
            if found {
                return true;
            }
        }

        false
    }
}
