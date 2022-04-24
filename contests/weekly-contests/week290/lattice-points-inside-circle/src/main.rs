use std::f32;

impl Solution {
    pub fn count_lattice_points(mut circles: Vec<Vec<i32>>) -> i32 {
        circles.sort_by_key(|k| k[2]);
        circles.reverse();
        print!("{}", circles[0][2]);

        let mut ans = 0;
        for x in 0..201 {
            for y in 0..201 {
                if exist_in_circle(Vec::from([x, y]), circles.clone()) {
                    ans += 1;
                }
            }
        }

        ans
    }
}

fn distance(point_a: Vec<i32>, point_b: Vec<i32>) -> i32 {
    let square = (point_a[0] - point_b[0]).pow(2) + (point_a[1] - point_b[1]).pow(2);
    let square :f32 = square as f32;
    square.sqrt().ceil() as i32
}

fn exist_in_circle(point: Vec<i32>, circles: Vec<Vec<i32>>) -> bool {
    for i in 0..circles.len() {
        if distance(point.clone(), Vec::from([circles[i][0], circles[i][1]])) <= circles[i][2] {
            return true;
        }
    }
    return false;
}

