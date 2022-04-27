impl Solution {
    pub fn pacific_atlantic(heights: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        use std::collections::{HashSet, VecDeque};
        type Point = (i32, i32);
        fn bfs(map: &Vec<Vec<i32>>, fifo: &mut VecDeque<Point>) -> HashSet<Point> {
            let (n, m) = (map.len(), map[0].len());
            let dir = [-1, 0, 1, 0, -1];
            let mut ans = HashSet::with_capacity(n * m);
            fifo.iter().for_each(|p| {ans.insert(*p);});
            while let Some((cx, cy)) = fifo.pop_front() {
                let cur_height = map[cx as usize][cy as usize];
                for i in 0..4 {
                    let x = cx + dir[i];
                    let y = cy + dir[i + 1];
                    if x < 0 || x >= n as i32 || y < 0 || y >= m as i32 {continue}
                    if map[x as usize][y as usize] < cur_height {continue}
                    if ans.get(&(x, y)).is_some() {continue}
                    ans.insert((x, y));
                    fifo.push_back((x, y));
                }
            }
            ans
        }
        let map = heights;
        let (n, m) = (map.len(), map[0].len());
        let mut fifo = VecDeque::with_capacity(n * m);
        for i in 0..m {fifo.push_back((0, i as i32));}
        for i in 1..n {fifo.push_back((i as i32, 0));}
        let pacific = bfs(&map, &mut fifo);
        for i in 0..m {fifo.push_back(((n - 1) as i32, i as i32));}
        for i in 0..n - 1 {fifo.push_back((i as i32, (m - 1) as i32));}
        let atlantic = bfs(&map, &mut fifo);
        pacific.into_iter().filter(|p| atlantic.get(&p).is_some())
            .map(|p| vec![p.0, p.1]).collect()
    }
}
