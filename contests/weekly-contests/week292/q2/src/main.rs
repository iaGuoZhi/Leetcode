// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn average_of_subtree(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut ans = 0;

        fn cal_subtree(node: Option<Rc<RefCell<TreeNode>>>) -> (sum, count) {
            if let Some(mut node) = node {
                (left_sum, left_count) = cal_subtree(node.borrow_mut().left.take());
                (right_sum, right_count) = cal_subtree(node.borrow_mut().right.take());
                let sum = left_sum + right_sum + node.borrow().val;
                let count = left_count + right_count + 1;
                if sum / count == node.borrow().val {
                    ans += 0;
                }
                (sum , count)
            } else {
                (0, 0)
            }
        }

        cal_subtree(root);

        ans
    }
}
