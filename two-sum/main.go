package main

import "fmt"

func twoSum(nums []int, target int) []int {
	hashTable := map[int]int{}

	for k, v := range nums {
		p, ok := hashTable[target-v]
		if ok {
			return []int{k, p}
		}
		hashTable[v] = k
	}
	return []int{}
}

func main() {
	nums := []int{1, 4, 6, 7, 3, 6, 13, 4, 2, 5, 6}
	fmt.Println(twoSum(nums, 15))
}
