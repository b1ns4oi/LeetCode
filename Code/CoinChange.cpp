// https://leetcode.com/problems/coin-change/
// Memory Limit Exceeded Error
//
// 递推关系：
// 对于每个amount(从1到amount)，如果已经知道某个coins 集合情况下的最优解，现在对集合增加一个coin 面值，求最优解
// 增加的面值带来的影响会是以下情况之一：
// 1， 面值大于amount，则解还应是增加前的最优解（增加了一个元素对结果无影响）
// 2， 面值不大于amount, 则可以尝试采纳该面值，最终解是不采纳该面值的子情况与采纳该面值的子情况的min (注意子情况为-1 )
//
int coinChange(vector<int>& coins, int amount) {
	int n = coins.size();
	int i, j, k;

	vector<vector<int> > aux(amount+1, vector<int>(n+1, 0));

	for (i = 1; i <= amount; ++i) {
		// no coins
		aux[i][0] = -1;

		for (j = 1; j <= n; ++j) {
			if ((k = i - coins[j-1]) < 0 || aux[k][j] == -1)
				aux[i][j] = aux[i][j-1];
			else if (aux[i][j-1] == -1)
				aux[i][j] = 1 + aux[k][j];
			else
				aux[i][j] = std::min(aux[i][j-1], 1 + aux[k][j]);
		}
	}
	return aux[amount][n];
}


// Recursive solution (i.e. Top down DP without caching result)
//  Time Limit Exceeded
int coinChange_recur(vector<int>& coins, int amount) {
	if (amount == 0)
		return 0;

	int i, j, res = amount+1;

	for (i = 0; i < coins.size(); ++i) {
		if (coins[i] <= amount) {
			j = coinChange_recur(coins, amount-coins[i]);
			if (j == -1)
				continue;
			if (j+1 < res)
				res = j+1;
		}
	}
	return res > amount ? -1 : res;
}

int coinChange_recur_with_cache_helper(vector<int>& coins, int amount, vector<int>& cache) {
	if (cache[amount] < amount+1)
		return cache[amount];
	if (amount == 0)
		return 0;

	int i, j, res = amount+1;

	for (i = 0; i < coins.size(); ++i) {
		if (coins[i] <= amount) {
			j = coinChange_recur_with_cache_helper(coins, amount-coins[i], cache);
			if (j == -1)
				continue;
			if (j+1 < res)
				res = j+1;
		}
	}
	cache[amount] = res > amount ? -1 : res;
	return cache[amount];
}

// Recursive solution with cache
// Accepted
int coinChange_recur_with_cache(vector<int>& coins, int amount) {
	vector<int> cache(amount+1, amount+1);
	return coinChange_recur_with_cache_helper(coins, amount, cache);
}


// Botton-up DP solution
//
// Reference: https://discuss.leetcode.com/topic/32475/c-o-n-amount-time-o-amount-space-dp-solution
//
// 这个解法的递推关系比较巧妙：
// 假设已经知道aux[0], aux[1], ... , aux[amount-1] 的最优解， 要求aux[amount]，就是遍历coins 集合中所有可能
// 被aux[amount] 取到的coin (也就是面值不大于amount 的coin)，再考虑对应子情况aux[amount-coin] 的值
//
// 最终我们要的结果是遍历过程中发现的最小值
//
int coinChange_DP(vector<int>& coins, int amount) {
	int n = coins.size();
	int i, j;

	vector<int> aux(amount+1, amount+1);
	aux[0] = 0;

	for (i = 1; i <= amount; ++i) {
		for (j = 0; j < n; ++j) {
			if (coins[j] <= i)
				aux[i] = std::min(aux[i], 1+aux[i-coins[j]]);
		}
	}
	return aux[amount] > amount ? -1 : aux[amount];
}