impl Solution {
    pub fn reorder_log_files(mut logs: Vec<String>) -> Vec<String> {
        logs.sort_by_key(|log| {
            let mut parts = log.splitn(2, ' ');
            let first = parts.next().unwrap();
            let second = parts.next().unwrap();
            if second.chars().next().unwrap().is_alphabetic() {
                (0, second.to_owned(), first.to_owned())
            } else {
                (1, "".to_owned(), "".to_owned())
            }
        });
        logs
    }
}
