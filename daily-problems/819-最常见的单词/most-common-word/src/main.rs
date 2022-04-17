use std::collections::HashMap;

impl Solution {
    pub fn most_common_word(paragraph: String, banned: Vec<String>) -> String {
        let mut words = paragraph.split_whitespace();
        let mut word_counts = HashMap::new();
        let mut res = String::new();
        let mut max_count :i32 = 0;

        for word in words {
            if !banned.contains(word) {
                word_counts[word] += 1;
            }
        }

        for (word, count) in &word_counts {
            if count > max_count {
                res = word;
                max_count = count;
            }
        }

        res
    }
}
