
/*
copyright@nciaebupt 转载请注明出处
题目：有一个整数数组，请求出两两之差绝对值最小的值,记住，只要得出最小值即可，不需要求
出是哪两个数。
分析：有人证明这个算法是Theta(nlogn)的。
因为，“判定一个数组有无重复元素”的算法是Theta(nlogn)的。如果这个找最近数对的算法存在小于O(nlogn)的算法，那么，只要判断最近数对的差是不是0，就能用同样复杂度解决“有无重复元素”问题。所以，这个算法不可能小于O(nlogn)。而这个算法存在nlogn的算法（先排序），所以它就是Theta(nlogn)的。

一些信息：http://stackoverflow.com/questions/4990060/an-algorithm-in-on-time-complexity-to-find-a-pair-of-nos-in-an-array-which-have
还有这个：http://en.wikipedia.org/wiki/Element_distinctness_problem

用基数排序可以达到O(n)，但是这要求数据范围不大。
结论，先排序，再找出相邻数之间差的最小值
*/
