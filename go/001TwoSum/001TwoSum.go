package TwoSum

/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
UPDATE (2016/2/13):
The return format had been changed to zero-based indices. Please read the above updated description carefully.
*/

func twoSum(nums []int, target int) []int {
	if len(nums) < 2 {
		return []int{-1,-1}
	}

	minus_map := make(map[int]int, len(nums))

	minus_map[target-nums[0]] = 0
	for i:=1; i<len(nums); i++ {
		if idx, ok := minus_map[nums[i]]; ok {
			return []int{idx, i}
		}else{
			minus_map[target-nums[i]] = i
		}
	}

	return []int{-1,-1}
}