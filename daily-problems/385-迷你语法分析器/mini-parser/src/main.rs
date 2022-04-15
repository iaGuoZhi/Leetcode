#[derive(Debug, PartialEq, Eq)]
pub enum NestedInteger {
  Int(i32),
  List(Vec<NestedInteger>)
}

impl Solution {
    pub fn deserialize(s: String) -> NestedInteger {
        if !s.starts_with("[") {
            let num: i32 = s.parse().unwrap();
            return NestedInteger::Int(num);
        }
        let mut num = 0;
        let mut neg = false;
        let mut my_st = Vec::new();
        let s = s.into_bytes();

        for (i, c) in s.iter().enumerate() {
            if *c == '[' as u8 {
                let x = NestedInteger::List(Vec::new());
                my_st.push(x);
            } else if c.is_ascii_digit() {
                num = num * 10 + (*c - '0' as u8) as i32;
            } else if *c == '-' as u8 {
                neg = true;
            } else if (*c == ']' as u8) || (*c == ',' as u8) {
                if s[i - 1].is_ascii_digit() {
                    if neg {
                        num *= -1;
                    }
                    if let NestedInteger::List(v) = my_st.last_mut().unwrap() {
                        v.push(NestedInteger::Int(num));
                    }
                }
                num = 0;
                neg = false;
                if (*c == ']' as u8) && (my_st.len() > 1) {
                    let ni = my_st.pop().unwrap();
                    if let NestedInteger::List(v) = my_st.last_mut().unwrap() {
                        v.push(ni);
                    }
                }
            }
        }
        my_st.pop().unwrap()
    }
}
