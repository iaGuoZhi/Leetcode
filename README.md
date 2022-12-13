LeetCode
========

# LeetCode Algorighm

## Dynamic Programming

|题目|思路|链接|
|--|--|--|
|10-Regular-Expression-Matching|如果不是\*，则直接匹配，如果是\*分两种情况，\*匹配0个字符和\*匹配n个字符|https://leetcode.cn/problems/regular-expression-matching/|
|5-longest-palindromic-substring|实现一个内部函数，根据输入的两个起点，计算出当前的最长回文串，返回两个端点|https://leetcode.cn/problems/longest-palindromic-substring/|
|84-Largest-Rectangle-in-Histogram/|单调栈|https://leetcode.cn/problems/largest-rectangle-in-histogram/description/|
|42-Trapping-Rain-Water/|计算出两个数组，表示每个节点左右两侧的最高点的高度|https://leetcode.cn/problems/trapping-rain-water/|
|312-Burst-Balloons/|倒过来看这个过程，相当于插入气球|https://leetcode.cn/problems/burst-balloons/|

## 广度/深度优先遍历

|题目|思路|链接|
|--|--|--|
|207-Course-Schedule/|使用visited保存状态，visited[i]==1表示刚开始访问这个course，visited[i]==2表示结束，如果在递归过程中发现了visited[i]==1的节点，说明出现了环，有问题|https://leetcode.cn/problems/course-schedule/|

## 单调栈

|题目|思路|链接|
|--|--|--|
|1063-Number-of-Valid-Subarrays/|单调栈+节点产生的分数并不是在该节点处结算，而是在下一个比它高的节点|https://leetcode.cn/problems/number-of-valid-subarrays|
|772-Basic-Calculator-III||https://leetcode.cn/problems/basic-calculator-iii/|
|255-Verify-Preorder-Sequence-in-Binary-Search-Tree|https://leetcode.cn/problems/verify-preorder-sequence-in-binary-search-tree|

## 并查集

|题目|思路|链接|
|--|--|--|
|305-Number-ofIslands-II|实现一个并查集，与之前查过的节点union|https://leetcode.cn/problems/number-of-islands-ii/|

## 堆

|题目|思路|链接|
|--|--|--|
|1199|转换成哈夫曼算法|https://leetcode.cn/problems/minimum-time-to-build-blocks/submissions/|

## 贪心

|题目|思路|链接|
|--|--|--|
|1102-Path-With-Maximum-Minimum-Value|每次找现有相邻点的最大值|https://leetcode.cn/problems/path-with-maximum-minimum-value|

## 排序

|题目|思路|链接|
|--|--|--|

## 矩阵

|题目|思路|链接|
|--|--|--|
|85-Maximal-Rectangle|转换成84，柱状图的最大矩形问题|https://leetcode.cn/problems/maximal-rectangle/|

## 岛屿问题

|题目|思路|链接|
|--|--|--|
|200-Number-Of-Islands|dfs每个岛屿点，然后标记为水域|https://leetcode.cn/problems/number-of-islands/|
|827-Making-A-Large-Island/|跟上面一样的思路|https://leetcode.cn/problems/making-a-large-island|

## 滑动窗口

|题目|思路|链接|
|--|--|--|
|76-Minimum-Window-Substring/|滑动窗口+map记录当前各个字符的count，滑动窗口保证当前map里所有字符都达到了目标字符串的标准|https://leetcode.cn/problems/minimum-window-substring|
