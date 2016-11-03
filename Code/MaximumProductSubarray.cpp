class Solution {
public:
    // 
    // 这一题在找DP 递归公式时需要注意：要寻找每个下标处的最优解f(n)，仅仅知道f(n-1) 是不够的，还需要知道n-1 处的minimum product 值
    // 因此在迭代过程中，需要save 两个值：1, maximum product 2, minumum product
    // 基于这两个值，才能推导出下一个元素处的最优解
    //
    int maxProduct(vector<int>& nums) {
        int i;
        int max_pre = nums[0], min_pre = nums[0], res = nums[0];
        int max, min;
        
        for (i = 1; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                max = min_pre <= 0 ? nums[i] * min_pre : nums[i];
                min = max_pre > 0 ? nums[i] * max_pre : nums[i];
                
            }
            else if (nums[i] > 0) {
                max = max_pre > 0 ? max_pre * nums[i] : nums[i];
                min = min_pre <= 0 ? min_pre * nums[i] : nums[i];
            }
            else
                max = min = 0;

            res = std::max(res, max);
            max_pre = max;
            min_pre = min;
        }
        return res;
    }

    // 不难发现，max/min 值分别只可能有三种选择，所以上述代码可以稍微优化一下
    int maxProduct2(vector<int>& nums) {
        int i;
        int max_pre = nums[0], min_pre = nums[0], res = nums[0];
        int max, min;
        
        for (i = 1; i < nums.size(); ++i) {
            max = std::max(std::max(nums[i] * min_pre, nums[i]), max_pre * nums[i]);
            min = std::min(std::min(nums[i] * min_pre, nums[i]), max_pre * nums[i]);

            res = std::max(res, max);
            max_pre = max;
            min_pre = min;
        }
        return res;
    }
};