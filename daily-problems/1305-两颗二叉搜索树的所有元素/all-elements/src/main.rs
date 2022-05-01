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
    pub fn get_all_elements(root1: Option<Rc<RefCell<TreeNode>>>, root2: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        fn in_order(node: Option<Rc<RefCell<TreeNode>>>, vec: &mut Vec<i32>) {
            if let Some(mut node) = node {
                in_order(node.borrow_mut().left.take(), vec);
                vec.push(node.borrow().val);
                in_order(node.borrow_mut().right.take(), vec);
            }
        }
        let mut ret = Vec::new();
        in_order(root1, &mut ret);
        in_order(root2, &mut ret);
        ret.sort();
        ret
    }
}
