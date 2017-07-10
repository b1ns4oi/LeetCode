import java.util.*;

public class Solution {
    public int[] twoSum(int[] nums, int target) {
    	HashMap<Integer, Integer> m = new HashMap<Integer, Integer>();
    	int[] res = new int[2];

    	for (int i = 0; i < nums.length; ++i) {
    		if (m.containsKey( nums[i] )) {
    			res[0] = m.get( nums[i] );
    			res[1] = i;
    			return res;
    		}
    		m.put(target - nums[i], i);
    	}
        return null;
    }

    public static void main(String[] args) {
    	Solution s = new Solution();
    	int[] res = s.twoSum(new int[]{2,7, -1}, 1);
        System.out.println(Arrays.toString(res));
    }
}