use std::collections::HashMap;

impl Solution {
    pub fn most_common_word(paragraph: String, banned: Vec<String>) -> String {
        let paragraph = paragraph
            .to_lowercase()
            .replace("!", " ")
            .replace("?", " ")
            .replace("'", " ")
            .replace(",", " ")
            .replace(";", " ")
            .replace(".", " ");

        let parts = paragraph.split_ascii_whitespace();

        let banned_set = banned
            .iter()
            .collect::<std::collections::HashSet<&String>>();

        let mut count_map: std::collections::HashMap<&str, i32> = std::collections::HashMap::new();

        let (mut max, mut result) = (0, "");

        parts.into_iter().for_each(|v| {
            if v != "" && !banned_set.contains(&(v.to_string())) {
                let count = count_map.entry(v).or_insert(0);
                *count += 1;
                if *count > max {
                    result = v;
                    max = *count;
                };
            }
        });

        result.to_string()
    }
}
