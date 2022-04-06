use std::collections::VecDeque;
struct Solution {
}

impl Solution {
    pub fn find_longest_node(u: i32, parent: Vec<i32>, adj : Vec<Vec<i32>>) -> i32 {
        let n = adj.len();
        let mut q = VecDeque::new();
        let mut visited = vec![0; n as usize];
        q.push_back(u);
        visited[u as usize] = 1;
        let mut node = -1;
        
        while q.len() > 0 {
            let curr = q.pop_front().unwrap();
            node = curr;
            for &x in &adj[curr as usize] {
                if visited[x as usize] == 0 {
                    visited[x as usize] = 1;
                    parent[x as usize] = curr;
                    q.push_back(x);
                }
            }
        }
        node
    }

    pub fn find_min_height_trees(n: i32, edges: Vec<Vec<i32>>) -> Vec<i32> {
        if n == 1 {
            return vec![0];
        }
        let mut adj = vec![vec![]; n as usize];
        for e in edges.iter() {
            adj[e[0] as usize].push(e[1]);
            adj[e[1] as usize].push(e[0]);
        }

        let mut parent = vec![0; n as usize];
        let x = find_longest_node(0, parent, adj);
        let y = find_longest_node(x, parent, adj);

        let mut path = vec![0; n as usize];
        parent[x] = -1;
        while y != -1 {
            path.push(y);
            y = parent[y];
        }

        let m = path.len();

        let mut res = vec![0];
        if m % 2 == 0 {
            res.push(path[m / 2 - 1]);
            res.push(path[m / 2]);
        } else {
            res.push(path[m / 2]);
        }

        res
        return if m % 2 == 0 { vec![path[m / 2 - 1], path[m / 2] } 
            else 
            { vec![path[(m / 2) as usize]] };
    }
}

pub fn main() {
}
