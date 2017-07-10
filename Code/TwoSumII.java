// 167. Two Sum II - Input array is sorted

import java.util.*;

public class Solution {
    public int[] twoSum(int[] nums, int target) {
    	int i = 0, j = nums.length-1;

    	while (i < j) {
    		int sum = nums[i] + nums[j];
    		if (sum == target) 
    			break; 
    		else if (sum < target)
    			++i;
    		else 
    			--j;
    	}
    	return new int[]{i+1, j+1};
    }

    public static void main(String[] args) {
    	Solution s = new Solution();
    	int[] res = s.twoSum(new int[]{2,7, 11, 13}, 10);
        System.out.println(Arrays.toString(res));
    }
}