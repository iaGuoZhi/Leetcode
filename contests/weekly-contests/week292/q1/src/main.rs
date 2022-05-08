impl Solution {
    pub fn largest_good_integer(num: String) -> String {
        let mut max_c = 'a';
        let bytes = num.chars();
        let mut count = 1;
        
        bytes.fold('a', |mut acc, x| {
            if x == acc {
                count = count + 1;
            } else {
                acc = x;
                count = 1;
            }
            if count == 3 {
                if max_c == 'a' {
                    max_c = x;
                } else {
                    max_c = max_c.max(x);
                }
            }
            acc
        });

        if max_c == 'a' {
            String::from("")
        } else {
            let mut ans = (0..3).map(|_| max_c).collect::<String>();
            ans
        }

    }
}
