use std::collections::HashMap;

impl Solution {
    pub fn remove_anagrams(words: Vec<String>) -> Vec<String> {
        let mut prior_word = String::from("");
        let mut ans = Vec::<String>::new();

        pub fn is_anagrams(word1: String, word2: String) -> bool {
            let mut map1 = HashMap::new();
            let mut map2 = HashMap::new();

            for c in word1.chars() {
                *map1.entry(c).or_insert(0) += 1;
            }
            for c in word2.chars() {
                *map2.entry(c).or_insert(0) += 1;
            }

            map1.len() == map2.len() && map1.keys().all(|k| map2.contains_key(k) && map1[k] == map2[k]) 
        }

        for (idx, word) in words.iter().enumerate() {
            if idx != 0 {
                if is_anagrams(prior_word.clone(), (*word).clone()) {
                    continue;
                }
            }
            prior_word = (*word).clone();
            ans.push((*word).clone());
        }

        ans
    }
}
