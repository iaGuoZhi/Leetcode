impl Solution {
    pub fn to_goat_latin(sentence: String) -> String {
        let mut idx = 1;
        let vowels = vec!['a', 'e', 'i', 'o', 'u'];
        sentence.split(' ').fold(String::new(), |mut ans: String, s| {
            ans.push_str(&s);
            if !vowels.contains(&s.chars().nth(0).unwrap()) {
                ans.push(s.chars().nth(0).unwrap());
            }
            ans.push_str("ma");
            for _ in 0..idx {
                ans.push('a');
            }
            idx = idx + 1;
            ans
        })
    }
}
